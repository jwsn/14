#include "MonsterManager.h"
#include "PosLoadUtil.h"
#include "Monster.h"
#include "MonsterPos.h"
MonsterManager::MonsterManager()
{}
MonsterManager::~MonsterManager()
{}
MonsterManager* MonsterManager::createWithLevel(int iCurLevel)
{
	MonsterManager* monsterMgr = new MonsterManager();
	if(monsterMgr && monsterMgr->initWithLevel(iCurLevel))
	{
		monsterMgr->autorelease();
	}
	else
	{
		CC_SAFE_DELETE(monsterMgr);
	}
	return monsterMgr;
}
bool MonsterManager::initWithLevel(int iCurLevel)
{
	createMonsters(iCurLevel);
	return true;
}
int MonsterManager::getNotShowMonsterCount()
{
	return m_notShowMonsterList.size();
}
Vector<Monster*> MonsterManager::getMonsterList()
{
	return m_monsterList;
}
MonsterPos* MonsterManager::getMonsterStartPos()
{
	return (MonsterPos*)m_monsterList.at(0);
}
MonsterPos* MonsterManager::getMonsterEndPos()
{
	return (MonsterPos*)m_monsterList.at(m_monsterList.size() - 1);
}
void MonsterManager::createMonsters(int iCurLevel)
{
	//加载坐标对象
	std::string sMonsterPosPath = StringUtils::format("tollgate/monsterPos_level_%d.plist",iCurLevel);
	auto posList = PosLoadUtil::getInstance()->loadPosWithFile(sMonsterPosPath.c_str(),enMonsterPos, this, 10, false);
	m_monsterPosList.pushBack(posList);
	//读取配置文件
	std::string sMonsterConfPath = StringUtils::format("tollgate/monster_level_%d.plist",iCurLevel);
	ValueMap fileDataMap = FileUtils::getInstance()->getValueMapFromFile(sMonsterPosPath.c_str());

	int size = fileDataMap.size();
	for(int i = 0; i <= size; i++)
	{
		Value value = fileDataMap.at(StringUtils::toString(i));
		ValueMap data = value.asValueMap();
	
		/*从怪物出场的配置文件读取怪物ID和出场时间，保存所有怪物未出场列表*/
		int id = data["id"].asInt();
		float fShowTime = data["showTime"].asFloat();
		auto monster = Monster::createFromCsvFileByID(id);
		monster->setfShowTime(fShowTime);
		monster->setVisible(false);

		//设置怪物精灵
		std::string spPath = StringUtils::format("sprite/monster/monster_%d.png",monster->getiModelID());
		monster->bindSprite(Sprite::create(spPath.c_str()));

		m_monsterList.pushBack(monster);
		m_notShowMonsterList.pushBack(monster);
		this->addChild(monster);
		//检查怪物是否出场
		this->schedule(schedule_selector(MonsterManager::showMonster));
	}
}
void MonsterManager::showMonster(float dt)
{
	int iNotShowMonsterCount = m_notShowMonsterList.size();
	if(iNotShowMonsterCount > 0)
	{
		m_fShowTimeCount += dt;
	}
	auto monsterFirstPos = getMonsterStartPos();

	Vector<Monster*> monsterWantToDelete;
	for(auto monster:m_notShowMonsterList)
	{
		//时间达到怪物的出场时间，让怪物出场
		if(m_fShowTimeCount >= monster->getfShowTime())
		{
			//添加怪物到删除列表，出场后的怪物要出未出场列表中删除
			monsterWantToDelete.pushBack(monster);
			monster->setPosition(monster->getPosition());
			monster->setVisible(true);
			//怪物按照指定的坐标行走
			//monster->moveByPosList(m_monsterPosList);
		}
	}
	//删除已经出场的怪物
	for(auto monster:monsterWantToDelete)
	{
		m_notShowMonsterList.eraseObject(monster);
	}
}







