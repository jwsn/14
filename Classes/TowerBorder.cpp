#include "TowerBorder.h"
TowerBorder::TowerBorder()
{
	m_iLevel = 1;
	m_hero = NULL;
}
TowerBorder::~TowerBorder()
{}
bool TowerBorder::init()
{
	return true;
}
void TowerBorder::upgrade()
{
	if(getSprite() != NULL)
	{
		getSprite()->stopAllActions();
	}
	std::string sFilePath = StringUtils::format("sprite/hero/border_%d.png", m_iLevel);
	Sprite* sprite = Sprite::create(sFilePath.c_str());
	bindSprite(sprite);
	m_iLevel++;
	if(m_iLevel == 2)
	{
		auto rotateBy = RotateBy::create(25.0f, 360, 360);
		auto repeat = RepeatForever::create(rotateBy);
		sFilePath = StringUtils::format("sprite/hero/magic_border_%d.png", m_iLevel);
		sprite = Sprite::create(sFilePath.c_str());
		sprite->setOpacity(80);
		sprite->runAction(repeat);
		this->addChild(sprite, 10);
	}
}
bool TowerBorder::isClickMe(Point pos)
{
	Size size = getSprite()->getContentSize();
	Point borderPos = getPosition();

	Point srcPos = Point(borderPos.x - size.width/2, borderPos.y + size.height/2);
	Point destPos = Point(borderPos.x + size.width /2, borderPos.y - size.height / 2);
	/*判断是否在一个矩形内部*/
	if(pos.x >= srcPos.x && pos.x <= destPos.x && pos.y <= srcPos.y && pos.y >= destPos.y)
	{
		return true;
	}
	return false;
}
void TowerBorder::bindHero(Hero* hero)
{
	m_hero = hero;
}
Hero* TowerBorder::getHero()
{
	return m_hero;
}
void TowerBorder::deleteHero()
{
	if(m_hero != NULL)
	{
		m_hero->removeFromParent();
	}
}







