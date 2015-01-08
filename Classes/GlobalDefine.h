#ifndef _GLOBALDEFINE_H_
#define _GLOBALDEFINE_H_
#include "cocos2d.h"

//创建bool变量，setter,getter函数
#define CC_CC_SYNTHESIZE_BOOL(varName, funName)\
protected: bool varName;\
public: bool is##funName(void) const {return varName;}\
public: void set##funName(bool var) {varName = var;}

//消息派发
#define NOTIFY cocos2d::NotificationCenter::getInstance()

#endif