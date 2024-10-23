#pragma once

#include "ILayerSystem.hpp"

#include <map>
#include <list>
#include <ranges>

#include "LayerFactory.hpp"

namespace AllM::XRated::Framework
{
	class LayerSystem final : public ILayerSystem
	{
		struct Layers
		{
			std::list<ILayer *> Visible;
			std::map<std::string, ILayer *> Map;
		};

		Layers layers_;
		System &system_;

		void AddVisibleLayer(ILayer *layer)
		{
			layers_.Visible.remove(layer);
			layers_.Visible.push_back(layer);

			layer->Inserted();
		}

		void RemoveVisibleLayer(ILayer *layer)
		{
			layers_.Visible.remove(layer);

			layer->Removed();
		}

		[[nodiscard]] bool Exists(const std::string &name) const
		{
			return layers_.Map.contains(name);
		}

	public:
		LayerSystem(const std::string &name, System &system) : system_(system)
		{
		}

		~LayerSystem() override
		{
			// TODO: XScript::XScriptSystemInstance().UnregisterInstance(this);

			for (const auto &layer: layers_.Map | std::views::values)
			{
				layer->Free();
			}
		}

		void Show(const std::string &layer)
		{
			if (!Exists(layer))
			{
				// TODO: ALLM_ERROR(("layer not found, %s", layer.c_str()));
				return;
			}

			if (!layers_.Map[layer]->Show())
			{
				AddVisibleLayer(layers_.Map[layer]);
			}
		}

		void Hide(const std::string &layer)
		{
			if (!Exists(layer))
			{
				// TODO: ALLM_ERROR(("layer not found, %s", layer.c_str()));
				return;
			}

			if (!layers_.Map[layer]->Hide())
			{
				Remove(layer);
			}
		}

		void Remove(const std::string &layer)
		{
			if (!Exists(layer))
			{
				// TODO: ALLM_ERROR(("layer not found, %s", layer.c_str()));
				return;
			}

			RemoveVisibleLayer(layers_.Map[layer]);
		}

		void Create(const std::string &type, const std::string &name) override
		{
			if (Exists(name))
			{
				// TODO: ALLM_ERROR(("layer already exists with name %s", name.c_str()));
				return;
			}

			AddLayer(GetLayerFactoryInstance().Create(type, name));
		}

		void Delete(const std::string &layer) override
		{
			if (!Exists(layer))
			{
				// TODO: ALLM_ERROR(("layer not found, %s", layer.c_str()));
				return;
			}

			Remove(layer);

			layers_.Map[layer]->Free();
			layers_.Map.erase(layer);
		}

		void AddLayer(ILayer *layer) override
		{
			layers_.Map[layer->GetName()] = layer;

			layer->Initialize(system_);
		}

		ILayer *GetLayer(const std::string &layer) override
		{
			if (!Exists(layer))
			{
				// TODO: ALLM_ERROR(("layer not found, %s", layer.c_str()));
				return nullptr;
			}

			return layers_.Map[layer];
		}

		ILayer *GetTopVisibleLayer() override
		{
			if (!layers_.Visible.empty())
			{
				return layers_.Visible.back();
			}

			return nullptr;
		}

		void Update(System &system, const float dt) override
		{
			// for (System::Types::ActionIn::iterator i = system.action.in->begin(); i != system.action.in->end(); ++i)
			// {
			// 	//ALLM_INFO(("Action: %s",(*i).command.c_str()));
			// 	if ((*i).command == "xscript")
			// 	{
			// 		XScript::XScriptSystemInstance().Execute((*i).parameters, XScript::IScriptSystem::ExecutionMode::Immediate);
			// 	}
			// }

			for (const auto &layer: std::ranges::reverse_view(layers_.Visible))
			{
				if (layer->Update(system, dt))
				{
					break; // Layers can be exclusive
				}
			}
		}

		void Render(System &system) override
		{
			//					system.graphics.render->RenderDebugText(100,100,"hello world");
			for (const auto &layer: layers_.Visible)
			{
				layer->Render(system);
			}
		}
	};
}
