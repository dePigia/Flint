#include "Flint/flint_pch.h"
#include "imgui_layer.h"

#include "imgui.h"
#define GLFW_INCLUDE_NONE
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"

#include "Flint/application.h"

#include "GLFW/glfw3.h"
#include "glad/glad.h"

namespace Flint {
    ImGuiLayer::ImGuiLayer()
        : Layer("ImGuiLayer") {
    }

    void ImGuiLayer::OnAttach() {
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO(); (void)io;
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;

        ImGui::StyleColorsDark();

        Application& app = Application::Get();
        GLFWwindow* window = static_cast<GLFWwindow*>(app.GetWindow().GetNativeWindow());

        ImGui_ImplGlfw_InitForOpenGL(window, true);
        ImGui_ImplOpenGL3_Init("#version 410");
    }

    void ImGuiLayer::OnDetach() {
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();
    }

    void ImGuiLayer::OnUpdate() {
        ImGuiIO& io = ImGui::GetIO();
        Application& app = Application::Get();
        io.DisplaySize = ImVec2((float)app.GetWindow().GetWidth(), (float)app.GetWindow().GetHeight());

        float time = (float)glfwGetTime();
        io.DeltaTime = m_Time > 0.0f ? (time - m_Time) : (1.0f / 60.0f);
        m_Time = time;

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        static bool show_demo_window = true;
        ImGui::ShowDemoWindow(&show_demo_window);

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }

    void ImGuiLayer::OnEvent(Event& event) {
    }
}