#pragma once

#include <AllM/XRated/Framework/IModule.hpp>

namespace AllM
{
	class LuniaModule final : public XRated::Framework::IModule
	{
	public:
		void Initialize(XRated::Framework::IApplication &system) override;

		void Run(XRated::Framework::IApplication &system) override;
	};
}
