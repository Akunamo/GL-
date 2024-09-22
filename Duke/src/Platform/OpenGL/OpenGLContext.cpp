#include "dkpch.h"
#include "OpenGLContext.h"
#include "core.h"
namespace Duke
{

    OpenGLContext::OpenGLContext(GLFWwindow *windowHandle)
        : m_WindowHandle(windowHandle)
    {
        ASSERT(windowHandle);
    }

    void OpenGLContext::Init()
    {
        glfwMakeContextCurrent(m_WindowHandle);
        int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        ASSERT(status);
    }

    void OpenGLContext::SwapBuffers()
    {
        glfwSwapBuffers(m_WindowHandle);
    }

}