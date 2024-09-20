#pragma once

#ifdef _WIN32

extern Duke::App* Duke::CreateApplication();

int main()
{
    auto app = new Duke::App();
    app->run();
    delete app;
}

#endif