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
	virtual void onBindSprite();//�󶨾���ʱ����
	virtual void onHurt(int iHurtValue);//����ʱ����
private:
	Sprite* m_sprite;//������Ϸ�ʽ��ʵ��ʵ��
	//CC_SYNTHESIZE IS USE TO DECLARE A PROTECTED VAR
	CC_SYNTHESIZE(int, m_ID, ID);//ʵ��ID
	CC_SYNTHESIZE(int, m_iModeID, iModelID);//ģ��ID
	CC_SYNTHESIZE(std::string, m_sName, sName);//����
	CC_SYNTHESIZE(int, m_iHP, iHP);//HP
	CC_SYNTHESIZE(int, m_iDefense, iDefense);//����
	CC_SYNTHESIZE(int, m_iSpeed, iSpeed);//�ƶ��ٶ�
	CC_SYNTHESIZE(int, m_iLevel, iLevel);//�ȼ�
	bool m_isDead;
};
#endif