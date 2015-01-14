#ifndef _HERO_H_
#define _HERO_H_
#include "Entity.h"
#include "Monster.h"
class Hero:public Entity
{
public:
	Hero();
	~Hero();
	static Hero* create(Sprite* sprite);
	bool init(Sprite* sprite);
	//给定英雄ID,从配置文件中读取英雄数据
	static Hero* createFromCsvFileByID(int iHeroID);
	bool initFromCsvFileByID(int iHeroID);

	CC_SYNTHESIZE(int, m_iBaseAtk, iBaseAtk);//基础攻击能力
	CC_SYNTHESIZE(int, m_iCurAtk, iCurAtk);//当前攻击能力
	CC_SYNTHESIZE(int, m_iAtkSpeed, iAtkSpeed);//攻击间隔
	CC_SYNTHESIZE(int, m_iAtkRange, iAtkRange);//攻击范围
	CC_SYNTHESIZE(int, m_iUpgradeCostBase, iUpgradeCostBase);//升级消耗基础值
	CC_SYNTHESIZE(float, m_fUpgradeAtkBase, fUpgradeAtkBase);//升级攻击加成系数
	void upgrade();
	void checkAtkMonster(float ft, Vector<Monster*> monsterList);

	bool m_isAtkCoolDown;//攻击是否冷却
	Monster* m_atkMonster;//当前锁定的怪物
	bool isInAtkRange(Point pos);
	void chooseAtkMonster(Monster* monster);
	void chooseAim(Vector<Monster*> monsterList);//查找并锁定攻击目标
	void atkCollDownEnd(float dt);
	void atk();
	void checkAimIsOutOfRange(Vector<Monster*> monsterList);
	void missAtkMonster();
};
#endif