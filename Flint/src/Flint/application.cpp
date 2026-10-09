#include "application.h"

#include "log.h"
#include "events/application_event.h"


namespace Flint {
    Application::Application() {
    }

    Application::~Application() {
    }

    void Application::Run() {
        WindowResizeEvent e(1280, 720);

        if (e.IsInCategory(EventCategoryApplication)) {
            FLINT_CORE_TRACE("{0}", e);
        }

        while (true);
    }
}
