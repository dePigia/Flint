#pragma once

#include "event.h"


namespace Flint {
    class FLINT_API MouseMovedEvent : public Event {
    private:
        float m_mouse_x, m_mouse_y;
    public:
        MouseMovedEvent(float x, float y)
            : m_mouse_x(x), m_mouse_y(y) {}

        inline float GetX() const { return m_mouse_x; }
        inline float GetY() const { return m_mouse_y; }

        std::string ToString() const override {
            std::stringstream ss;

            ss << "MouseMovedEvent: " << m_mouse_x << ", " << m_mouse_y;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseMoved)
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput);
    };


    class FLINT_API MouseScrolledEvent : public Event {
    private:
        float m_x_offset, m_y_offset;
    public:
        MouseScrolledEvent(float x_offset, float y_offset)
            : m_x_offset(x_offset), m_y_offset(y_offset) {}

        inline float GetXOffset() const { return m_x_offset; }
        inline float GetYOffset() const { return m_y_offset; }

        std::string ToString() const override {
            std::stringstream ss;

            ss << "MouseScrolledEvent: " << m_x_offset << ", " << m_y_offset;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseScrolled)
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
    };


    class FLINT_API MouseButtonEvent : public Event {
    protected:
        MouseButtonEvent(int button)
            : m_button(button) {}

        int m_button;

    public:
        inline int GetMouseButton() const { return m_button; }

        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput);
    };


    class FLINT_API MouseButtonPressedEvent : public MouseButtonEvent {
    public:
        MouseButtonPressedEvent(int button)
            : MouseButtonEvent(button) {}

        std::string ToString() const override {
            std ::stringstream ss;

            ss << "MouseButtonPressedEvent: " << m_button;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseButtonPressed)
    };


    class FLINT_API MouseButtonReleasedEvent : public MouseButtonEvent {
    public:
        MouseButtonReleasedEvent(int button)
            : MouseButtonEvent(button) {}

        std::string ToString() const override {
            std ::stringstream ss;

            ss << "MouseButtonReleasedEvent: " << m_button;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseButtonReleased)
    };
}