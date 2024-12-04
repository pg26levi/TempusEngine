// Copyright Levi Spevakow (C) 2024

#include "Application.h"
#include <iostream>
#include <thread>

namespace Tempus {

	Tempus::Application::Application()
	{
		
	}

	Tempus::Application::~Application()
	{
	}

	void Application::Run()
	{
		std::cout << "Hello World!" << std::endl;

		SDL_SetMainReady();

		SDL_Init(SDL_INIT_VIDEO);

		SDL_LogSetAllPriority(SDL_LOG_PRIORITY_VERBOSE);

		m_Window = SDL_CreateWindow("Cool Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080, 0);

		SDL_Renderer* renderer = SDL_CreateRenderer(m_Window, -1, 0);

		SDL_SetRenderDrawColor(renderer, 19, 61, 102, 255);

		SDL_Event event;

		while (true) {
			SDL_RenderClear(renderer);
			SDL_RenderPresent(renderer);

			SDL_PollEvent(&event);

			if (event.type == SDL_QUIT) {
				break;
			}
			std::cout << "Number of threads: " << std::thread::hardware_concurrency() << std::endl;
		}

	}


}

