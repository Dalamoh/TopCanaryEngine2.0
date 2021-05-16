workspace "TCGEngine2"
	architecture "x64"


	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include dirs relative to root folder (sln dir)
IncludeDir = {}
IncludeDir["GLFW"] = "TCGEngine2/vendor/GLFW/include"
IncludeDir["Glad"] = "TCGEngine2/vendor/Glad/include"
IncludeDir["ImGui"] = "TCGEngine2/vendor/imgui"

include "TCGEngine2/vendor/GLFW"
include "TCGEngine2/vendor/Glad"
include "TCGEngine2/vendor/imgui"


project "TCGEngine2"
	location "TCGEngine2"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/".. outputdir .. "/%{prj.name}")
	objdir ("bin-int/".. outputdir .. "/%{prj.name}")

	pchheader "TCGEpch.h"
	pchsource "TCGEngine2/src/TCGEpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}"
	}
	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"TCGE_PLATFORM_WINDOWS",
			"TCGE_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/".. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "TCGE_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "TCGE_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "TCGE_DIST"
		buildoptions "/MD"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/".. outputdir .. "/%{prj.name}")
	objdir ("bin-int/".. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"TCGEngine2/vendor/spdlog/include",
		"TCGEngine2/src"
	}

	links
	{
		"TCGEngine2"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"TCGE_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "TCGE_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "TCGE_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "TCGE_DIST"
		buildoptions "/MD"
		optimize "On"