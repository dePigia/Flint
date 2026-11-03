#include "flint_pch.h"
#include "application.h"
#include "log.h"
#include <GLFW/glfw3.h>


namespace Flint {
    Application* Application::s_Instance = nullptr;

    Application::Application() {
        FLINT_CORE_ASSERT(!s_Instance, "Application already exists");
        s_Instance = this;

        m_Window = std::unique_ptr<Window>(Window::Create());
        m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
    }

    Application::~Application() {
    }

    void Application::PushLayer(Layer* layer) {
        m_LayerStack.PushLayer(layer);
    }

    void Application::PushOverlay(Layer* overlay) {
        m_LayerStack.PushOverlay(overlay);
    }

    void Application::OnEvent(Event &e) {
        EventDispatcher dispatcher(e);
        dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

        for (auto it = m_LayerStack.begin(); it != m_LayerStack.end(); ++it) {
            if (e.m_handled) break;
            (*it)->OnEvent(e);
        }
    }

    bool Application::OnWindowClose(WindowCloseEvent &e) {
        m_Running = false;
        return true;
    }

    void Application::Run() {
        while (m_Running) {
            glClearColor(1, 0, 1, 1);
            glClear(GL_COLOR_BUFFER_BIT);

            for (Layer* layer : m_LayerStack) {
                layer->OnUpdate();
            }

            m_Window->OnUpdate();
        }
    }
}
