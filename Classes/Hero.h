#ifndef _HERO_H_
#define _HERO_H_
#include "Entity.h"
class Hero:public Entity
{
public:
	Hero();
	~Hero();
	static Hero* create(Sprite* sprite);
	bool init(Sprite* sprite);
	//����Ӣ��ID,�������ļ��ж�ȡӢ������
	static Hero* createFromCsvFileByID(int iHeroID);
	bool initFromCsvFileByID(int iHeroID);

	CC_SYNTHESIZE(int, m_iBaseAtk, iBaseAtk);//������������
	CC_SYNTHESIZE(int, m_iCurAtk, iCurAtk);//��ǰ��������
	CC_SYNTHESIZE(int, m_iAtkSpeed, iAtkSpeed);//�������
	CC_SYNTHESIZE(int, m_iAtkRange, iAtkRange);//������Χ
	CC_SYNTHESIZE(int, m_iUpgradeCostBase, iUpgradeCostBase);//�������Ļ���ֵ
	CC_SYNTHESIZE(float, m_fUpgradeAtkBase, fUpgradeAtkBase);//���������ӳ�ϵ��
	void upgrade();
};
#endif