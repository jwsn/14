#ifndef _TOWERPOSEDITOROPERATORLAYER_H_
#define _TOWERPOSEDITOROPERATORLAYER_H_
#include "TowerPosEditorLayer.h"

#include "editor-support/cocostudio/CCSGUIReader.h"
#include "cocos-ext.h"
#include "ui/CocosGUI.h"
using namespace cocos2d::ui;
using namespace cocostudio;
USING_NS_CC_EXT;
USING_NS_CC;

class TowerPosEditorOperatorLayer:public Layer
{
public:
	TowerPosEditorOperatorLayer();
	~TowerPosEditorOperatorLayer();
	static TowerPosEditorOperatorLayer* create(TowerPosEditorLayer* layer);
	virtual bool init(TowerPosEditorLayer* layer);
	void draw(Renderer* renderer, const kmMat4 &transform, unsigned int transformupdated);
private:
	void onDraw(const kmMat4 &transform, bool transformupdated);
	CustomCommand _custCommand;
	//four btn
    void outputBtnOnClick(Ref*, TouchEventType type);
	void changeModeBtnOnClick(Ref*, TouchEventType type);
	void nextLevelBtnOnClick(Ref*, TouchEventType type);
	void preLevelBtnOnClick(Ref*, TouchEventType type);
private:

	TowerPosEditorLayer* m_editorLayer;
};
#endif