#pragma once

#include "Duke/Window.h"
namespace Duke
{

    class WindowsWindow:public Window
    {
    public:
        WindowsWindow(const WindowProps& props);

        virtual ~WindowsWindow();

        virtual void OnUpdate() override;
        virtual GLFWwindow* GetNativeWindow();


        virtual unsigned int GetWidth() const override { return m_Data.Width; }
        virtual unsigned int GetHeight() const override { return m_Data.Width; }

        inline virtual void SetEventCallback(const EventCallbackFn& callback) { m_Data.CallbackFn = callback; }
        virtual void SetVSync(bool enabled) override;
        virtual bool IsVSync() const override;


    private:
        virtual void Init(const WindowProps& props);
        virtual void Shutdown();

    private:
        GLFWwindow* m_Window;

        struct WindowData
        {  
            std::string Title;
            unsigned int Width,Height;

            bool VSync = false;

            EventCallbackFn CallbackFn;
        };
        WindowData m_Data;
    };
}