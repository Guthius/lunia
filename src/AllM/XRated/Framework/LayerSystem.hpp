#pragma once

#include <list>
#include <map>
#include <ranges>

#include "ILayerSystem.hpp"

namespace AllM::XRated::Framework
{
	class LayerSystem final : public ILayerSystem
	{
		std::list<std::shared_ptr<ILayer> > visible_;
		std::map<std::string, std::shared_ptr<ILayer> > map_;
		System &system_;

		void AddVisible(const std::shared_ptr<ILayer> &layer)
		{
			visible_.remove(layer);
			visible_.push_back(layer);

			layer->Inserted();
		}

		[[nodiscard]] bool Exists(const std::string &name) const
		{
			return map_.contains(name);
		}

	public:
		explicit LayerSystem(System &system) : system_(system)
		{
		}

		void Show(const std::string &layer_name)
		{
			const auto iter = map_.find(layer_name);
			if (iter == map_.end())
			{
				return;
			}

			if (const auto &layer = iter->second; layer->Show())
			{
				visible_.remove(layer);
				visible_.push_back(layer);

				layer->Inserted();
			}
		}

		void Hide(const std::string &layer_name)
		{
			const auto iter = map_.find(layer_name);
			if (iter == map_.end())
			{
				return;
			}

			if (const auto &layer = iter->second; !layer->Hide())
			{
				Remove(layer_name);
			}
		}

		void Add(const std::shared_ptr<ILayer> &layer) override
		{
			map_[layer->GetName()] = layer;

			layer->Initialize(system_);
		}

		void Remove(const std::string &layer_name) override
		{
			const auto iter = map_.find(layer_name);
			if (iter == map_.end())
			{
				return;
			}

			const auto &layer = iter->second;

			visible_.remove(layer);

			layer->Removed();

			map_.erase(iter);
		}

		[[nodiscard]] const std::shared_ptr<ILayer> GetLayer(const std::string &layer_name) const override
		{
			const auto iter = map_.find(layer_name);
			if (iter == map_.end())
			{
				return nullptr;
			}

			return iter->second;
		}

		[[nodiscard]] const std::shared_ptr<ILayer> GetTopVisibleLayer() const override
		{
			if (!visible_.empty())
			{
				return visible_.back();
			}

			return nullptr;
		}

		void Update(System &system, const float dt) override
		{
			for (const auto &layer: std::ranges::reverse_view(visible_))
			{
				if (layer->Update(system, dt))
				{
					break; // Layers can be exclusive
				}
			}
		}

		void Render(System &system) override
		{
			for (const auto &layer: visible_)
			{
				layer->Render(system);
			}
		}
	};
}
