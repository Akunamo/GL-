#pragma once

// #ifdef _WIN32

extern Duke::App* Duke::CreateApplication();

int main()
{
    auto app = new Duke::App();
    app->Run();
    delete app;
}

// #endif