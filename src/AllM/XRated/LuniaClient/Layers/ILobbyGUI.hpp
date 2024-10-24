#pragma once

#include <memory>

namespace AllM::XRated::Lunia::Layers
{
	enum class PageType
	{
		PreStart,
		Contract,
		SelectServer,
		SelectCharacter,
		CreateCharacter,
		SelectSquare,
		CheckSecurityCard,
	};

	class ILobbyGUI
	{
	public:
		virtual ~ILobbyGUI() = default;

		virtual void Hide() = 0;
		virtual void Show() = 0;
		virtual void Update(float dt) = 0;
		virtual void Render() = 0;
	};

	std::unique_ptr<ILobbyGUI> CreateLobbyGUI();
}
