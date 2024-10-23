#pragma once

#include "IApplication.hpp"
#include "IModule.hpp"

namespace AllM::XRated::Framework
{
	class Application : public IApplication
	{
		IModule *module_;

	public:
		explicit Application(IModule *module) : module_(module)
		{
			module->Initialize(*this);
		}

		~Application() override
		{
			Application::Release();
		}

		void Release() override
		{
		}

		void Run();
	};
}
