#pragma once

#include "IApplication.hpp"

namespace AllM::XRated::Framework
{
	class IModule
	{
	public:
		virtual ~IModule() = default;

		virtual void Initialize(IApplication &application) = 0;
		virtual void Run(IApplication &application) = 0;
	};
}
