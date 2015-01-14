#include "Monster.h"
#include "CsvUtil.h"
#include "GlobalPath.h"
#include "PosBase.h"
#include "ControllerSimpleMove.h"
#include "EnumMonsterPropConfType.h"
Monster::Monster()
{
	m_moveController = NULL;
	m_iSpeed = MONSTER_SPEED_INIT;
}
Monster::~Monster()
{
}
bool Monster::init()
{
	m_moveController = ControllerSimpleMove::create(this);
	this->addChild(m_moveController);
	return true;
}
Monster* Monster::createFromCsvFileByID(int monsterID)
{
	Monster* monster = new Monster();
	if(monster && monster->initFrameCsvFileByID(monsterID))
	{
		monster->autorelease();
	}
	else
	{
		CC_SAFE_DELETE(monster);
	}
	return monster;
}
bool Monster::initFrameCsvFileByID(int iMonsterID) {
    bool bRet = false;

    do {
        CsvUtil* csvUtil = CsvUtil::getInstance();

        std::string sMonsterID = StringUtils::format("%d", iMonsterID);

        /* 寻找ID所在的行 */
        int iLine = csvUtil->findValueIntWithLine(sMonsterID.c_str(),
            enMonsterPropConf_ID, PATH_CSV_MONSTER_CONF);

        CC_BREAK_IF(iLine < 0);

        setID(iMonsterID);
        setiLevel(csvUtil->getInt(iLine, enMonsterPropConf_Level, PATH_CSV_MONSTER_CONF));
        setiModelID(csvUtil->getInt(iLine, enMonsterPropConf_ModelID, PATH_CSV_MONSTER_CONF));
        setiDefense(csvUtil->getInt(iLine, enMonsterPropConf_Defense, PATH_CSV_MONSTER_CONF));
        setiHP(csvUtil->getInt(iLine, enMonsterPropConf_Hp, PATH_CSV_MONSTER_CONF));
        setiSpeed(csvUtil->getInt(iLine, enMonsterPropConf_Speed, PATH_CSV_MONSTER_CONF));

        CC_BREAK_IF(!init());

        bRet = true;
    } while (0);

    return bRet;
}

void Monster::moveByPosList(Vector<PosBase*> posList) {
    if (posList.size() < 1) {
        return;
    }
    m_moveController->moveByPosList(posList, 2, getiSpeed());
}
	//Monster
	//Monster
	//Monster