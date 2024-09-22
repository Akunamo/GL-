#pragma once

#include "dkpch.h"
#include "Renderer/GraphicsContext.h"

namespace Duke
{

    class OpenGLContext : public GraphicsContext
    {
    public:
        OpenGLContext(GLFWwindow *windowHandle);

        virtual void Init() override;
        virtual void SwapBuffers() override;

    private:
        GLFWwindow *m_WindowHandle;
    };
}