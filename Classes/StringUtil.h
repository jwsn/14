#ifndef _STRINGUTIL_H_
#define _STRINGUTIL_H_
#include "cocos2d.h"
USING_NS_CC;
class StringUtil:public Ref
{
public:
	static StringUtil* getInstance();
	virtual bool init();
	ValueVector split(const char* srcStr, const char* sSep);
private:
	static StringUtil* m_StringUtil;
};
#endif