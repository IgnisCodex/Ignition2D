local vulkan_sdk = os.getenv("VULKAN_SDK")
if vulkan_sdk == nil then
    error("\nVULKAN_SDK environment variable is not set. Please install the Vulkan SDK and restart your shell.")
end

inc = {}
inc.GLFW = "%{wks.location}/libs/glfw/include"
inc.SPDLOG = "%{wks.location}/libs/spdlog/include"
inc.VULKAN = vulkan_sdk .. "/Include"
inc.GLM = "%{wks.location}/libs/glm"

lib = {}
lib.VULKAN = vulkan_sdk .. "/Lib"