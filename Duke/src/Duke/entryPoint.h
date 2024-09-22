#pragma once

// #ifdef _WIN32

extern Duke::App* Duke::CreateApplication();

int main()
{
    auto app = Duke::CreateApplication();
    app->Run();
    delete app;
}

// #endif