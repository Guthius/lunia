#pragma once

#include <memory>
#include <AllM/XRated/Framework/Layer.hpp>

namespace AllM::XRated::Lunia::Layers
{
	class ILobby : public Framework::Layer
	{
	public:
		explicit ILobby(const std::string &name) : Layer(name)
		{
		}
	};

	std::shared_ptr<ILobby> CreateLobbyLayer(const std::string &name);
}
