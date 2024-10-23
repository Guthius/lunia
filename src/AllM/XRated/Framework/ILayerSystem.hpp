#pragma once

#include <string>

#include "ILayer.hpp"
#include "IObject.hpp"

namespace AllM::XRated::Framework
{
	class ILayerSystem : public IObject
	{
	public:
		virtual void Create(const std::string &type, const std::string &name) = 0;
		virtual void Delete(const std::string &layer) = 0;
		virtual void AddLayer(ILayer *layer) = 0;
		virtual ILayer *GetLayer(const std::string &layer) = 0;
		virtual ILayer *GetTopVisibleLayer() = 0;
	};
}
