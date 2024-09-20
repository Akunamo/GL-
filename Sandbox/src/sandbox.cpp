#include "Duke.h"

class Sandbox: public Duke::App
{
private:
    /* data */
public:
    Sandbox(/* args */);
    ~Sandbox();
};

Sandbox::Sandbox(/* args */)
{
}

Sandbox::~Sandbox()
{
}



Duke::App*  Duke::CreateApplication() {
    return new Sandbox();
}

