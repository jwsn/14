#include "Hero.h"
#include "CsvUtil.h"
#include "EnumHeroPropConfType.h"
#include "GlobalPath.h"
Hero::Hero()
{}
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
iLine:����Ҫ��ȡ��ֵ��CSV�ļ��е��У�
enHeroPropConf_AtkSpeed:������CSV�ļ��е�·������GlobalPath.h�ﶨ��
PATH_CSV_HERO_CONF:����Csv�ļ���·������GlobalPath.h�ﶨ�塣
*/
bool Hero::initFromCsvFileByID(int iHeroID) {
    bool bRet = false;

    do {
        CsvUtil* csvUtil = CsvUtil::getInstance();

        std::string sHeroID = StringUtils::toString(iHeroID);

        /* Ѱ��ID���ڵ��� */
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








