#include "HelloWorldScene.h"
#include "TowerPos.h"
#include "TowerPosEditorLayer.h"
#include "TowerPosEditorOperatorLayer.h"
#include "EnumStrKey.h"
#include "I18N.h"
USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
	auto layer = TowerPosEditorLayer::create();
	scene->addChild(layer, 1);

	auto oplayer = TowerPosEditorOperatorLayer::create(layer);
	scene->addChild(oplayer, 2);

	log("I18N Test:%s",I18N::getInstance()->getString(en_StrKey_Public_Confirm));
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();


    
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
