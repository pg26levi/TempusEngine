// Copyright Levi Spevakow (C) 2025

#pragma once

#include "Core.h"

#include "vulkan/vulkan.h"
#define SDL_MAIN_HANDLED
#include "sdl/SDL.h"

namespace Tempus {

	class TEMPUS_API Application
	{
	public:

		Application();
		virtual ~Application();
		void Run();

	protected:

		virtual void Update();
		virtual void Cleanup();

		SDL_Event GetCurrentEvent() const { return CurrentEvent; }

		void SetRenderColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);

	private:

		bool InitWindow();
		bool InitRenderer();
		bool InitSDL();

		void CoreUpdate();

	private:

		VkInstance m_Instance = nullptr;
		class Window* m_Window = nullptr;
		class Renderer* m_Renderer = nullptr;

		bool bShouldQuit = false;

		SDL_Event CurrentEvent;

	};

	Application* CreateApplication();

}

