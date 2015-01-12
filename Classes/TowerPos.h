#ifndef _TOWERPOS_H_
#define _TOWERPOS_H_
#include"cocos2d.h"
#include"Posbase.h"
USING_NS_CC;
#define RADIUS 32
class TowerPos:public PosBase
{
public:
	TowerPos();
	~TowerPos();
	static TowerPos* create(Point pos);
	static TowerPos* create(Point pos, bool isDebug);
	bool init(Point pos);
	bool init(Point pos, bool isDebug);
	virtual bool isClickMe(Point pos) override;
	void draw(Renderer* renderer, const kmMat4 &transform, unsigned int transformUpdated);
private:
	void onDraw(const kmMat4 &transform, bool transformUpdated);
	CustomCommand _customCommand;
};
#endif