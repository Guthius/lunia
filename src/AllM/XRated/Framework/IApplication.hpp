#pragma once

namespace AllM::XRated::Framework
{
	class IApplication
	{
	public:
		virtual ~IApplication() = default;

		virtual void Release() = 0;
	};
}
