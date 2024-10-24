#pragma once

#include <string>
#include <memory>

#include "ILayer.hpp"

namespace AllM::XRated::Framework
{
	class ILayerSystem
	{
	public:
		virtual ~ILayerSystem() = default;

		virtual void Initialize()
		{
		}

		virtual void Add(const std::shared_ptr<ILayer> &layer) = 0;
		virtual void Remove(const std::string &layer_name) = 0;

		[[nodiscard]]
		virtual std::shared_ptr<ILayer> GetLayer(const std::string &layer_name) const = 0;

		[[nodiscard]]
		virtual std::shared_ptr<ILayer> GetTopVisibleLayer() const = 0;

		virtual void Update(float dt)
		{
		}

		virtual void UpdateFixed(float dt)
		{
		}

		virtual void Render()
		{
		}
	};
}
