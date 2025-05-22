project "Ignition"
	location "%{wks.location}/projects/Ignition"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("%{wks.location}/build/bin/" .. OUTPUT_DIR .. "/%{prj.name}")
	objdir ("%{wks.location}/build/int/" .. OUTPUT_DIR .. "/%{prj.name}")

	pchheader "src/IGPCH.hpp"
	pchsource "src/IGPCH.cpp"

	files {
		"src/**.h",
		"src/**.cpp"
	}

	includedirs {
		"src",
		"%{libs.GLFW}",
		"%{libs.SPDLOG}"
	}

	defines {
		"GLFW_INCLUDE_NONE"
	}

	filter "system:windows"
		systemversion "latest"

		defines {
			"IG_SYS_WINDOWS"
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