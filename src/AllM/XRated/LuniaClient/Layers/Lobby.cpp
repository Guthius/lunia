#include "ILobby.hpp"

#include <raylib.h>

#include "ILobbyGUI.hpp"

namespace AllM::XRated::Lunia::Layers
{
	class Lobby final : public ILobby
	{
		std::unique_ptr<ILobbyGUI> gui_;

	public:
		explicit Lobby(const std::string &name): ILobby(name)
		{
			gui_ = CreateLobbyGUI();
		}

		bool Update(const float dt) override
		{
			gui_->Update(dt);

			return false;
		}

		void Render() override
		{
			ClearBackground(SKYBLUE);

			gui_->Render();
		}
	};

	std::shared_ptr<ILobby> CreateLobbyLayer(const std::string &name)
	{
		return std::make_shared<Lobby>(name);
	}
}
