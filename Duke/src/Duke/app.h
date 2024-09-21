#pragma once
#include "Platform/Windows/WindowsWindow.h"
#include "Events/ApplicationEvent.h"
#include "LayerStack.h"

namespace Duke
{
    class App
    {
    public:
        App();
        virtual ~App();

        virtual void Run();

        void OnEvent(Event& e);

        void PushLayer(Layer* layer);
        void PushOverlay(Layer* layer);

    private:
        bool OnWindowClose(WindowCloseEvent& e);

        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
        LayerStack m_LayerStack;
    };


    // To be defined in client
    App* CreateApplication();

}