#ifndef _MONSTERPOS_H_
#define _MOSTERPOS_H_
#include "PosBase.h"
//#include "cocos2d.h"
#define MONSTER_RADIUS 10
class Monster;//即使现在没有Monster类，也不会导致编译出错
class MonsterPos:public PosBase
{
public:
	MonsterPos();
	~MonsterPos();
	static MonsterPos* create(Point pos);
	static MonsterPos* create(Point pos, bool isDebug);
	bool init(Point pos);
	bool init(Point pos, bool isDebug);
	virtual bool isClickMe(Point pos);
	void draw(Renderer* renderer, const kmMat4 &transform, bool transformupdated);
private:
	void onDraw(const kmMat4 &transform, bool transformupdated);
	CustomCommand _customCommand;
	Monster* m_monster;
};
#endif