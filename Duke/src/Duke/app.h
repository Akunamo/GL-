#pragma once
#include "Platform/Windows/WindowsWindow.h"

namespace Duke
{
    class App
    {
    public:
        App();
        virtual ~App();

        void Run();

        void OnEvent(Event& e);

    private:
        std::unique_ptr<Window> m_Window;

        bool m_Running = true;
    };


    // To be defined in client
    App* CreateApplication();

}