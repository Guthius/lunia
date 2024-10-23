#pragma once

#include <string>
#include <memory>

#include "ILayer.hpp"
#include "IObject.hpp"

namespace AllM::XRated::Framework
{
	class ILayerSystem : public IObject
	{
	public:
		virtual void Add(const std::shared_ptr<ILayer> &layer) = 0;
		virtual void Remove(const std::string &layer_name) = 0;

		[[nodiscard]]
		virtual const std::shared_ptr<ILayer> GetLayer(const std::string &layer_name) const = 0;

		[[nodiscard]]
		virtual const std::shared_ptr<ILayer> GetTopVisibleLayer() const = 0;
	};
}
