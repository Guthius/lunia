#include "LuniaModule.hpp"

#include <raylib.h>

namespace AllM
{
	void LuniaModule::Initialize(XRated::Framework::IApplication &application)
	{
		layerSystem = new XRated::Framework::LayerSystem("layersystem1", *system);
	}

	void LuniaModule::Run(XRated::Framework::IApplication &application)
	{
		ClearBackground(SKYBLUE);

		DrawText("Lunia Shell", 10, 10, 20, WHITE);
	}
}
