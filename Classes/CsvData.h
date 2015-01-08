#ifndef _CSVDATA_H_
#define _CSVDATA_H_
#include "cocos2d.h"
USING_NS_CC;
class CsvData:public Ref
{
public:
	CREATE_FUNC(CsvData);
	virtual bool init();
	void addLineData(ValueVector lineData);
	ValueVector getStringLineData(int iLine);
	Size getRowColNum();
private:
	ValueVector m_allLinesVec;
	int m_iColNum;
};
#endif