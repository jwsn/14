#ifndef _MONSTER_H_
#define _MONSTER_H_

#include "Entity.h"

#define MONSTER_SPEED_INIT 1
class ControllerSimpleMove;
class PosBase;
class Monster:public Entity
{
public:
	Monster();
	~Monster();
	CREATE_FUNC(Monster);
	virtual bool init();

	static Monster* createFromCsvFileByID(int iMonsterID);
	bool initFrameCsvFileByID(int iMonsterID);
public:
	void moveByPosList(Vector<PosBase*> posList);
private:
	ControllerSimpleMove* m_moveController;
	CC_SYNTHESIZE(int, m_iLevel, iLevel);
	CC_SYNTHESIZE(float, m_fShowTime, fShowTime);
};
#endif