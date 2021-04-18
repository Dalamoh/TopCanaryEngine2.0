#pragma once


#ifdef TCGE_PLATFORM_WINDOWS
	#ifdef TCGE_BUILD_DLL
		#define TCGE_API __declspec(dllexport)
	#else
		#define TCGE_API __declspec(dllimport)
	#endif 
#else
	#error TCGE only supports Windows!

#endif