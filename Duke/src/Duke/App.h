#pragma once
#include "Platform/Windows/WindowsWindow.h"
#include "Events/ApplicationEvent.h"
#include "ImGui/ImGuiLayer.h"
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

        static App& Get() { return *s_Instance; }

        inline Window& GetWindow() { return *m_Window; }

    private:
        bool OnWindowClose(WindowCloseEvent& e);

        std::unique_ptr<Window> m_Window;
        bool m_Running = true;

        ImGuiLayer* m_ImGuiLayer;        
        LayerStack m_LayerStack;

    private:
        static App *s_Instance;
    };


    // To be defined in client
    App* CreateApplication();

}