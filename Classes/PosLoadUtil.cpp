#include "PosLoadUtil.h"
#include "TowerPos.h"
#include "EnumPosType.h"
#include "MonsterPos.h"
PosLoadUtil* PosLoadUtil::m_PosLoadUtil = NULL;
PosLoadUtil* PosLoadUtil::getInstace()
{
	if(m_PosLoadUtil == NULL)
	{
		m_PosLoadUtil = new PosLoadUtil();
		if(m_PosLoadUtil && m_PosLoadUtil->init())
		{
			m_PosLoadUtil->autorelease();
		}
		else
		{
			CC_SAFE_DELETE(m_PosLoadUtil);
		}
	}
	return m_PosLoadUtil;
}
bool PosLoadUtil::init()
{
	return true;
}
Vector<PosBase*> PosLoadUtil::loadPosWithFile(const char* sFilePath, EnumPosType enPosType, Node* container, int iLevel, bool isDebug)
{
	Vector<PosBase*> posList;
	ValueMap fileDataMap = FileUtils::getInstance()->getValueMapFromFile(sFilePath);
	int size = fileDataMap.size();
	for(int i = 0; i < size; i++)
	{
		//将plist文件转化为ValueMap结构的过程
		Value value = fileDataMap.at(StringUtils::toString(i));
		ValueMap data = value.asValueMap();
		PosBase* posbase = NULL;
		switch(enPosType)
		{
		case enTowerPos:
			posbase = TowerPos::create(Point(data["x"].asInt(), data["y"].asInt()), isDebug);
			break;
		case enMonsterPos:
			posbase = MonsterPos::create(Point(data["x"].asInt(), data["y"].asInt()), isDebug);
			break;
		default:
			posbase = TowerPos::create(Point(data["x"].asInt(), data["y"].asInt()), isDebug);
			break;
		}
		posList.pushBack(posbase);
		if(container != NULL)
		{
			container->addChild(posbase, iLevel);
		}
	}
	return posList;
}


