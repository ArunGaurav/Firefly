workspace "Firefly"
	architecture "x64"
	configurations 
	{ "Debug",
	  "Release",
	  "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
startproject "Sandbox"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Firefly/vendor/GLFW/include"
IncludeDir["Glad"] = "Firefly/vendor/Glad/include"
IncludeDir["ImGui"] = "Firefly/vendor/ImGui"

group "Dependencies"
	include "Firefly/vendor/GLFW"
	include "Firefly/vendor/Glad"
	include "Firefly/vendor/ImGui"

group ""

project "Firefly"
	location "Firefly"
	kind "SharedLib"
	language "C++"
	staticruntime "off"

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
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}"
	}

	links 
	{
		"Glad",
		"GLFW",
		"ImGui",
		"opengl32.lib"
	}

	postbuildcommands
	{
		("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
	}

	filter "system:windows"	
		cppdialect "C++17"
		systemversion "latest"

	defines
	{
		"FF_PLATFORM_WINDOWS",
		"FF_BUILD_DLL",
		"GLFW_INCLUDE_NONE"
	}


	filter "configurations:Debug"
		defines "FF_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "FF_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "FF_DIST"
		runtime "Release"
		optimize "On"

		
project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "off"

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
		systemversion "latest"

	defines
	{
		"FF_PLATFORM_WINDOWS"
	}

	filter "configurations:Debug"
		defines "FF_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "FF_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "FF_DIST"
		runtime "Release"
		optimize "On"
	 