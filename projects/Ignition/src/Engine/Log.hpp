#pragma once
#include "IGAPI.hpp"

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

namespace Ignition::Engine {
	class Log {
	public:
		static void Init();
		inline static IGRef<spdlog::logger>& GetCoreLogger() { return sCoreLogger; }
		inline static IGRef<spdlog::logger>& GetClientLogger() { return sClientLogger; }

	private:
		static IGRef<spdlog::logger> sCoreLogger;
		static IGRef<spdlog::logger> sClientLogger;
	};
}

#ifdef IG_SYS_WINDOWS
	#define IG_BREAK __debugbreak();
#elif defined(IG_SYS_MACOS)
	#define IG_BREAK __builtin_debugtrap();
#else
	#define IG_BREAK __builtin_trap();
#endif

// TODO: Add a check for release type, then cast 0 to a void for each
#define IG_CORE_TRACE(...)    ::Ignition::Engine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define IG_CORE_INFO(...)     ::Ignition::Engine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define IG_CORE_WARN(...)     ::Ignition::Engine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define IG_CORE_ERROR(...)    ::Ignition::Engine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define IG_CORE_CRITICAL(...) ::Ignition::Engine::Log::GetCoreLogger()->critical(__VA_ARGS__)

#define IG_CORE_ASSERT(x, msg) \
    if ((x)) {} else { IG_CORE_CRITICAL("{}\n\n\t{}\n\n\tFile: {}\n\tLine: {}", #x, msg, __FILE__, __LINE__); IG_BREAK }

#define IG_TRACE(...)         ::Ignition::Engine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define IG_INFO(...)          ::Ignition::Engine::Log::GetClientLogger()->info(__VA_ARGS__)
#define IG_WARN(...)          ::Ignition::Engine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define IG_ERROR(...)         ::Ignition::Engine::Log::GetClientLogger()->error(__VA_ARGS__)
#define IG_CRITICAL(...)      ::Ignition::Engine::Log::GetClientLogger()->critical(__VA_ARGS__)

#define IG_ASSERT(x, msg) \
    if ((x)) {} else { IG_CRITICAL("{}\n\n\t{}\n\n\tFile: {}\n\tLine: {}", #x, msg, __FILE__, __LINE__); IG_BREAK }