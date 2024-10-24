#include "ILobbyGUI.hpp"

#include <raylib.h>

namespace AllM::XRated::Lunia::Layers
{
	class LobbyGUI final : public ILobbyGUI
	{
	public:
		void Hide() override
		{
		}

		void Show() override
		{
		}

		void Update(float dt) override
		{
		}

		void Render() override
		{
			DrawText("Lunia Shell", 10, 10, 20, WHITE);
		}
	};

	std::unique_ptr<ILobbyGUI> CreateLobbyGUI()
	{
		return std::make_unique<LobbyGUI>();
	}
}
