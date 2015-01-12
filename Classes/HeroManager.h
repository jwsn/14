#ifndef _HEROMANAGER_H_
#define _HEROMANAGER_H_
#include "cocos2d.h"
#include "TowerPos.h"
#include "TowerBorder.h"
#define TOWER_POS_LAYER_LVL 5 //������Ĳ��
#define TOWER_BORDER_LAYER_LVL 8 //��̨�Ĳ��
#define TOWER_LAYER_LVL 10 //���Ĳ��
USING_NS_CC;
/*
������̨��Ӣ��
(1)������̨���������ļ�����������̨����
(2)������̨�󴴽�Ӣ�ۣ�ǰ���Ǳ���������̨�ǿ���̨
*/
class HeroManager:public Node
{
public:
	HeroManager();
	~HeroManager();
	static HeroManager* createWithLevel(int iCurLevel);
	bool initWithLevel(int iCurLevel);
private:
	Vector<PosBase*> m_towerPosList;//������������������
	Vector<TowerBorder*> m_towerBorderList;//���������̨����
	void createTowerBorder(int iCurLevel);//������̨
	void createTowerPos(Point pos);//�������꣬�������������
	TowerBorder* findClickTowerBorder(Point pos);
};
#endif