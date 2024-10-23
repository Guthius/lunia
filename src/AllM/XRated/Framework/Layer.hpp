#pragma once

#include <utility>

#include "ILayer.hpp"

namespace AllM::XRated::Framework
{
	class Layer : public ILayer
	{
		std::string name_;

	protected:
		virtual void Init(System &system)
		{
		}

		enum class State
		{
			Showing,
			Visible,
			Hiding,
			Hidden
		};

		State state_{State::Hidden};
		bool initialized_{false};

	public:
		explicit Layer(std::string name) : name_(std::move(name))
		{
		}

		void Initialize(System &system) override
		{
			if (!initialized_)
			{
				Init(system);

				initialized_ = true;
			}
		}

		bool Update(System &system, float dt) override
		{
			return false;
		}

		void Render(System &system) override
		{
		}

		void Inserted() override
		{
			state_ = State::Visible;
		}

		void Removed() override
		{
			state_ = State::Hidden;
		}

		bool Hide() override
		{
			state_ = State::Hiding;
			return false;
		}

		bool Show() override
		{
			state_ = State::Showing;
			return false;
		}

		[[nodiscard]] const std::string &GetName() const override
		{
			return name_;
		}
	};
}
