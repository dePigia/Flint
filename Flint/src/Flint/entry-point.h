#pragma once

#include "application.h"
#include "log.h"

extern Flint::Application* Flint::CreateApplication();

int main(int argc, char** argv) {
    Flint::Log::Init();
    FLINT_CORE_WARN("Initialized Log!");
    int a = 5;
    FLINT_INFO("Hello Var={0}", a);

    auto app = Flint::CreateApplication();
    app -> Run();
    delete app;

    return 0;
}