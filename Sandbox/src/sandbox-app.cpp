#include <flint.h>


class SandBox: public Flint::Application {
public:
    SandBox() {
    }

    ~SandBox() {
    }
};


Flint::Application* Flint::CreateApplication() {
    return new SandBox();
}
