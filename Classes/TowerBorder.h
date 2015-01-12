#ifndef _TOWERBORDER_H_
#define _TOWERBORDER_H_
#include "cocos2d.h"
#include "Entity.h"
#include "Hero.h"
USING_NS_CC;;
class TowerBorder:public Entity
{
public:
	TowerBorder();
	~TowerBorder();
	CREATE_FUNC(TowerBorder);
	virtual bool init();
	void upgrade(); //升级
	bool isClickMe(Point pos);
	void bindHero(Hero* hero);//绑定英雄对象
	Hero* getHero();
	void deleteHero();
private:
	Hero* m_hero;
};
#endif