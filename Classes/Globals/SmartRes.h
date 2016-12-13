
#ifndef __SMART_RES_H_
#define __SMART_RES_H_


#include "cocos2d.h"
USING_NS_CC;

#define _center     SmartRes::getInstance()->getCenter()
#define _top        SmartRes::getInstance()->getTop()
#define _right      SmartRes::getInstance()->getRight()
#define _bottom     SmartRes::getInstance()->getBottom()
#define _left       SmartRes::getInstance()->getLeft()
#define _scale      SmartRes::getInstance()->getScale()
#define _xy(v)      SmartRes::getInstance()->xy(v)

class SmartRes
{
public:
    //static SmartRes* sharedRes(void);
	/**
	* Returns a shared instance of the SmartRes.
	*/
	static SmartRes* getInstance();
	static void purge();

    // 设定虚拟屏幕的宽度//
    void setVirtualScreenWidth(float width);

    const Size getScreenSize(void) {
        return m_screenSize;
    }

    float getScale(void) {
        return m_scale;
    }

    const Vec2 getCenter(void) {
        return m_center;
    }

    float getTop(void) {
        return m_top;
    }

    float getRight(void) {
        return m_right;
    }

    float getBottom(void) {
        return m_bottom;
    }

    float getLeft(void) {
        return m_left;
    }

    float xy(float v) {
        return m_scale * v;
    }

private:
    SmartRes(void)
    : m_scale(1.0f)
    , m_top(0)
    , m_right(0)
    , m_bottom(0)
    , m_left(0)
    {
    }
	virtual ~SmartRes();

    bool init(void);

    static SmartRes* s_sharedRes;

    Size m_screenSize;
    Vec2 m_center;
    float m_scale;
    float m_top;
    float m_right;
    float m_bottom;
    float m_left;
};

#endif