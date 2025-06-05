// NOTE: This file is to only be included in the Client project.
#pragma once

#include "IGAPI.hpp"

// Ignition Engine Headers
#include "Engine/Log.hpp"

#include "Engine/Core/Application.hpp"
#include "Engine/Core/Window.hpp"

#include "Platform/Vulkan/VulkanPipeline.hpp"

// Creates aliases for the Ignition Engine namespaces
#ifdef IG_USE_ALIASES
	// Ignition Aliases
	namespace IGECore = Ignition::Engine::Core;

	namespace IGPVulkan = Ignition::Platform::Vulkan;
	//namespace IGGraphics = Ignition::Engine::Graphics;
#endif // IG_USE_ALIASES

#ifdef IG_APPLICATION
	#include <Main.hpp>
#endif