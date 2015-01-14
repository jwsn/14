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
	//�����������
	std::string sMonsterPosPath = StringUtils::format("tollgate/monsterPos_level_%d.plist",iCurLevel);
	auto posList = PosLoadUtil::getInstance()->loadPosWithFile(sMonsterPosPath.c_str(),enMonsterPos, this, 10, false);
	m_monsterPosList.pushBack(posList);
	//��ȡ�����ļ�
	std::string sMonsterConfPath = StringUtils::format("tollgate/monster_level_%d.plist",iCurLevel);
	ValueMap fileDataMap = FileUtils::getInstance()->getValueMapFromFile(sMonsterPosPath.c_str());

	int size = fileDataMap.size();
	for(int i = 0; i <= size; i++)
	{
		Value value = fileDataMap.at(StringUtils::toString(i));
		ValueMap data = value.asValueMap();
	
		/*�ӹ�������������ļ���ȡ����ID�ͳ���ʱ�䣬�������й���δ�����б�*/
		int id = data["id"].asInt();
		float fShowTime = data["showTime"].asFloat();
		auto monster = Monster::createFromCsvFileByID(id);
		monster->setfShowTime(fShowTime);
		monster->setVisible(false);

		//���ù��ﾫ��
		std::string spPath = StringUtils::format("sprite/monster/monster_%d.png",monster->getiModelID());
		monster->bindSprite(Sprite::create(spPath.c_str()));

		m_monsterList.pushBack(monster);
		m_notShowMonsterList.pushBack(monster);
		this->addChild(monster);
		//�������Ƿ����
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
		//ʱ��ﵽ����ĳ���ʱ�䣬�ù������
		if(m_fShowTimeCount >= monster->getfShowTime())
		{
			//���ӹ��ﵽɾ���б���������Ĺ���Ҫ��δ�����б���ɾ��
			monsterWantToDelete.pushBack(monster);
			monster->setPosition(monster->getPosition());
			monster->setVisible(true);
			//���ﰴ��ָ������������
			//monster->moveByPosList(m_monsterPosList);
		}
	}
	//ɾ���Ѿ������Ĺ���
	for(auto monster:monsterWantToDelete)
	{
		m_notShowMonsterList.eraseObject(monster);
	}
}






