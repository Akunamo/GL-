#pragma once

namespace Duke
{
    class App
    {
        public:
        App();

        void run();


        virtual ~App();
    };


    // To be defined in client
    App* CreateApplication();

}