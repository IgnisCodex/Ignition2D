#pragma once

#include <string>
#include "Engine/Core/Window.hpp"

namespace Ignition::Engine::Core {
	class Application {
	public:
		Application(const std::string& name = "Ignition");
		virtual ~Application();

		void Run();
		void Quit();

		inline static Application& Get() { return *sInstance; }

	private:
		bool mIsRunning = true;
		bool mIsMinimized = false;

		IGScope<Window>	mWindow;

	private:
		static Application* sInstance;
	};

	// This is to be defined in the client application.
    // It is the entry point of the application.
	Application* CreateApplication();
}