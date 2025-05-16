project "Sandbox"
	location "%{wks.location}/projects/Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("%{wks.location}/build/bin/" .. OUTPUT_DIR .. "/%{prj.name}")
	objdir ("%{wks.location}/build/int/" .. OUTPUT_DIR .. "/%{prj.name}")

	files {
		"src/**.h",
		"src/**.cpp"
	}

	includedirs {
		"%{wks.location}/projects/Ignition/src"
	}

	links {
		"Ignition"
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
		symbols "On"

	filter "configurations:Release"
		defines "IGN_RELEASE"
		optimize "On"
