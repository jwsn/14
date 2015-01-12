#ifndef _HEROMANAGER_H_
#define _HEROMANAGER_H_
#include "cocos2d.h"
#include "TowerPos.h"
#include "TowerBorder.h"
#define TOWER_POS_LAYER_LVL 5 //塔坐标的层次
#define TOWER_BORDER_LAYER_LVL 8 //炮台的层次
#define TOWER_LAYER_LVL 10 //塔的层次
USING_NS_CC;
/*
管理炮台和英雄
(1)根据炮台坐标配置文件创建所有炮台对象
(2)单击炮台后创建英雄，前提是被单击的炮台是空炮台
*/
class HeroManager:public Node
{
public:
	HeroManager();
	~HeroManager();
	static HeroManager* createWithLevel(int iCurLevel);
	bool initWithLevel(int iCurLevel);
private:
	Vector<PosBase*> m_towerPosList;//存放所有塔的坐标对象
	Vector<TowerBorder*> m_towerBorderList;//存放所有炮台坐标
	void createTowerBorder(int iCurLevel);//创建炮台
	void createTowerPos(Point pos);//给定坐标，生成塔坐标对象
	TowerBorder* findClickTowerBorder(Point pos);
};
#endif