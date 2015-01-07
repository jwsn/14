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
private:
    void outputBtnOnClick(Ref*, TouchEventType type);
	void changeModeBtnOnClick(Ref*, TouchEventType type);
private:

	TowerPosEditorLayer* m_editorLayer;
};
#endif