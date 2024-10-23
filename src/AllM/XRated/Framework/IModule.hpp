#pragma once

#include "IApplication.hpp"

namespace AllM::XRated::Framework
{
	class IModule
	{
	public:
		virtual ~IModule() = default;

		virtual void Initialize(IApplication &system) = 0;
		virtual void Run(IApplication &system) = 0;
	};
}
