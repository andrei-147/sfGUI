workspace "imGUI"
    architecture "x86_64"
    configurations { "Debug", "Release" }

project "Core"
    kind "StaticLib"
    language "C++"
    cppdialect "C++latest"

    location "core"
    targetname "sfgui"
    targetdir "core/bin/%{cfg.buildcfg}"
    objdir "core/bin.obj/%{cfg.buildcfg}"

    includedirs {
        "core/include",
        "dependencies/include"
    }

    libdirs {
        "dependencies/lib"
    }

    files {
        "core/src/**.cpp",
        "core/include/**.hpp"
    }

    links {
        "GL",
        "sfml-system",
        "sfml-window",
        "sfml-graphics"
    }

    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On"

project "basic_example"
    kind "WindowedApp"
    language "C++"
    cppdialect "C++latest"

    location "examples/basic_example"
    targetname "basic_example"
    targetdir "examples/basic_example/bin/%{cfg.buildcfg}"
    objdir "examples/basic_example/bin.obj/%{cfg.buildcfg}"

    links {
        "GL",
        "sfml-system",
        "sfml-window",
        "sfml-graphics",
        "Core"
    }

    includedirs {
        "core/include",
        "examples/basic_example/include",
        "dependencies/include"
    }

    libdirs {
        "dependencies/lib"
    }

    files {
        "examples/basic_example/src/**.cpp",
        "examples/basic_example/include/**.hpp"
    }

    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On"
