#pragma once

extern Flint::Application* Flint::CreateApplication();

int main(int argc, char** argv) {
    printf("Flint Engine\n");

    auto app = Flint::CreateApplication();
    app -> Run();
    delete app;

    return 0;
}