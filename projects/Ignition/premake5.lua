project "Ignition"
	location "%{wks.location}/projects/Ignition"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("%{wks.location}/build/bin/" .. OUTPUT_DIR .. "/%{prj.name}")
	objdir ("%{wks.location}/build/int/" .. OUTPUT_DIR .. "/%{prj.name}")

	pchheader "src/IGNPCH.hpp"
	pchsource "src/IGNPCH.cpp"

	files {
		"src/**.h",
		"src/**.cpp"
	}

	includedirs {
		"src"
	}

	filter "system:windows"
		systemversion "latest"

		defines {
			"IGN_SYS_WINDOWS",
		}

	filter "system:macosx"
		defines {
			"IGN_SYS_MACOS",
		}

	filter "system:linux"
		defines {
			"IGN_SYS_LINUX",
		}

	filter "configurations:Debug"
		defines "IGN_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "IGN_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "IGN_DIST"
		runtime "Release"
		optimize "on"