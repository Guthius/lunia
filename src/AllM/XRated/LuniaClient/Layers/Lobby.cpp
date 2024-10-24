#include "ILobby.hpp"

#include <raylib.h>

namespace AllM::XRated::Lunia::Layers
{
	class Lobby final : public ILobby
	{
	public:
		explicit Lobby(const std::string &name): ILobby(name)
		{
		}

		void Render() override
		{
			ClearBackground(SKYBLUE);

			DrawText("Lunia Shell", 10, 10, 20, WHITE);
		}
	};

	std::shared_ptr<ILobby> CreateLobbyLayer(const std::string &name)
	{
		return std::make_shared<Lobby>(name);
	}
}
