#pragma once

#include "Event.h"

namespace Duke
{
    class MouseMoveEvent:public Event
    {
    public:
        MouseMoveEvent(float x, float y)
        :m_X(x), m_Y(y) {}

        inline float GetX() const { return m_X; }
        inline float GetY() const { return m_Y; }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseMoveEvent:" << "x = " << GetX() << ", y = " << GetY();
            return ss.str();
        }
    
        EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse)
        EVENT_CLASS_TYPE(MouseMoved)

    private:
        float m_X, m_Y;
    };



    class MouseScrolledEvent: public Event
    {
    public:
        MouseScrolledEvent(float xOffset, float yOffset)
        :m_XOffset(xOffset),m_YOffset(yOffset) {}

        inline float GetXOffset() const { return m_XOffset; }
        inline float GetYOffset() const { return m_YOffset; }

        EVENT_CLASS_TYPE(MouseScrolled)
        EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse)

    private:
        float m_XOffset, m_YOffset;
    };


    class MouseButtonEvent: public Event
    {
    public:
        inline int GetMouseButton() const { return m_Button; }
    
    EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse)

    protected:
        MouseButtonEvent(int button)
        :m_Button(button) {}

        int m_Button;
    };


    class MouseButtonPressedEvent: public MouseButtonEvent
    {
    public:
        MouseButtonPressedEvent(int button)
        :MouseButtonEvent(button) {}

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseButonPressedEvent:" << "--  Button Pressed = " << GetMouseButton();
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseButtonPressed)
    };

        class MouseButtonReleasedEvent: public MouseButtonEvent
    {
    public:
        MouseButtonReleasedEvent(int button)
        :MouseButtonEvent(button) {}

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseButonReleasedEvent:" << "--  Button Pressed = " << GetMouseButton();
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseButtonPressed)
    };
}