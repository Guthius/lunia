#include <AllM/XRated/Framework/Application.hpp>

#include "LuniaModule.hpp"
#include <Windows.h>

int main()
{
	const auto module = new AllM::LuniaModule();

	try
	{
		AllM::XRated::Framework::Application application(module);

		application.Run();
	}
	catch (std::exception &e)
	{
		MessageBoxA(nullptr, e.what(), "Error", MB_OK | MB_ICONERROR);

		return 1;
	}

	return 0;
}
