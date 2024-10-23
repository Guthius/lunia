#include <AllM/XRated/Framework/Application.hpp>

#include "LuniaModule.hpp"

int main()
{
	const auto module = new AllM::LuniaModule();

	AllM::XRated::Framework::Application application(module);

	application.Run();

	return 0;
}
