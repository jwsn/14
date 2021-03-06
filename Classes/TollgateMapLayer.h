#ifndef _TOLLGATEMAPLAYER_H_
#define _TOLLGATEMAPLAYER_H_
#include "cocos2d.h"
#include "HeroManager.h"
#include "MonsterManager.h"
USING_NS_CC;
class TollgateMapLayer:public Layer
{
public:
	TollgateMapLayer();
	~TollgateMapLayer();
	CREATE_FUNC(TollgateMapLayer);
	virtual bool init();
private:
	int m_iCurLevel;
	HeroManager* m_heroMgr;
	MonsterManager* m_monsterMgr;
	void loadConfig();
	void logic(float dt)
};
#endif