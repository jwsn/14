#ifndef _CSVUTIL_H_
#define _CSVUTIL_H_
#include "cocos2d.h"
#include "CsvData.h"
#include "StringUtil.h"
USING_NS_CC;
class CsvUtil:public Ref
{
public:
	static CsvUtil* getInstance();
	virtual bool init();
	void loadFile(const char* path);
	Value getValue(int iRow, int iCol, const char* csvFilePath);
	const std::string getString(int iRow, int iCol, const char* csvFilePath);
	const int getInt(int iRow, int iCol, const char* csvFilePath);
	const Size getFileRowColNum(const char* csvFilePath);
	const int findValueIntWithLine(const char* chValue, int iValueCol, const char* csvFilePath);
	const float getFloat(int iRow, int iCol, const char* csvFilePath);
	const bool getBool(int iRow, int iCol, const char* csvFilePath);
private:
	static CsvUtil* m_CsvUtil;
	Map<std::string, CsvData*> mCsvMap;
};
#endif