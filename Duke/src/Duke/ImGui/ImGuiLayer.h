#pragma once

#include "Duke/Layer.h"

#include "Duke/Events/ApplicationEvent.h"
#include "Duke/Events/KeyEvent.h"
#include "Duke/Events/MouseEvent.h"

namespace Duke
{

    class ImGuiLayer : public Layer
    {
    public:
        ImGuiLayer();
        ~ImGuiLayer();

        virtual void OnAttach() override;
        virtual void OnDetach() override;
        virtual void OnImGuiRender();

        void Begin();
        void End();

    private:
        float m_Time = 0.0f;
    };

}