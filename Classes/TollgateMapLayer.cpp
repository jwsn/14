#include "TollgateMapLayer.h"

#define HOME_LAYER_LVL 3
#define HERO_LAYER_LVL 10
#define MONSTER_LAYER_LVL 15
#define BULLET_LAYER_LVL 20

TollgateMapLayer::TollgateMapLayer()
{
	m_iCurLevel = 1;
}
TollgateMapLayer::~TollgateMapLayer()
{}
bool TollgateMapLayer::init()
{
	if(!Layer::init())
		return false;

	bool ret = false;
	do{
		loadConfig();
		m_heroMgr = HeroManager::createWithLevel(m_iCurLevel);
		this->addChild(m_heroMgr, HERO_LAYER_LVL);
		m_monsterMgr = MonsterManager::createWithLevel(m_iCurLevel);
		this->addChild(m_monsterMgr, MONSTER_LAYER_LVL);
		this->schedule(schedule_selector(TollgateMapLayer::logic));
		ret = true;
	}while(0);
	return true;
}
void TollgateMapLayer::loadConfig()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();

	//Ìí¼Ó±³¾°ÒôÀÖ
	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic(StringUtils::format("music/tollgate_%d.map3", m_iCurLevel).c_str(), true);
	std::string sBG = StringUtils::format("tollgate/level_%d.jpg", m_iCurLevel);
	Sprite* map = Sprite::create(sBG.c_str());
	map->setPosition(Point(visibleSize.width /2, visibleSize.height / 2));
	this->addChild(map, 1);
}
bool TollgateMapLayer::logic(float dt)
{
	m_heroMgr->logic(dt, m_monsterMgr->getMonsterList());
}