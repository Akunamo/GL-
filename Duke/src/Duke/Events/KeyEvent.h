#pragma once

#include "Event.h"

namespace Duke
{


    class KeyEvent: public Event
    {
    public:
        int GetKeyCode() const { return m_KeyCode; }

        EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryKeyboard)
    protected:
        KeyEvent(int keycode)
        :m_KeyCode(keycode) {}


        int m_KeyCode;
    };




    class KeyPressedEvent:public KeyEvent
    {
    public:
        KeyPressedEvent(int keycode,int keyRepeatCount)
        :KeyEvent(keycode), m_RepeatCount(keyRepeatCount) {}

        inline int GetRepeatCount() const { return m_RepeatCount; }

        EVENT_CLASS_TYPE(KeyPressed)

    private:
        int m_RepeatCount;
    };


    class KeyReleasedEvent:public KeyEvent
    {
    public:
        KeyReleasedEvent(int keycode)
        :KeyEvent(keycode) {}

        EVENT_CLASS_TYPE(KeyReleased)
    };

}