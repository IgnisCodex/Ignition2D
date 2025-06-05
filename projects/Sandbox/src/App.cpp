#define IG_APPLICATION
#define IG_USE_ALIASES
#include <Ignition.hpp>

class Sandbox : public IGECore::Application {
public:
	Sandbox() {
		IGPVulkan::VulkanPipeline vkpipe = IGPVulkan::VulkanPipeline("assets/shaders/simple.vert.spv", "assets/shaders/simple.frag.spv");

	}

	~Sandbox() {

	}
};

IGECore::Application* IGECore::CreateApplication() {
	return new Sandbox();
}