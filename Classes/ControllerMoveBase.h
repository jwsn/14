#ifndef _CONTROLLERMOVEBASE_H_
#define _CONTROLLERMOVEBASE_H_
#include "cocos2d.h"
#include "ControllerBase.h"
#include "Entity.h"
USING_NS_CC;
#define CHECK_MOVE_SPEED_LVL1 0.1f
#define CHECK_MOVE_SPEED_LVL2 0.04f
#define CHECK_MOVE_SPEED_LVL3 0.03f

#define SPEED 1

class ControllerMoveBase:public ControllerBase
{
public:
	ControllerMoveBase();
	~ControllerMoveBase();
	CC_SYNTHESIZE(int, m_speed, iSpeed);//移动速度
protected:
	Entity* m_entity;
	bool isMoving;
	bool isXLeft;//x方向是否向左移动
	bool isYUp;//标记y方向是否向上移动
	int icheckMoveSpeed;//检查移动的间隔时间，时间越短，移动越快
	Point getNextPos(Point curPos, Point destPos);//给定当前坐标和目标坐标，计算出下一次要设置的坐标
};
#endif