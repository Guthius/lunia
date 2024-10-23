#include "ILobby.hpp"

namespace AllM::XRated::Lunia::Layers
{
	class Lobby final : public ILobby
	{
		Framework::System &system_;

	public:
		Lobby(const std::string &name, Framework::System &system)
			: ILobby(name), system_(system)
		{
		}
	};

	std::shared_ptr<ILobby> CreateLobbyLayer(const std::string &name, Framework::System &system)
	{
		return std::make_shared<Lobby>(name, system);
	}
}
