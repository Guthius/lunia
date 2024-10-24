#pragma once

#include <AllM/XRated/Framework/IModule.hpp>
#include <AllM/XRated/Framework/LayerSystem.hpp>

namespace AllM
{
	class LuniaModule final : public XRated::Framework::IModule
	{
		XRated::Framework::LayerSystem layer_system_{};

	public:
		void Initialize(XRated::Framework::IApplication &application) override;

		void Run(XRated::Framework::IApplication &application) override;
	};
}
