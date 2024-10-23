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

		virtual void Update(System &system, float dt)
		{
		}

		virtual void UpdateFixed(System &system, float dt)
		{
		}

		virtual void Render(System &system)
		{
		}
	};
}
