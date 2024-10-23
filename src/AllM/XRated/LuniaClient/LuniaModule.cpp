#include "LuniaModule.hpp"

#include <raylib.h>

namespace AllM
{
	void LuniaModule::Initialize(XRated::Framework::IApplication &system)
	{
	}

	void LuniaModule::Run(XRated::Framework::IApplication &system)
	{
		ClearBackground(SKYBLUE);

		DrawText("Lunia Shell", 10, 10, 20, WHITE);
	}
}
