#ifndef _CONTROLLERSIMPLEMOVE_H_
#define _CONTROLLERSIMPLEMOVE_H_
#include "cocos2d.h"
#include "Entity.h"
#include "ControllerMoveBase.h"
#include "PosBase.h"
USING_NS_CC;
class ControllerSimpleMove:public ControllerMoveBase
{
public:
	ControllerSimpleMove();
	~ControllerSimpleMove();
	static ControllerSimpleMove* create(Entity* entity);
	bool init(Entity* entity);
	void checkMoveUpdate(float dt);
	void moveByPosList(Vector<PosBase*> posList);//���ո�����������ƶ�
	void moveByPosList(Vector<PosBase*> posList, int iSpeed);//���ո������������ƶ��ٶ�
	void moveByPosList(Vector<PosBase*> posList, int iSpeed, int iSpanTime);//���ո���������㡣�ٶȡ��ƶ�ʱ����
	void moveByPos(PosBase* pos);
private:
	void moveOneStep();//�ƶ�һ��
	void nextMovePos();//������һ���ƶ�Ŀ�ĵ�
private:
	Vector<PosBase*> m_movePosList;//�ƶ�Ŀ���б�
	PosBase* m_curDestPos;//��ǰ�ƶ�Ŀ�ĵ�
	float m_MoveSpan;//�ƶ�ʱ����
	float m_fMoveTimeCount;//��ʱ��
};
#endif