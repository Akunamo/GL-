#include "app.hpp"
#include "Events/MouseEvent.h"
#include "dkpch.h"
namespace Duke
{
    App::App()
    {
        
    }

    void App::run()
    {
        while (true)
        {
            Event* e = new MouseButtonPressedEvent(20);
            std::cout<<e->GetName()<<std::endl;
            /* code */
        }
        
    }


    App::~App()
    {
    }
}