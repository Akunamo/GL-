#pragma once

#include "Duke/core.h"

namespace Duke 
{

    enum class EventType
    {
        None = 0,
        WindowClose,WindowResize,WindowFocus,WindowMoved,
        AppTick, AppUpdate, AppRender,
        KeyPressed,KeyReleased,
        MouseButtonPressed,MouseButtonReleased, MouseMoved, MouseScrolled
    };


    enum EventCategory
    {
        None = 0,
        EventCategoryApplication = BIT(1),
        EventCategoryInput       = BIT(2),
        EventCategoryKeyboard    = BIT(3),
        EventCategoryMouse       = BIT(4),
        EventCategoryMouseButton = BIT(5),
    };

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::type; } \
virtual const char* GetName() const override { return #type; } \
virtual EventType GetEventType() const override { return GetStaticType(); }



#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

    class Event
    {
        friend class EventDispatcher;
    public:

        virtual EventType GetEventType() const = 0;

        virtual const char* GetName() const = 0;
        virtual std::string ToString() const { return GetName(); }
        
        
        virtual int GetCategoryFlags() const = 0;
        inline bool IsInCategory(EventCategory category) const
        {
            return GetCategoryFlags() & category;
        }

        bool m_Handled = false;
    protected:
    };

    class EventDispatcher
    {

        template<typename T>
        using EventFn = std::function<bool(T&)>;
    public:
        EventDispatcher(Event& event)
        :m_Event(event)
        {

        }

        template<typename T>
        bool Dispatch(EventFn<T> func)
        {
            if(m_Event.GetEventType() == T::GetStaticType())
            {
                m_Event.m_Handled = func(*(T*)&m_Event);
                return true;
            }
            return false;
        }

    private:
        Event& m_Event;
    };
}