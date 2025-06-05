#include "IGPCH.hpp"
#include "Platform/Vulkan/VulkanPipeline.hpp"

#include "Engine/Log.hpp"

#include <fstream>

namespace Ignition::Platform::Vulkan {
	VulkanPipeline::VulkanPipeline(const std::string& vertexShaderPath, const std::string& fragmentShaderPath) {
		Create(vertexShaderPath, fragmentShaderPath);
	}

	// ---- Private ----
	std::vector<char> VulkanPipeline::ReadFile(const std::string& filepath) {
		std::ifstream file(filepath, std::ios::ate | std::ios::binary);
		IG_CORE_ASSERT(file.is_open(), "Failed to open file.");

		size_t fileSize = (size_t)file.tellg();
		std::vector<char> buffer(fileSize);
		file.seekg(0);
		file.read(buffer.data(), fileSize);
		file.close();

		return buffer;
	}

	void VulkanPipeline::Create(const std::string& vertexShaderPath, const std::string& fragmentShaderPath) {
		IG_CORE_INFO("Loading shader file '{}'", vertexShaderPath);
		auto vertexShaderCode = ReadFile(vertexShaderPath);

		IG_CORE_INFO("Loading shader file '{}'", fragmentShaderPath);
		auto fragmentShaderCode = ReadFile(fragmentShaderPath);

		IG_CORE_INFO("Vertex shader code size: {}", vertexShaderCode.size());
		IG_CORE_INFO("Fragment shader code size: {}", fragmentShaderCode.size());
	}
}