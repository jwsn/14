#ifndef _I18N_H_
#define _I18N_H_
#include "cocos2d.h"
#include "EnumStrKey.h"
USING_NS_CC;
class I18N:public Ref
{
public:
	static I18N* getInstance();
	virtual bool init();
	const char* getString(EnumStrKey enStrKey);
	const char* getStringByKey(int iKey);
private:
	void loadStringsFromConf(const char* filePath);
	static I18N* m_I18N;
	std::map<int, std::string> mStringMap;
};
#endif