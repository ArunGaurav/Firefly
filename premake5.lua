workspace "Firefly"
	architecture "x64"
	configurations 
	{ "Debug",
	  "Release",
	  "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Firefly/vendor/GLFW/include"

include "Firefly/vendor/GLFW"


project "Firefly"
	location "Firefly"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "ffpch.h"
	pchsource "Firefly/src/ffpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Firefly/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links 
	{
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"	
		cppdialect "C++17"
		staticruntime "Off"
		systemversion "latest"

	defines
	{
		"FF_PLATFORM_WINDOWS",
		"FF_BUILD_DLL"
	}

	postbuildcommands
	{
		("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
	}

	filter "configurations:Debug"
	defines "FF_DEBUG"
	symbols "On"

	filter "configurations:Release"
	defines "FF_RELEASE"
	optimize "On"

	filter "configurations:Dist"
	defines "FF_DIST"
	optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs 
	{
		"Firefly/src",
		"Firefly/vendor/spdlog/include"
	}
	
	links
	{
		"Firefly"
	}

	filter "system:windows"	
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

	defines
	{
		"FF_PLATFORM_WINDOWS"
	}

	filter "configurations:Debug"
	defines "FF_DEBUG"
	symbols "On"

	filter "configurations:Release"
	defines "FF_RELEASE"
	optimize "On"

	filter "configurations:Dist"
	defines "FF_DIST"
	optimize "On"
	 