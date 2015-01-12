#include "CsvUtil.h"
CsvUtil* CsvUtil::m_CsvUtil = NULL;
CsvUtil* CsvUtil::getInstance()
{
	if(m_CsvUtil == NULL)
	{
		m_CsvUtil = new CsvUtil();
		if(m_CsvUtil && m_CsvUtil->init())
		{
			m_CsvUtil->autorelease();
			m_CsvUtil->retain();
		}
		else
		{
			CC_SAFE_DELETE(m_CsvUtil);
			m_CsvUtil = NULL;
		}
	}
	return m_CsvUtil;
}

bool CsvUtil::init()
{
	return true;
}

const std::string CsvUtil::getString(int iRow, int iCol, const char* csvFilePath)
{
	Value colValue = getValue(iRow, iCol, csvFilePath);
	return colValue.asString();
}
const int CsvUtil::getInt(int iRow, int iCol, const char* csvFilePath)
{
	Value colValue = getValue(iRow, iCol, csvFilePath);
	return colValue.asInt();
}
const float CsvUtil::getFloat(int iRow, int iCol, const char* csvFilePath)
{
	Value colValue = getValue(iRow, iCol, csvFilePath);
	return colValue.asFloat();
}
const bool CsvUtil::getBool(int iRow, int iCol, const char* csvFilePath)
{
	Value colValue = getValue(iRow, iCol, csvFilePath);
	return colValue.asBool();
}
void CsvUtil::loadFile(const char* sPath)
{
	CsvData* csvdata = CsvData::create();
	std::string str = FileUtils::getInstance()->getStringFromFile(sPath);
	ValueVector lineList = StringUtil::getInstance()->split(str.c_str(), "\n");
	for(auto value:lineList)
	{
		ValueVector tArr = StringUtil::getInstance()->split(value.asString().c_str(), ",");
		csvdata->addLineData(tArr);
	}
	mCsvMap.insert(sPath, csvdata);
}

const Size CsvUtil::getFileRowColNum(const char* csvFilePath)
{
	auto csvData = mCsvMap.at(csvFilePath);
	if(csvData == nullptr)
	{
		loadFile(csvFilePath);
		csvData = mCsvMap.at(csvFilePath);
	}
	Size size = csvData->getRowColNum();
	return size;
}
Value CsvUtil::getValue(int iRow, int iCol, const char* csvFilePath)
{
	auto csvData = mCsvMap.at(csvFilePath);
	if(csvData == nullptr)
	{
		loadFile(csvFilePath);
		csvData = mCsvMap.at(csvFilePath);		
	}
	ValueVector rowVector = csvData->getStringLineData(iRow);
	Value colValue = rowVector.at(iCol);
	return colValue;
}
const int CsvUtil::findValueIntWithLine( const char* chValue, int iValueCol, const char* csvFilePath ) {
    Size csvSize = getFileRowColNum(csvFilePath);

    int iLine = -1;
    for(int i = 2; i < csvSize.width; i++) {
        int ID = getInt(i, iValueCol, csvFilePath);
        if(Value(ID).asString().compare(chValue) == 0) {
            iLine = i;
            break;
        }
    }

    return iLine;
}









