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

#ifdef TCGE_ENABLE_ASSERTS
	#define TCGE_ASSERT(x, ...) {if (!(x)) { TCGE_ERROR("ASSERTION FAILED: {0}", __VA_ARGS__); __debugbreak(); } }
	#define TCGE_CORE_ASSERT(x, ...) {if (!(x)) { TCGE_CORE_ERROR("ASSERTION FAILED: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define TCGE_ASSERT(x,...)
	#define TCGE_CORE_ASSERT(x,...)
#endif // TCGE_ENABLE_ASSERTS


#define BIT(x) (1 << x)