#pragma once
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Firefly {
	class FIREFLY_API Log
	{
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	public:
		static void Init();
		static inline std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		static inline std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	};
}

//core logging
#define FF_CORE_TRACE(...)   ::Firefly::Log::GetCoreLogger()->trace(__VA_ARGS__);
#define FF_CORE_INFO(...)    ::Firefly::Log::GetCoreLogger()->info(__VA_ARGS__);
#define FF_CORE_WARN(...)    ::Firefly::Log::GetCoreLogger()->warn(__VA_ARGS__);
#define FF_CORE_ERROR(...)   ::Firefly::Log::GetCoreLogger()->error(__VA_ARGS__);
#define FF_CORE_FATAL(...)   ::Firefly::Log::GetCoreLogger()->fatal(__VA_ARGS__);

//client logging
#define FF_TRACE(...)    ::Firefly::Log::GetClientLogger()->trace(__VA_ARGS__);
#define FF_INFO(...)     ::Firefly::Log::GetClientLogger()->info(__VA_ARGS__);
#define FF_WARN(...)     ::Firefly::Log::GetClientLogger()->warn(__VA_ARGS__);
#define FF_ERROR(...)    ::Firefly::Log::GetClientLogger()->error(__VA_ARGS__);
#define FF_FATAL(...)    ::Firefly::Log::GetClientLogger()->fatal(__VA_ARGS__);