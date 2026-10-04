#pragma once
#include "core.h"


namespace Flint {
    class FLINT_API Application {
    public:
        Application();
        virtual ~Application();

        void Run();
    };

    Application* CreateApplication();
}
