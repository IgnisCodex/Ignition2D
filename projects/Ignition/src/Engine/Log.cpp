#include "IGPCH.hpp"
#include "Engine/Log.hpp"

#include <spdlog/sinks/stdout_color_sinks.h>

namespace Ignition::Engine {

	IGRef<spdlog::logger> Log::sCoreLogger;
	IGRef<spdlog::logger> Log::sClientLogger;

	void Log::Init() {
		spdlog::set_pattern("%^[%T] %n: %v%$");
		sCoreLogger = spdlog::stdout_color_mt("ENGINE");
		sCoreLogger->set_level(spdlog::level::trace);

		sClientLogger = spdlog::stdout_color_mt("APP");
		sClientLogger->set_level(spdlog::level::trace);
	}
}