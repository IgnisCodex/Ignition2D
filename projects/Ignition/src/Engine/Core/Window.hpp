#pragma once
#include "IGAPI.hpp"

namespace Ignition::Engine::Core {
	struct WindowProperties {
		std::string Title;
		uint32_t Width;
		uint32_t Height;

		WindowProperties(
			const std::string title = "Ignition",
			uint32_t width = 1280,
			uint32_t height = 720
		)
			: Title(title)
			, Width(width)
			, Height(height)
		{}
	};

	class Window {
	public:
		virtual ~Window() {}

		virtual void* GetWindow() const = 0;
		virtual uint32_t GetWidth() const = 0;
		virtual uint32_t GetHeight() const = 0;
		virtual void SetVSync(bool enabled) = 0;

		virtual bool VSync() const = 0;

		virtual void OnUpdate() = 0;

		static IGScope<Window> Create(const WindowProperties& properties = WindowProperties());
	};
}