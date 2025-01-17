// Copyright Levi Spevakow (C) 2025

#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include <memory>

#define COLOR_GREEN "\033[1;32m"
#define COLOR_YELLOW "\033[33m"
#define COLOR_WHITE "\033[1;37m"
#define COLOR_RESET "\033[0m"

namespace Tempus {

#ifdef TPS_PLATFORM_WINDOWS
	template class TEMPUS_API std::shared_ptr<spdlog::logger>;
#endif

	class TEMPUS_API Log
	{

	public:

		Log();
		~Log();

		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:

		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};

}

// Core log macros
#define TPS_CORE_TRACE(...)      ::Tempus::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define TPS_CORE_INFO(...)       ::Tempus::Log::GetCoreLogger()->info(__VA_ARGS__)
#define TPS_CORE_WARN(...)       ::Tempus::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define TPS_CORE_ERROR(...)      ::Tempus::Log::GetCoreLogger()->error(__VA_ARGS__)
#define TPS_CORE_CRITICAL(...)   ::Tempus::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define TPS_TRACE(...)           ::Tempus::Log::GetClientLogger()->trace(__VA_ARGS__)
#define TPS_INFO(...)            ::Tempus::Log::GetClientLogger()->info(__VA_ARGS__)
#define TPS_WARN(...)            ::Tempus::Log::GetClientLogger()->warn(__VA_ARGS__)
#define TPS_ERROR(...)           ::Tempus::Log::GetClientLogger()->error(__VA_ARGS__)
#define TPS_CRITICAL(...)        ::Tempus::Log::GetClientLogger()->critical(__VA_ARGS__)

