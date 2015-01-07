#include "MonsterPos.h"
MonsterPos::MonsterPos()
{
	m_pos = Point(0, 0);
	m_isDebug = false;
}
MonsterPos::~MonsterPos()
{}
MonsterPos* MonsterPos::create(Point pos)
{
	MonsterPos* tpos = new MonsterPos();
	if(tpos && tpos->init(pos))
	{
		tpos->autorelease();
	}
	else
	{
		CC_SAFE_DELETE(tpos);
	}
	return tpos;
}
MonsterPos* MonsterPos::create(Point pos, bool isDebug)
{
	MonsterPos* tpos = new MonsterPos();
	if(tpos && tpos->init(pos, isDebug))
	{
		tpos->autorelease();
	}
	else
	{
		CC_SAFE_DELETE(tpos);
	}
	return tpos;
}
bool MonsterPos::init(Point pos)
{
	bool ret = false;
	do{
		setPos(pos);
		ret = true;
	}while(0);
	return ret;
}
bool MonsterPos::init(Point pos, bool isDebug)
{
	bool ret = false;
	do{
		CC_BREAK_IF(!init(pos));
		m_isDebug = isDebug;
		ret = true;
	}while(0);
	return ret;
}
void MonsterPos::draw(Renderer* renderer, const kmMat4 & transform, bool transformupdated)
{
	if(m_isDebug)
	{
		_customCommand.init(_globalZOrder);
		_customCommand.func = CC_CALLBACK_0(MonsterPos::onDraw, this, transform, transformupdated);
		renderer->addCommand(&_customCommand);
	}
}
void MonsterPos::onDraw(const kmMat4 &transform, bool transformupdated)
{
	kmGLPushMatrix();
	kmGLLoadMatrix(&transform);
	glLineWidth(4);
	DrawPrimitives::drawCircle(m_pos, MONSTER_RADIUS, 360, 20, false);
	glLineWidth(1);
	kmGLPopMatrix();
}
bool MonsterPos::isClickMe(Point pos)
{
	Point srcPos = Point(m_pos.x - MONSTER_RADIUS, m_pos.y + MONSTER_RADIUS);
	Point destPos = Point(m_pos.x + MONSTER_RADIUS, m_pos.y - MONSTER_RADIUS);

	if(pos.x >= srcPos.x && pos.x <= destPos.x && pos.y <= srcPos.y && pos.y >= destPos.y) {
		return true;
	}

	return false;
}














