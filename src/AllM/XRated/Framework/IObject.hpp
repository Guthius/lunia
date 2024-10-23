#pragma once
#include "System.hpp"

namespace AllM::XRated::Framework
{
	struct IObject
	{
		virtual ~IObject() = default;

		virtual void Initialize(System &system)
		{
		}

		virtual void Update(System &, float dt)
		{
		}

		virtual void UpdateFixed(System &, float dt)
		{
		}

		virtual void Render(System &)
		{
		}
	};
}
