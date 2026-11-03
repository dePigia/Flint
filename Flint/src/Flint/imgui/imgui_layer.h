#pragma once

#include "Flint/layer.h"
#include "Flint/events/application_event.h"
#include "Flint/events/key_event.h"
#include "Flint/events/mouse_event.h"


namespace Flint {
    class FLINT_API ImGuiLayer : public Layer {
    private:
        bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& e);
        bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e);
        bool OnMouseMovedEvent(MouseMovedEvent& e);
        bool OnMouseScrolledEvent(MouseScrolledEvent& e);
        bool OnKeyPressedEvent(KeyPressedEvent& e);
        bool OnKeyReleasedEvent(KeyReleasedEvent& e);
        bool OnKeyTypedEvent(KeyPressedEvent& e);
        bool OnWindowResizeEvent(WindowResizeEvent& e);

        float m_Time = 0.0f;
    public:
        ImGuiLayer();
        ~ImGuiLayer() = default;

        void OnAttach() override;
        void OnDetach() override;
        void OnUpdate() override;
        void OnEvent(Event& event) override;
    };
}
