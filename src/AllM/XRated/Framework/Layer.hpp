#pragma once

#include <utility>

#include "ILayer.hpp"

namespace AllM::XRated::Framework
{
	class Layer : public ILayer
	{
		std::string name_;

	protected:
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

		bool Update(float dt) override
		{
			return false;
		}

		void Render() override
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
			return true;
		}

		bool Show() override
		{
			state_ = State::Showing;
			return true;
		}

		[[nodiscard]] const std::string &GetName() const override
		{
			return name_;
		}
	};
}
