#include "ControllerSimpleMove.h"
ControllerSimpleMove::ControllerSimpleMove()
{
	m_fMoveTimeCount = 0;
	m_MoveSpan = 0;
}
ControllerSimpleMove::~ControllerSimpleMove()
{
	CC_SAFE_DELETE(m_curDestPos);
}
ControllerSimpleMove* ControllerSimpleMove::create(Entity* entity)
{
	ControllerSimpleMove* csm = new ControllerSimpleMove();
	if(csm && csm->init(entity))
	{
		csm->autorelease();
	}
	else
	{
		CC_SAFE_DELETE(csm);
	}
	return csm;
}
bool ControllerSimpleMove::init(Entity* entity)
{
	this->m_entity = entity;
	this->schedule(schedule_selector(ControllerSimpleMove::checkMoveUpdate));
	return true;
}
void ControllerSimpleMove::checkMoveUpdate(float dt)
{
	if(isMoving)
	{
		m_fMoveTimeCount += dt * 1000;
		if(m_fMoveTimeCount >= m_MoveSpan)
		{
			m_fMoveTimeCount = 0;
			moveOneStep();
		}
	}
}
void ControllerSimpleMove::moveOneStep()
{
	Sprite* sprite = m_entity->getSprite();
	if(sprite != NULL)
	{
		Point entityPos = m_entity->getPosition();
		Point curDestPos = m_curDestPos->getPosition();
		//取得下一个移动坐标点
		entityPos = getNextPos(entityPos, curDestPos);
		//移动实体
		m_entity->setPosition(entityPos);
		//到达目的地，开始下一个目的地
		if(entityPos.x == curDestPos.x && entityPos.y == curDestPos.y)
		{
			if(m_movePosList.size() > 0)
			{
				nextMovePos();
			}
		}
	}
}
void ControllerSimpleMove::nextMovePos()
{
	if(m_movePosList.size() < 1)
	{
		return;
	}
	m_curDestPos = m_movePosList.at(0);
	m_movePosList.erase(0);
}
void ControllerSimpleMove::moveByPosList(Vector<PosBase*> posList)
{
	if(posList.size() < 1)
	{
		return;
	}
	this->m_movePosList.clear();
	this->m_movePosList.pushBack(posList);
	nextMovePos();
	this->isMoving = true;
}
void ControllerSimpleMove::moveByPosList(Vector<PosBase*> posList, int speed)
{
	this->m_speed = speed;
	moveByPosList(posList);
}
void ControllerSimpleMove::moveByPosList(Vector<PosBase*> posList, int speed, int span)
{
	m_MoveSpan = span;
	moveByPosList(posList, span);
}
void ControllerSimpleMove::moveByPos(PosBase* pos)
{
	if(isMoving == false && pos != NULL)
	{
		Vector<PosBase*> posList;
		posList.pushBack(pos);
		moveByPosList(posList);
	}
}