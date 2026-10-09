#pragma once

#include "event.h"


namespace Flint {
    class FLINT_API KeyEvent : public Event {
    public:
        inline int GetKeyCode() const { return m_keyCode; }

        EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
    protected:
        KeyEvent(int keyCode)
            : m_keyCode(keyCode) {}

        int m_keyCode;
    };


    class FLINT_API KeyPressedEvent : public KeyEvent {
    private:
        int m_repeat_count;
    public:
        KeyPressedEvent(int keyCode, int repeatCount)
            : KeyEvent(keyCode), m_repeat_count(repeatCount) {}

        inline int GetRepeatCount() const { return m_repeat_count; }

        std::string ToString() const override {
            std::stringstream ss;
            ss << "KeyRepeatEvent: " << m_keyCode << " (" << m_repeat_count << " repeats)";
            return ss.str();
        }

        EVENT_CLASS_TYPE(KeyPressed)
    };


    class FLINT_API KeyReleasedEvent : public KeyEvent {
    public:
        KeyReleasedEvent(int keyCode)
            : KeyEvent(keyCode) {}

        std::string ToString() const override {
            std::stringstream ss;

            ss << "KeyReleasedEvent: " << m_keyCode;
            return ss.str();
        }

        EVENT_CLASS_TYPE(KeyReleased)
    };
}