OUTPUT_DIR = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

include "settings.lua"
include "dependencies.lua"

workspace "Ignition2D"
    architecture "x64"
    -- architecture "ARM64"
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