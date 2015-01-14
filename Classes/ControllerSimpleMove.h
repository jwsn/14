#ifndef _CONTROLLERSIMPLEMOVE_H_
#define _CONTROLLERSIMPLEMOVE_H_
#include "cocos2d.h"
#include "Entity.h"
#include "ControllerMoveBase.h"
#include "PosBase.h"
USING_NS_CC;
class ControllerSimpleMove:public ControllerMoveBase
{
public:
	ControllerSimpleMove();
	~ControllerSimpleMove();
	static ControllerSimpleMove* create(Entity* entity);
	bool init(Entity* entity);
	void checkMoveUpdate(float dt);
	void moveByPosList(Vector<PosBase*> posList);//按照给定的坐标点移动
	void moveByPosList(Vector<PosBase*> posList, int iSpeed);//按照给定的坐标点和移动速度
	void moveByPosList(Vector<PosBase*> posList, int iSpeed, int iSpanTime);//按照给定的坐标点。速度。移动时间间隔
	void moveByPos(PosBase* pos);
private:
	void moveOneStep();//移动一步
	void nextMovePos();//设置下一个移动目的点
private:
	Vector<PosBase*> m_movePosList;//移动目的列表
	PosBase* m_curDestPos;//当前移动目的地
	float m_MoveSpan;//移动时间间隔
	float m_fMoveTimeCount;//计时器
};
#endif