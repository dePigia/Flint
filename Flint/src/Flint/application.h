#pragma once

#include "core.h"
#include "layer_stack.h"
#include "window.h"
#include "events/application_event.h"
#include "Flint/events/event.h"


namespace Flint {
    class FLINT_API Application {
    private:
        bool OnWindowClose(WindowCloseEvent& e);

        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
        LayerStack m_LayerStack;
    public:
        Application();
        virtual ~Application();

        void Run();

        void OnEvent(Event &e);

        void PushLayer(Layer* layer);
        void PushOverlay(Layer* overlay);
    };

    Application* CreateApplication();
}
