#include "IGPCH.hpp"
#include "Platform/GLFW/GLFWWindow.hpp"

#include "Engine/Log.hpp"

namespace Ignition::Platform::GLFW {

    GLFWWindow::GLFWWindow(const Engine::Core::WindowProperties& properties) {
        Init(properties);
    }

    GLFWWindow::~GLFWWindow() {
        End();
    }

    void GLFWWindow::Init(const Engine::Core::WindowProperties& properties) {
        mWindowData.Title = properties.Title;
        mWindowData.Width = properties.Width;
        mWindowData.Height = properties.Height;

        glfwInit();
        IG_CORE_INFO("Initalising Window: '{}' ({} x {})", properties.Title, properties.Width, properties.Height);

        mWindow = glfwCreateWindow(properties.Width, properties.Height, properties.Title.c_str(), nullptr, nullptr);
    }

    void GLFWWindow::End() {
		glfwDestroyWindow(mWindow);
	}

	void GLFWWindow::OnUpdate() {
		glfwPollEvents();
		// mContext->SwapBuffers();
	}

	void GLFWWindow::SetVSync(bool enabled) {
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);
		mWindowData.VSync = enabled;
	}

	bool GLFWWindow::VSync() const {
		return mWindowData.VSync;
	}
}