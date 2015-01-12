#ifndef _SCENEMANAGER_H_
#define _SCENEMANAGER_H_
#include "cocos2d.h"
using namespace cocos2d;
class SceneManager:public Ref
{
public:
	enum EnumSceneType{
		en_TollgateScene,//�ؿ�����
		en_TollgateEditorScene,//�ؿ��༭������
		en_WinScene,//ʤ������
		en_GameOverScene,//��Ϸ��������
	};

	static SceneManager* getInstance();
	virtual bool init();
	void changeScene(EnumSceneType enSceneType);
private:
	static SceneManager* mSceneManager;
};
#endif