#pragma once

#include <string>

namespace AllM::XRated::Framework
{
	class ILayer
	{
	public:
		virtual ~ILayer() = default;

		virtual void Initialize()
		{
		}

		virtual bool Update(float dt) = 0;
		virtual void Render() = 0;
		virtual void Inserted() = 0;
		virtual void Removed() = 0;
		virtual bool Hide() = 0;
		virtual bool Show() = 0;

		[[nodiscard]] virtual const std::string &GetName() const = 0;
	};
}
