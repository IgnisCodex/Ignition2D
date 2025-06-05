#pragma once

#include <string>
#include <vector>

namespace Ignition::Platform::Vulkan {
	class VulkanPipeline {
	public:
		VulkanPipeline(const std::string& vertexShaderPath, const std::string& fragmentShaderPath);

	private:
		static std::vector<char> ReadFile(const std::string& filepath);
		void Create(const std::string& vertexShaderPath, const std::string& fragmentShaderPath);
	};
}