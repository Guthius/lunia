#include "ILobby.hpp"

#include <raylib.h>

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

		void Render(Framework::System &system) override
		{
			ClearBackground(SKYBLUE);

			DrawText("Lunia Shell", 10, 10, 20, WHITE);
		}
	};

	std::shared_ptr<ILobby> CreateLobbyLayer(const std::string &name, Framework::System &system)
	{
		return std::make_shared<Lobby>(name, system);
	}
}
