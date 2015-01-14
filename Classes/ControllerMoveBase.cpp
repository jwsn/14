#include "ControllerMoveBase.h"
ControllerMoveBase::ControllerMoveBase()
{
	isMoving = false;
	isXLeft = false;
	isYUp = false;
	m_speed = SPEED;
	icheckMoveSpeed = CHECK_MOVE_SPEED_LVL2;
	m_entity = NULL;
}
ControllerMoveBase::~ControllerMoveBase()
{}
//给定当前坐标和目标坐标，计算出下一次要设置的坐标
Point ControllerMoveBase::getNextPos(Point curPos, Point destPos)
{
	if(curPos.x > destPos.x)
	{
		isXLeft = true;
	}
	else
	{
		isXLeft = false;
	}
	if(curPos.y < destPos.y)
	{
		isYUp = true;
	}
	else
	{
		isYUp = false;
	}
	if(curPos.x < destPos.x && isXLeft == false)
	{
		curPos.x += m_speed;
		if(curPos.x > destPos.x)
		{
			curPos.x = destPos.x;
		}
	}
	else if(curPos.x > destPos.x && isXLeft == true)
	{
		curPos.x -= m_speed;
		if(curPos.x < destPos.x)
		{
			curPos.x = destPos.x;
		}
	}
	if(curPos.y < destPos.y && isYUp == true)
	{
		curPos.y += m_speed;
		if(curPos.y > destPos.y)
		{
			curPos.y = destPos.y;
		}
	}
	else if(curPos.y > destPos.y && isYUp == false)
	{
		curPos.x-=m_speed;
		if(curPos.y < destPos.y)
		{
			curPos.y = destPos.y;
		}
	}
	return curPos;
}