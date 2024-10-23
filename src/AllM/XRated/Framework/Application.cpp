#include "Application.hpp"

#include <raylib.h>

namespace AllM::XRated::Framework
{
	void Application::Run()
	{
		InitWindow(1280, 720, "Lunia");

		SetTargetFPS(60);

		while (!WindowShouldClose())
		{
			BeginDrawing();

			module_->Run(*this);

			EndDrawing();
		}

		CloseWindow();
	}
}
