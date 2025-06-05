project "Ignition"
	location "%{wks.location}/projects/Ignition"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("%{wks.location}/build/bin/" .. OUTPUT_DIR .. "/%{prj.name}")
	objdir ("%{wks.location}/build/int/" .. OUTPUT_DIR .. "/%{prj.name}")

	pchheader "IGPCH.hpp"
	pchsource "src/IGPCH.cpp"

	files {
		"src/**.h",
		"src/**.cpp",

		-- "%{inc.GLM}/glm/**.hpp",
		-- "%{inc.GLM}/glm/**.inl",
	}

	includedirs {
		"src",
		"%{inc.GLFW}",
		"%{inc.SPDLOG}",
		"%{inc.VULKAN}",
		"%{inc.GLM}"
	}

	libdirs {
		"%{lib.VULKAN}"
	}

	defines {
		"GLFW_INCLUDE_VULKAN"
	}

	filter "system:windows"
		systemversion "latest"

		defines {
			"IG_SYS_WINDOWS"
		}

		buildoptions {
			"/utf-8"
		}

		links {
			"vulkan-1"
		}

	filter "system:macosx"
		defines {
			"IG_SYS_MACOS"
		}

	filter "system:linux"
		defines {
			"IG_SYS_LINUX"
		}

	filter "configurations:Debug"
		defines "IG_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "IG_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "IG_DIST"
		runtime "Release"
		optimize "on"