#pragma once

#include "core.h"
#include <memory>
#include "spdlog/spdlog.h"


namespace Flint {
    class FLINT_API Log {
    public:
        static void Init();

        inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
        inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };
}


// core log macros
#define FLINT_CORE_TRACE(...) ::Flint::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define FLINT_CORE_INFO(...) ::Flint::Log::GetCoreLogger()->info(__VA_ARGS__)
#define FLINT_CORE_WARN(...) ::Flint::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define FLINT_CORE_ERROR(...) ::Flint::Log::GetCoreLogger()->error(__VA_ARGS__)
#define FLINT_CORE_FATAL(...) ::Flint::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// client log macros
#define FLINT_TRACE(...) ::Flint::Log::GetClientLogger()->trace(__VA_ARGS__)
#define FLINT_INFO(...) ::Flint::Log::GetClientLogger()->info(__VA_ARGS__)
#define FLINT_WARN(...) ::Flint::Log::GetClientLogger()->warn(__VA_ARGS__)
#define FLINT_ERROR(...) ::Flint::Log::GetClientLogger()->error(__VA_ARGS__)
#define FLINT_FATAL(...) ::Flint::Log::GetClientLogger()->fatal(__VA_ARGS__)
