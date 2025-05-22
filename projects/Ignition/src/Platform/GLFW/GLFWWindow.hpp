#pragma once

#include "Engine/Core/Window.hpp"

#include <GLFW/glfw3.h>

namespace Ignition::Platform::GLFW {
	class GLFWWindow : public Engine::Core::Window {
	public:
		GLFWWindow(const Engine::Core::WindowProperties& properties);
		virtual ~GLFWWindow();

		virtual void* GetWindow() const override { return mWindow; }
		inline uint32_t GetWidth() const override { return mWindowData.Width; }
		inline uint32_t GetHeight() const override { return mWindowData.Height; }
		void SetVSync(bool enabled) override;
		
        bool VSync() const override;
		void OnUpdate() override;

	private:
		virtual void Init(const Engine::Core::WindowProperties& properties);
		virtual void End();

	private:
		struct WindowData {
			std::string Title;
			uint32_t Width = 0;
			uint32_t Height = 0;
			bool VSync = true;
		};

		GLFWwindow* mWindow;
		WindowData mWindowData;
		// Graphics::Context* mContext;
	};
}