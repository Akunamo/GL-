#include "app.h"
#include "Events/MouseEvent.h"
#include "dkpch.h"

#include "GLFW/glfw3.h"
namespace Duke
{
    #define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)

    App::App()
    {
        m_Window = std::unique_ptr<Window>(Window::Create());
        m_Window->SetEventCallback(BIND_EVENT_FN(App::OnEvent));
    }

    void App::Run()
    {
        while (m_Running)
        {
            glClearColor(1, 0, 1, 1);
            glClear(GL_COLOR_BUFFER_BIT);
            m_Window->OnUpdate();
        }
        
    }

    void App::OnEvent(Event& e)
    {
        std::cout<< e.GetName()<<std::endl;
    }


    App::~App()
    {
    }
}