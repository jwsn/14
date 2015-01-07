#ifndef _POSBASE_H_
#define _POSBASE_H_
#include"cocos2d.h"
USING_NS_CC;
class PosBase:public Layer
{
public:
	PosBase();
	~PosBase();
	static PosBase* create(Point pos);
	static PosBase* create(Point pos, bool is_debug);
	bool init(Point pos);
	bool init(Point pos, bool is_debug);
	CC_SYNTHESIZE(Point, m_pos, Pos);
	virtual bool isClickMe(Point pos);
	void setDebug(bool is_debug);
protected:
	bool m_isDebug;
};
#endif