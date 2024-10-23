#include "LayerFactory.hpp"

#include <format>
#include <map>
#include <stdexcept>

namespace AllM::XRated::Framework
{
	class LayerFactory final : public ILayerFactory
	{
		std::map<std::string, Function> map_;

	public:
		void Register(const std::string &type, Function f) override
		{
			map_[type] = f;
		}

		Layer *Create(const std::string &type, const std::string &name) override
		{
			if (const auto iter = map_.find(type); iter != map_.end())
			{
				return iter->second(name);
			}

			throw std::runtime_error(std::format("LayerFactory::Create: Unknown type '{}'", type));
		}
	};

	ILayerFactory &GetLayerFactoryInstance()
	{
		static LayerFactory layer_factory;

		return layer_factory;
	}
}
