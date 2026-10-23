#include <flint.h>


class ExampleLayer : public Flint::Layer {
public:
    ExampleLayer()
        : Layer("ExampleLayer") {

    }

    void OnUpdate() {
        FLINT_CORE_INFO("ExampleLayer::Update");
    }

    void OnEvent(Flint::Event& event) override {
        FLINT_TRACE("{0}", event);
    }
};


class SandBox: public Flint::Application {
public:
    SandBox() {
        PushLayer(new ExampleLayer());
    }

    ~SandBox() {
    }
};


Flint::Application* Flint::CreateApplication() {
    return new SandBox();
}
