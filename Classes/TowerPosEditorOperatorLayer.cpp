#include "TowerPosEditorOperatorLayer.h"
#include "TowerPosEditorLayer.h"
TowerPosEditorOperatorLayer::TowerPosEditorOperatorLayer()
{}
TowerPosEditorOperatorLayer::~TowerPosEditorOperatorLayer()
{}
TowerPosEditorOperatorLayer* TowerPosEditorOperatorLayer::create(TowerPosEditorLayer* layer)
{
	TowerPosEditorOperatorLayer* oprLayer = new TowerPosEditorOperatorLayer();
	if(oprLayer && oprLayer->init(layer))
	{
		oprLayer->autorelease();
	}
	else
	{
		CC_SAFE_DELETE(oprLayer);
	}
	return oprLayer;
}
bool TowerPosEditorOperatorLayer::init(TowerPosEditorLayer* layer)
{
	if(!Layer::init())
	{
		return false;
	}
	this->m_editorLayer = layer;
	auto UI = cocostudio::GUIReader::getInstance()->widgetFromJsonFile("EditorOperate_1/EditorOperate_1.json");//
	this->addChild(UI);
	UI->setTouchEnabled(false);//UI本身也是控件，大小为400*800，必须有这句话将UI的触摸响应关闭，否则下方所有对象的触摸事件都会被吃掉
	auto outputBtn = (Button*)Helper::seekWidgetByName(UI, "outputBtn");
	//outputBtn->addTouchEventListener(this, toucheventselector(TowerPosEditorOperatorLayer::outputBtnOnClick));
	return true;
}

void TowerPosEditorOperatorLayer::outputBtnOnClick(Ref*, TouchEventType type)
{
	if(type == TouchEventType::TOUCH_EVENT_ENDED)
	{
		m_editorLayer->outputPosPlistFile();
	}
}
void TowerPosEditorOperatorLayer::changeModeBtnOnClick(Ref*, TouchEventType type)
{
	if(type == TouchEventType::TOUCH_EVENT_ENDED)
	{
		m_editorLayer->changeMode();
	}
}