#include "LuniaModule.hpp"

#include <raylib.h>

#include "Layers/ILobby.hpp"

namespace AllM
{
	void LuniaModule::Initialize(XRated::Framework::IApplication &application)
	{
		system_ = new XRated::Framework::System();

		const auto lobby = XRated::Lunia::Layers::CreateLobbyLayer("lobby", *system_);

		layer_system_ = new XRated::Framework::LayerSystem(*system_);
		layer_system_->Add(lobby);
		layer_system_->Show("lobby");
	}

	void LuniaModule::Run(XRated::Framework::IApplication &application)
	{
		const auto dt = GetFrameTime();

		layer_system_->Update(*system_, dt);
		layer_system_->Render(*system_);
	}
}
