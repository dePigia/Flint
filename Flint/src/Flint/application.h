#pragma once

#include "core.h"
#include "window.h"
#include "events/application_event.h"
#include "Flint/events/event.h"


namespace Flint {
    class FLINT_API Application {
    private:
        bool OnWindowClose(WindowCloseEvent& e);

        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
    public:
        Application();
        virtual ~Application();

        void Run();

        void OnEvent(Event &e);
    };

    Application* CreateApplication();
}
