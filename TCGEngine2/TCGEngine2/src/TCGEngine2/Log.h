#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"



namespace TCGEngine2 {

	class TCGE_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define TCGE_CORE_TRACE(...) ::TCGEngine2::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define TCGE_CORE_INFO(...)  ::TCGEngine2::Log::GetCoreLogger()->info(__VA_ARGS__)
#define TCGE_CORE_WARN(...)  ::TCGEngine2::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define TCGE_CORE_ERROR(...) ::TCGEngine2::Log::GetCoreLogger()->error(__VA_ARGS__)
#define TCGE_CORE_FATAL(...) ::TCGEngine2::Log::GetCoreLogger()->fatal(__VA_ARGS__)


// Client log macros
#define TCGE_CLIENT_TRACE(...) ::TCGEngine2::Log::GetClientLogger()->trace(__VA_ARGS__)
#define TCGE_CLIENT_INFO(...)  ::TCGEngine2::Log::GetClientLogger()->info(__VA_ARGS__)
#define TCGE_CLIENT_WARN(...)  ::TCGEngine2::Log::GetClientLogger()->warn(__VA_ARGS__)
#define TCGE_CLIENT_ERROR(...) ::TCGEngine2::Log::GetClientLogger()->error(__VA_ARGS__)
#define TCGE_CLIENT_FATAL(...) ::TCGEngine2::Log::GetClientLogger()->fatal(__VA_ARGS__)