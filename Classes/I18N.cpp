#include "I18N.h"
#include "CsvUtil.h"
I18N* I18N::m_I18N = NULL;

I18N* I18N::getInstance()
{
	if(m_I18N == NULL)
	{
		m_I18N = new I18N();
		if(m_I18N && m_I18N->init())
		{
			m_I18N->autorelease();
			m_I18N->retain();
		}
		else
		{
			CC_SAFE_DELETE(m_I18N);
			m_I18N = NULL;
		}
	}
	return m_I18N;
}
bool I18N::init()
{
	loadStringsFromConf("i18n/Public.csv");
	return true;
}
const char* I18N::getString(EnumStrKey enStrKey)
{
	return mStringMap.at(enStrKey).c_str();
}
const char* I18N::getStringByKey(int iKey)
{
	return mStringMap.at(iKey).c_str();
}
void I18N::loadStringsFromConf(const char* filePath)
{
	CsvUtil::getInstance()->loadFile(filePath);
	Size size = CsvUtil::getInstance()->getFileRowColNum(filePath);
	int iRowNum = size.width;
	int iColNum = size.height;
	if(iColNum < 2)
	{
		return;
	}
	for(int i = 1; i < iRowNum; i++)
	{
		int key = CsvUtil::getInstance()->getInt(i, 0, filePath);
		std::string value = CsvUtil::getInstance()->getString(i, 1, filePath);
		mStringMap[key] = value;
	}
}









