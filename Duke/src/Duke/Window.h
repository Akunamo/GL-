#pragma once

#include "dkpch.h"
#include "Events/Event.h"

namespace Duke
{

    struct WindowProps
    {
        std::string Title;
        unsigned int Width, Height;

        WindowProps(const std::string& title = "DUKE SLAYS", unsigned int width = 1280, unsigned int height = 720)
        :Title(title), Width(width), Height(height){}
    };

    class Window
    {
    public:
        using EventCallbackFn = std::function<void(Event&)>;

        virtual ~Window() = default;

        virtual void OnUpdate() = 0;

        virtual unsigned int GetWidth() const = 0;
        virtual unsigned int GetHeight() const = 0;
        virtual GLFWwindow* GetNativeWindow() = 0;

        // Window atributes
        virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
        virtual void SetVSync(bool enabled) = 0;
        virtual bool IsVSync() const = 0;

        static Window* Create(const WindowProps& props = WindowProps());
    };

}