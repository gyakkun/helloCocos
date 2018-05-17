#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;
USING_NS_CC_EXT;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

	//auto displaySwitch = MenuItemImage::create(
	//	"DisplaySwitch.png", "DisplaySwitchSelected.png", CC_CALLBACK_1(HelloWorld::displaySwitchCallback, this)
	//);

    if (closeItem == nullptr ||
        closeItem->getContentSize().width <= 0 ||
        closeItem->getContentSize().height <= 0)
    {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width - closeItem->getContentSize().width/2;
        float y = origin.y + closeItem->getContentSize().height/2;
        closeItem->setPosition(Vec2(x,y));
    }

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label

    auto label = Label::createWithTTF(HelloWorld::FontToUTF8("你好, 世界!"), "fonts/gyakkun_kai.ttf", 48);
    auto sidLabel = Label::createWithTTF(HelloWorld::FontToUTF8("吴志远 15322220"), "fonts/gyakkun_kai.ttf", 24);

	
    if (label == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
		//set the display color of label
		label->setColor(cocos2d::Color3B(0, 158, 150));

        // position the label on the center of the screen
        label->setPosition(Vec2(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height - label->getContentSize().height));

        // add the label as a child to this layer
        this->addChild(label, 1);
    }
	
	if (sidLabel == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
		//set the display color of label
		sidLabel->setColor(cocos2d::Color3B(196, 144, 191));

        // position the label on the center of the screen
		sidLabel->setPosition(Vec2(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height - label->getContentSize().height - sidLabel->getContentSize().height));

        // add the label as a child to this layer
        this->addChild(sidLabel, 1);
    }

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("Icon_PosuCore.png");
    if (sprite == nullptr)
    {
        problemLoading("'Icon_PosuCore.png'");
    }
    else
    {
        // position the sprite on the center of the screen
        sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

        // add the sprite as a child to this layer
        this->addChild(sprite, 0);
    }


	//CCSprite* bg1 = CCSprite::create("ControlSwith_bg.png");
	//CCSprite* on1 = CCSprite::create("ControlSwith_on.png");
	//CCSprite* off1 = CCSprite::create("ControlSwith_off.png");
	//CCSprite* thumb1 = CCSprite::create("ControlSwith_thumb.png");
	//CCControlSwitch* controlSwitch1 = CCControlSwitch::create(bg1, on1, off1, thumb1);
	//controlSwitch1->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2) - ccp(100, 100));
	//this->addChild(controlSwitch1);

	////绑定事件，当开关控件的值发生改变时触发事件。
	//controlSwitch1->addTargetWithActionForControlEvents(this, cccontrol_selector(HelloWorld::valueChanged), CCControlEventValueChanged);



    return true;
}


//事件响应函数，值改变时，修改label标签的内容
//void HelloWorld::valueChanged(CCObject* sender, CCControlEvent controlEvent) {
//	//获取事件的传递者CCControlSwitch
//	CCControlSwitch* controlSwitch = (CCControlSwitch*)sender;
//
//	//根据开关控件的状态，设置label标签的内容
//	if (controlSwitch->isOn()) {
//		label->setString("ON");
//	}
//	else {
//		label->setString("OFF");
//	}
//}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
}

//void HelloWorld::displaySwitchCallback(Ref* pSender) {
//	//Close the cocos2d-x game scene and quit the application
//	
//	HelloWorld::sidLabel
//	/*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/
//
//	//EventCustom customEndEvent("game_scene_close_event");
//	//_eventDispatcher->dispatchEvent(&customEndEvent);
//}

