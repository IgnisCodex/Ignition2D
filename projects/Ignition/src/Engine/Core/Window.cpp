#include "IGPCH.hpp"
#include "Engine/Core/Window.hpp"

#include "Platform/GLFW/GLFWWindow.hpp"

namespace Ignition::Engine::Core {
    IGScope<Engine::Core::Window> Engine::Core::Window::Create(const Engine::Core::WindowProperties& properties) {
		return IGCreateScope<Platform::GLFW::GLFWWindow>(properties);
	}
}