#ifndef _POSLOADUTIL_H_
#define _POSLOADUTIL_H_
#include "PosBase.h"
#include "EnumPosType.h"
USING_NS_CC;
class PosLoadUtil:public Node
{
public:
	static PosLoadUtil* getInstance();
	virtual bool init();
	Vector<PosBase*> loadPosWithFile(const char* sFilePath, EnumPosType enPosType, Node* container, int iLevel, bool isDebug);
private:
	static PosLoadUtil* m_PosLoadUtil;
};
#endif