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
	void editTowerPos(Point pos);//�༭������
	PosBase* findExistTowerPos(Point pos);//���������ҵ��Ѿ����ڵ�������
	void createTowerPos(Point pos);//������������������
	void deleteTowerPos(PosBase* existPos);//���������꣬ɾ�����������
	void deleteAllPos();//ɾ�������������
	void outputPosToPlistFile();
	void loadConfigFile();
	void outputPosToPlistFile(Vector<PosBase*> posList, const char* sFilePath);
	//MonsterPos
	EnumPosType m_enMode;
	void editMonsterPos(Point pos);
	PosBase* findExistMonsterPos(Point pos);//���������ҵ��Ѿ����ڵ�������
	void createMonsterPos(Point pos);//������������������
	void deleteMonsterPos(PosBase* existPos);//���������꣬ɾ�����������
};
#endif