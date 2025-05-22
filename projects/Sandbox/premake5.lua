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
		"%{wks.location}/projects/Ignition/src",

		"%{libs.SPDLOG}"
	}

	links {
		"GLFW"
	}
	
	links {
		"Ignition"
	}

	filter "system:windows"
		systemversion "latest"

		defines {
			"IG_SYS_WINDOWS",
		}

	filter "system:macosx"
	
		libdirs {
			"%{wks.location}/build/bin/Debug-macosx-ARM64/GLFW"
		}

		defines {
			"IG_SYS_MACOS",
		}

		linkoptions {
			"-framework Cocoa",
			"-framework OpenGL",
			"-framework IOKit",
			"-framework CoreVideo",
			"-framework CoreFoundation",
			"-framework Metal",
			"-framework MetalKit",
			"-framework QuartzCore",
			"-framework AppKit",
			"-framework Foundation",
			"-framework CoreGraphics",
			"-framework CoreAudio",
			"-framework CoreServices"
		}

	filter "system:linux"
		defines {
			"IG_SYS_LINUX",
		}

	filter "configurations:Debug"
		defines "IG_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "IG_RELEASE"
		optimize "On"
