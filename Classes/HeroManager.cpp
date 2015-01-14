#include "HeroManager.h"
#include "PosLoadUtil.h"
HeroManager::HeroManager()
{}
HeroManager::~HeroManager()
{}
HeroManager* HeroManager::createWithLevel(int iCurLevel)
{
	HeroManager* heroMgr = new HeroManager();
	if(heroMgr && heroMgr->initWithLevel(iCurLevel))
	{
		heroMgr->autorelease();
	}
	else
	{
		CC_SAFE_DELETE(heroMgr);
	}
	return heroMgr;
}
bool HeroManager::initWithLevel(int iCurLevel)
{
	//加载塔坐标对象
	std::string sTowerPosPath = StringUtils::format("tollgate/towerPos_level_%d.plist",iCurLevel);
	Vector<PosBase*> posList = PosLoadUtil::getInstance()->loadPosWithFile(sTowerPosPath.c_str(), enTowerPos, this, 10, false);
	m_towerPosList.pushBack(posList);
	//创建炮台
	createTowerBorder(iCurLevel);

	//添加触摸事件
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = [](Touch* touch, Event* event)
	{
		return true;
	};
	listener->onTouchEnded = [&](Touch* touch, Event* event)
	{
		Point pos = Director::getInstance()->convertToGL(touch->getLocationInView());
		TowerBorder* clickBorder = findClickTowerBorder(pos);
		if(clickBorder->getHero() == NULL)
		{
			Hero* hero = Hero::createFromCsvFileByID(1);
			hero->setPosition(clickBorder->getPosition());
			this->addChild(hero, TOWER_LAYER_LVL);
			clickBorder->bindHero(hero);
		}
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
	return true;
}
//创建炮台
void HeroManager::createTowerBorder(int iCurLevel)
{
	for(auto tPos:m_towerPosList)
	{
		TowerBorder* border = TowerBorder::create();
		border->upgrade();
		border->upgrade();
		border->setPosition(tPos->getPos());
		this->addChild(border);
		m_towerBorderList.pushBack(border);
	}
}
void HeroManager::createTowerPos(Point pos)
{
	TowerPos* tPos = TowerPos::create(pos, true);
	this->addChild(tPos, TOWER_POS_LAYER_LVL);
	m_towerPosList.pushBack(tPos);
}
TowerBorder* HeroManager::findClickTowerBorder(Point pos)
{
	for(auto tBorder:m_towerBorderList)
	{
		if(tBorder->isClickMe(pos))
		{
			return tBorder;
		}
	}
	return NULL;
}
void HeroManager::logic(float dt, Vector<Monster*> monsterList)
{
	for(auto tBorder:m_towerBorderList)
	{
		if(tBorder->getHero() != NULL)
		{
			tBorder->getHero()->checkAtkMonster(dt,monsterList);
		}
	}
}
