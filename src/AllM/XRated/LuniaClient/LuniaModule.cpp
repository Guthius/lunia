#include "LuniaModule.hpp"

#include <raylib.h>

#include "Layers/ILobby.hpp"

namespace AllM
{
	void LuniaModule::Initialize(XRated::Framework::IApplication &application)
	{
		const auto lobby = XRated::Lunia::Layers::CreateLobbyLayer("lobby");

		layer_system_.Add(lobby);
		layer_system_.Show("lobby");
	}

	void LuniaModule::Run(XRated::Framework::IApplication &application)
	{
		const auto dt = GetFrameTime();

		layer_system_.Update(dt);
		layer_system_.Render();
	}
}
