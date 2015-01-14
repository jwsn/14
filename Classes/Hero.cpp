#include "Hero.h"
#include "CsvUtil.h"
#include "EnumHeroPropConfType.h"
#include "GlobalPath.h"
#include "Monster.h"
Hero::Hero()
{
	m_atkMonster = NULL;
	m_isAtkCoolDown = false;
}
Hero::~Hero()
{}
Hero* Hero::create(Sprite* sprite)
{
	Hero* hero = new Hero();
	if(hero && hero->init(sprite))
	{
		hero->autorelease();
	}
	else
	{
		CC_SAFE_DELETE(hero);
	}
	return hero;
}
bool Hero::init(Sprite* sprite)
{
	bool ret = false;
	do{
		CC_BREAK_IF(!sprite);
		bindSprite(sprite);
		ret = true;
	}while(0);
	return ret;
}
Hero* Hero::createFromCsvFileByID(int iHeroID)
{
	Hero* hero = new Hero();
	if(hero && hero->initFromCsvFileByID(iHeroID))
	{
		hero->autorelease();
	}
	else
	{
		CC_SAFE_DELETE(hero);
	}
	return hero;
}
/*
iLine:代表要获取的值在CSV文件中的行；
enHeroPropConf_AtkSpeed:代表在CSV文件中的路径，在GlobalPath.h里定义
PATH_CSV_HERO_CONF:代表Csv文件的路径，在GlobalPath.h里定义。
*/
bool Hero::initFromCsvFileByID(int iHeroID) {
    bool bRet = false;

    do {
        CsvUtil* csvUtil = CsvUtil::getInstance();

        std::string sHeroID = StringUtils::toString(iHeroID);

        /* 寻找ID所在的行 */
        int iLine = csvUtil->findValueIntWithLine(
            sHeroID.c_str(), enHeroPropConf_ID, PATH_CSV_HERO_CONF);

        CC_BREAK_IF(iLine < 0);

        setID(iHeroID);
        setiModelID(csvUtil->getInt(iLine, enHeroPropConf_ModelID, PATH_CSV_HERO_CONF));
        setiBaseAtk(csvUtil->getInt(iLine, enHeroPropConf_BaseAtk, PATH_CSV_HERO_CONF));
        setiCurAtk(getiBaseAtk());
        setiAtkSpeed(csvUtil->getInt(iLine, enHeroPropConf_AtkSpeed, PATH_CSV_HERO_CONF));
        setiAtkRange(csvUtil->getInt(iLine, enHeroPropConf_AtkRange, PATH_CSV_HERO_CONF));
        setiUpgradeCostBase(csvUtil->getInt(iLine, enHeroPropConf_UpgradeCostBase, PATH_CSV_HERO_CONF));
        setfUpgradeAtkBase(csvUtil->getFloat(iLine, enHeroPropConf_UpgradeAtkBase, PATH_CSV_HERO_CONF));

        Sprite* sprite = Sprite::create(StringUtils::format("sprite/hero/hero_%d.png", iHeroID).c_str());
        CC_BREAK_IF(!sprite);

        CC_BREAK_IF(!init(sprite));

        bRet = true;
    } while (0);

    return bRet;
}
void Hero::checkAtkMonster(float ft, Vector<Monster*> monsterList)
{
	if(m_atkMonster != NULL)
	{
		if(m_atkMonster->isDead())
		{
			monsterList.eraseObject(m_atkMonster);
			m_atkMonster = NULL;
			return;
		}
		if(m_isAtkCoolDown == false)
		{
			atk();
		}
		checkAimIsOutOfRange(monsterList);
	}
	else
	{
		chooseAim(monsterList);
	}
}
void Hero::atk()
{
	log("atk !!!!");
	m_isAtkCoolDown = true;
	this->scheduleOnce(schedule_selector(Hero::atkCollDownEnd),getiAtkSpeed()/1000.0f);
}
void Hero::chooseAim(Vector<Monster*> monsterList)
{
	for(auto monster:monsterList)
	{
		if(monster->isVisible() && isInAtkRange(monster->getPosition()))
		{
			chooseAtkMonster(monster);
			log("in atk range");
			break;
		}
	}
}
bool Hero::isInAtkRange(Point pos)
{
	int iDoubleAtkRange = getiAtkRange();//攻击范围
	Point heroPos = getPosition();
	float length = pos.getDistanceSq(heroPos);//两点之间的距离
	if(length <= iDoubleAtkRange*iDoubleAtkRange)
	{
		return true;
	}
	return false;
}
void Hero::chooseAtkMonster(Monster* monster)
{
	m_atkMonster = monster;
}
void Hero::atkCollDownEnd(float dt)
{
	m_isAtkCoolDown = false;
}
void Hero::checkAimIsOutOfRange(Vector<Monster*> monsterList)
{
	if(m_atkMonster != NULL)
	{
		if(isInAtkRange(m_atkMonster->getPosition()) == false)
		{
			missAtkMonster();
		}
	}
}
void Hero::missAtkMonster()
{
	log("out of range");
	m_atkMonster = NULL;
}



