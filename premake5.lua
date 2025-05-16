workspace "Ignition"
    architecture "ARM64"
    startproject "Sandbox"

    configurations {
        "Debug",
        "Release"
    }

OUTPUT_DIR = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include subprojects
include "projects/Ignition"
include "projects/Sandbox"