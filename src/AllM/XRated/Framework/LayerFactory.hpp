#pragma once

#include <string>

#include "Layer.hpp"

namespace AllM::XRated::Framework
{
	class ILayerFactory
	{
	public:
		virtual ~ILayerFactory() = default;

		typedef Layer *(*Function)(const std::string &name);

		virtual void Register(const std::string &type, Function f) = 0;
		virtual Layer *Create(const std::string &type, const std::string &name) = 0;
	};

	ILayerFactory &GetLayerFactoryInstance();
}
