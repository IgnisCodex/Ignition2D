OUTPUT_DIR = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

include "dependencies.lua"

workspace "Ignition"
    architecture "ARM64"
    startproject "Sandbox"

    configurations {
        "Debug",
        "Release"
    }


group "Dependencies"
    include "libs/GLFW"
group ""

group "Projects"
    include "projects/Ignition"
    include "projects/Sandbox"
group ""