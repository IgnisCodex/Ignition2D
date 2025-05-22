#include "IGPCH.hpp"
#include "Engine/Core/Application.hpp"

#include "Engine/Log.hpp"
#include "Platform/GLFW/GLFWWindow.hpp"

namespace Ignition::Engine::Core {

	Application* Application::sInstance = nullptr;

	Application::Application(const std::string& name) {
		sInstance = this;
		mWindow = Platform::GLFW::GLFWWindow::Create(WindowProperties(name));

		IG_CORE_INFO("Application Created: {0}", name);
	}

	Application::~Application() {}

	void Application::Run() {
		while (mIsRunning) {
			mWindow->OnUpdate();
		}
	}

	void Application::Quit() {
		mIsRunning = false;
	}
}