#ifndef _SCENEMANAGER_H_
#define _SCENEMANAGER_H_
#include "cocos2d.h"
using namespace cocos2d;
class SceneManager:public Ref
{
public:
	enum EnumSceneType{
		en_TollgateScene,//关卡场景
		en_TollgateEditorScene,//关卡编辑器场景
		en_WinScene,//胜利场景
		en_GameOverScene,//游戏结束场景
	};

	static SceneManager* getInstance();
	virtual bool init();
	void changeScene(EnumSceneType enSceneType);
private:
	static SceneManager* mSceneManager;
};
#endif