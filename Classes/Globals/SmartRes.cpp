
#include "SmartRes.h"

SmartRes* SmartRes::s_sharedRes = nullptr;

SmartRes* SmartRes::getInstance()
{
	if (!s_sharedRes)
	{
		s_sharedRes = new (std::nothrow) SmartRes();
		CCASSERT(s_sharedRes, "FATAL: Not enough memory");
		s_sharedRes->init();
	}

	return s_sharedRes;
}

bool SmartRes::init(void)
{
    return true;
}

void SmartRes::setVirtualScreenWidth(float width)
{
	// initialize director
	auto director = Director::getInstance();
	auto glview = director->getOpenGLView();

    // 暂时没有找到怎么获取设备方向；所以假定是横向//
    const Size& winSizeInPixels = Director::getInstance()->getWinSizeInPixels();

    m_scale = winSizeInPixels.width / width;
    m_screenSize.width = width;
//	m_screenSize.height = winSizeInPixels.height / m_scale;
	m_screenSize.height = 720.0f;
	glview->setDesignResolutionSize(
		m_screenSize.width,
		m_screenSize.height, 
		kResolutionExactFit
                                    
		);

    log("Virtual width: %0.2f, Virtual height: %0.2f, scale: %0.2f",
        m_screenSize.width, m_screenSize.height, m_scale);

	const Size& winSize = Director::getInstance()->getWinSize();
    m_center.x = winSize.width / 2;
    m_center.y = winSize.height / 2;
    m_left = 0;
    m_right = m_screenSize.width - 1;
    m_top = m_screenSize.height - 1;
    m_bottom = 0;

    log("center x: %0.2f, center y: %0.2f", m_center.x, m_center.y);
    log("top: %0.2f, right: %0.2f, bottom: %0.2f, left: %0.2f", m_top, m_right, m_bottom, m_left);
}

SmartRes::~SmartRes()
{
}

void SmartRes::purge()
{
	CC_SAFE_DELETE(s_sharedRes);
}
