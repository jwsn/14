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
	UI->setTouchEnabled(false);//UI����Ҳ�ǿؼ�����СΪ400*800����������仰��UI�Ĵ�����Ӧ�رգ������·����ж���Ĵ����¼����ᱻ�Ե�
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