#ifndef _ENTITY_H_
#define _ENTITY_H_
#include "cocos2d.h"
USING_NS_CC;
class Entity:public Node
{
public:
	Entity();
	~Entity();
	void bindSprite(Sprite* sprite);
	Sprite* getSprite();
	void hurtMe(int iHurtValue);
	bool isDead();
protected:
	virtual void onDead();
	virtual void onBindSprite();//绑定精灵时调用
	virtual void onHurt(int iHurtValue);//受伤时调用
private:
	Sprite* m_sprite;//采用组合方式来实现实体
	//CC_SYNTHESIZE IS USE TO DECLARE A PROTECTED VAR
	CC_SYNTHESIZE(int, m_ID, ID);//实体ID
	CC_SYNTHESIZE(int, m_iModeID, iModelID);//模型ID
	CC_SYNTHESIZE(std::string, m_sName, sName);//名字
	CC_SYNTHESIZE(int, m_iHP, iHP);//HP
	CC_SYNTHESIZE(int, m_iDefense, iDefense);//防御
	CC_SYNTHESIZE(int, m_iSpeed, iSpeed);//移动速度
	CC_SYNTHESIZE(int, m_iLevel, iLevel);//等级
	bool m_isDead;
};
#endif