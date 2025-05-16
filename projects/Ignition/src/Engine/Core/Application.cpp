#include "IGNPCH.hpp"
#include "Engine/Core/Application.hpp"

namespace Ignition::Core {

	Application* Application::sInstance = nullptr;

	Application::Application(const std::string& name) {
		sInstance = this;
	}

	Application::~Application() {}

	void Application::Run() {
		while (mIsRunning) {

		}
	}

	void Application::Quit() {
		mIsRunning = false;
	}
}