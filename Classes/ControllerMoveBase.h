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
	CC_SYNTHESIZE(int, m_speed, iSpeed);//�ƶ��ٶ�
protected:
	Entity* m_entity;
	bool isMoving;
	bool isXLeft;//x�����Ƿ������ƶ�
	bool isYUp;//���y�����Ƿ������ƶ�
	int icheckMoveSpeed;//����ƶ��ļ��ʱ�䣬ʱ��Խ�̣��ƶ�Խ��
	Point getNextPos(Point curPos, Point destPos);//������ǰ�����Ŀ�����꣬�������һ��Ҫ���õ�����
};
#endif