#include "PosBase.h"
PosBase::PosBase()
{
	m_pos = Point(0, 0);
	m_isDebug = false;
}
PosBase::~PosBase()
{}
PosBase* PosBase::create(Point pos)
{
	PosBase* tPos = new PosBase();
	if(tPos && tPos->init(pos))
	{
		tPos->autorelease();
	}
	else
	{
		CC_SAFE_DELETE(tPos);
	}
	return tPos;
}
PosBase* PosBase::create(Point pos, bool is_debug)
{
	PosBase* tPos = new PosBase();
	if(tPos && tPos->init(pos, is_debug))
	{
		tPos->autorelease();
	}
	else
	{
		CC_SAFE_DELETE(tPos);
	}
	return tPos;
}
bool PosBase::init(Point pos)
{
	bool ret = false;
	do{
		setPos(pos);
		ret = true;
	}while(0);
	return ret;
}
bool PosBase::init(Point pos, bool is_debug)
{
	bool ret = false;
	do{
		CC_BREAK_IF(!init(pos));
		m_isDebug = is_debug;
		ret = true;
	}while(0);
	return ret;
}
bool PosBase::isClickMe(Point pos)
{
	return false;
}
void PosBase::setDebug(bool isDebug)
{
	this->m_isDebug = isDebug;
}






