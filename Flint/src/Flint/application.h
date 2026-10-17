#pragma once

#include "core.h"
#include "window.h"
#include "Flint/events/event.h"


namespace Flint {
    class FLINT_API Application {
    private:
        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
    public:
        Application();
        virtual ~Application();

        void Run();
    };

    Application* CreateApplication();
}
