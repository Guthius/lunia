#pragma once

#include <string>

#include "System.hpp"

namespace AllM::XRated::Framework
{
	class ILayer
	{
	public:
		virtual ~ILayer() = default;

		virtual void Initialize(System &system) = 0;
		virtual bool Update(System &system, float dt) = 0;
		virtual void Render(System &system) = 0;
		virtual void Inserted() = 0;
		virtual void Removed() = 0;
		virtual bool Hide() = 0;
		virtual bool Show() = 0;

		[[nodiscard]] virtual const std::string &GetName() const = 0;
	};
}
