#include"TowerPos.h"
TowerPos::TowerPos()
{
	m_pos = Point(0, 0);
	m_isDebug = false;
}
TowerPos::~TowerPos()
{}
TowerPos* TowerPos::create(Point pos)
{
	TowerPos* tPos = new TowerPos();
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
TowerPos* TowerPos::create(Point pos, bool isDebug)
{
	TowerPos* tPos = new TowerPos();
	if(tPos && tPos->init(pos, isDebug))
	{
		tPos->autorelease();
	}
	else
	{
		CC_SAFE_DELETE(tPos);
	}
	return tPos;
}
bool TowerPos::init(Point pos)
{
	bool ret = false;
	do{
		CC_BREAK_IF(!PosBase::init(pos));
		ret = true;	
	}while(0);
	return ret;
}
bool TowerPos::init(Point pos, bool isDebug)
{
	bool ret = false;
	do{
		CC_BREAK_IF(!PosBase::init(pos, isDebug));
		ret = true;	
	}while(0);
	return ret;
}
bool TowerPos::isClickMe(Point pos)
{
	Point srcPos = Point(m_pos.x - RADIUS, m_pos.y + RADIUS);
	Point destPos = Point(m_pos.x + RADIUS, m_pos.y - RADIUS);
	if(pos.x >= srcPos.x && pos.x <=destPos.x && pos.y <= srcPos.y && pos.y >= destPos.y)
		return true;
	return false;
}
void TowerPos::draw(Renderer* renderer, const kmMat4 &transform, unsigned int transformUpdated)
{
	if(m_isDebug)
	{
		_customCommand.init(_globalZOrder);
		_customCommand.func = CC_CALLBACK_0(TowerPos::onDraw, this, transform, transformUpdated);
		renderer->addCommand(&_customCommand);
	}
}
void TowerPos::onDraw(const kmMat4 &transform, bool transformUpdated)
{
	kmGLPushMatrix();
	kmGLLoadMatrix(&transform);
	glLineWidth(5.0f);
	Point srcPos = Point(m_pos.x - RADIUS, m_pos.y + RADIUS);
	Point destPos = Point(m_pos.x + RADIUS, m_pos.y - RADIUS);
	DrawPrimitives::drawRect(srcPos, destPos);
	glLineWidth(1);
	kmGLPopMatrix();
}
