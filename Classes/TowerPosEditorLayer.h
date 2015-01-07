#ifndef _TOWERPOSEDITORLAYER_H_
#define _TOWERPOSEDITORLAYER_H_
#include"cocos2d.h"
#include"TowerPos.h"
#include "EnumPosType.h"
USING_NS_CC;
#define MAX_LEVEL 5
class TowerPosEditorLayer:public Layer
{
public:
	TowerPosEditorLayer();
	~TowerPosEditorLayer();
	CREATE_FUNC(TowerPosEditorLayer);
	virtual bool init();
	void outputPosPlistFile();
private:
	Vector<PosBase*> m_towerPosList;
	Vector<PosBase*> m_monsterPosList;

	int m_iCurLevel;
	void editTowerPos(Point pos);//编辑塔坐标
	PosBase* findExistTowerPos(Point pos);//根据坐标找到已经存在的塔坐标
	void createTowerPos(Point pos);//给定坐标生成塔坐标
	void deleteTowerPos(PosBase* existPos);//给定塔坐标，删除塔坐标对象
	void deleteAllPos();//删除所有坐标对象
	void outputPosToPlistFile();
	void loadConfigFile();
	void outputPosToPlistFile(Vector<PosBase*> posList, const char* sFilePath);
	//MonsterPos
	EnumPosType m_enMode;
	void editMonsterPos(Point pos);
	PosBase* findExistMonsterPos(Point pos);//根据坐标找到已经存在的塔坐标
	void createMonsterPos(Point pos);//给定坐标生成塔坐标
	void deleteMonsterPos(PosBase* existPos);//给定塔坐标，删除塔坐标对象
};
#endif