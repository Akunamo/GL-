#include "dkpch.h"
#include "WindowsWindow.h"
#include "Events/MouseEvent.h"
#include "Events/KeyEvent.h"
#include "Events/ApplicationEvent.h"

namespace Duke
{
    static bool s_GLFWInitiated = false;

    static void GLFWErrorCallback(int error, const char* description)
    {
        std::cout << "Error:--" << error<<std::endl;
        std::cout << "Description:--" << description <<std::endl;

    }


    Window* Window::Create(const WindowProps& props)
    {
        return new WindowsWindow(props);
    }


    WindowsWindow::WindowsWindow(const WindowProps &props)
    {
        Init(props);
    }

    WindowsWindow::~WindowsWindow()
    {
        Shutdown();
    }

        void WindowsWindow::Init(const WindowProps& props)
    {
        m_Data.Title = props.Title;
        m_Data.Width = props.Width;
        m_Data.Height = props.Height;

        if(!s_GLFWInitiated)
        {
            // TODO Terminate on system Shutdown
            int success = glfwInit();
            if(!success)
            {
                std::cout<<"GLFW not initialization failed";
                glfwSetErrorCallback(GLFWErrorCallback);
            }
            s_GLFWInitiated = true;
        }

        m_Window = glfwCreateWindow((int)m_Data.Width, (int)m_Data.Height, m_Data.Title.c_str(), NULL, NULL);
        glfwMakeContextCurrent(m_Window);

        int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

        glfwSetWindowUserPointer(m_Window, &m_Data);
        SetVSync(true);



        // ========================================================= Set GLFW Callback ===================================================================

        glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window,int width, int height) 
        {
            WindowData& data =  *(WindowData *)glfwGetWindowUserPointer(window);
            data.Width = width;
            data.Height = height;

            WindowResizeEvent* event = new WindowResizeEvent(width, height);

            data.CallbackFn(*event);
        });


        glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
        {
            WindowData& data =  *(WindowData *)glfwGetWindowUserPointer(window);
            WindowCloseEvent event;

            data.CallbackFn(event);
        });

        glfwSetKeyCallback(m_Window, [](GLFWwindow* window,int key, int scancode, int action, int mods)
        {
            WindowData& data =  *(WindowData *)glfwGetWindowUserPointer(window);

            switch(action)
            {
                case GLFW_PRESS:
                {

                    KeyPressedEvent event(key, 0);
                    data.CallbackFn(event);
                    break;
                }
                case GLFW_RELEASE:
                {
                    KeyReleasedEvent event(key);
                    data.CallbackFn(event);
                    break;
                }
                case GLFW_REPEAT:
                {
                    KeyPressedEvent event(key, 1);
                    data.CallbackFn(event);
                    break;
                }
            }
        });

        glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods)
        {
            WindowData& data =  *(WindowData *)glfwGetWindowUserPointer(window);

            switch (action)
            {
                case GLFW_PRESS:
                {

                    MouseButtonPressedEvent event(button);
                    data.CallbackFn(event);
                    break;
                }
                case GLFW_RELEASE:
                {
                    MouseButtonReleasedEvent event(button);
                    data.CallbackFn(event);
                    break;
                }
            }
        });

        glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xoffset, double yoffset)
        {
            WindowData& data = *(WindowData *)glfwGetWindowUserPointer(window);

            MouseScrolledEvent event((float)xoffset, (float)yoffset);
            data.CallbackFn(event);
        });

        glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xPos, double yPos)
        {
            WindowData& data = *(WindowData *)glfwGetWindowUserPointer(window);

            MouseMoveEvent event((float)xPos, (float)yPos);
            data.CallbackFn(event);
        });
    }


    void WindowsWindow::OnUpdate()
    {
        glfwPollEvents();
        glfwSwapBuffers(m_Window);
    }


    void WindowsWindow::SetVSync(bool enabled)
    {
        if(enabled)
            glfwSwapInterval(1);
        else
            glfwSwapInterval(0);

        m_Data.VSync = enabled;
    }

    bool WindowsWindow::IsVSync() const
    {
        return m_Data.VSync;
    }



    void WindowsWindow::Shutdown()
    {
        glfwDestroyWindow(m_Window);
    }
}