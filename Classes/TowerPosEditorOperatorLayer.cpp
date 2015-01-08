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
	outputBtn->addTouchEventListener(this, toucheventselector(TowerPosEditorOperatorLayer::outputBtnOnClick));

	auto changeModeBtn = (Button*)Helper::seekWidgetByName(UI, "changeModeBtn");
	changeModeBtn->addTouchEventListener(this, toucheventselector(TowerPosEditorOperatorLayer::changeModeBtnOnClick));

	auto nextLevelBtn = (Button*)Helper::seekWidgetByName(UI, "nextLevelBtn");
	nextLevelBtn->addTouchEventListener(this, toucheventselector(TowerPosEditorOperatorLayer::nextLevelBtnOnClick));

	auto preLevelBtn = (Button*)Helper::seekWidgetByName(UI, "preLevelBtn");
	preLevelBtn->addTouchEventListener(this, toucheventselector(TowerPosEditorOperatorLayer::preLevelBtnOnClick));
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
void TowerPosEditorOperatorLayer::nextLevelBtnOnClick(Ref*, TouchEventType type)
{
	if(type == TouchEventType::TOUCH_EVENT_ENDED)
	{
		m_editorLayer->nextLvl();
	}
}
void TowerPosEditorOperatorLayer::preLevelBtnOnClick(Ref*, TouchEventType type)
{
	if(type == TouchEventType::TOUCH_EVENT_ENDED)
	{
		m_editorLayer->preLvl();
	}
}
void TowerPosEditorOperatorLayer::draw(Renderer* renderer, const kmMat4 &transform, bool transformupdated)
{
	_custCommand.init(_globalZOrder);
	_custCommand.func = CC_CALLBACK_0(TowerPosEditorOperatorLayer::onDraw, this, transform, transformupdated);
	renderer->addCommand(&_custCommand);
}
void TowerPosEditorOperatorLayer::onDraw(const kmMat4 &transform, bool transformupdated)
{
	kmGLPushMatrix();
	kmGLLoadMatrix(&transform);
	Vector<PosBase*> m_monsterPosList = m_editorLayer->getMonsterPosList();
	PosBase* prePos = NULL;
	for(auto posbase: m_monsterPosList)
	{
		if(prePos != NULL)
		{
			DrawPrimitives::drawLine(prePos->getPos(), posbase->getPos());
		}
		prePos = posbase;
	}
	kmGLPopMatrix();
}