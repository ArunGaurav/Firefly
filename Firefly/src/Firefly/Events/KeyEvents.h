#pragma once
#include "Events.h"

namespace Firefly {
	class FIREFLY_API KeyEvent : public Event
	{
	public:
		inline int GetKeyCode() const { return m_KeyCode;  }
		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)

	protected:
		KeyEvent(int Keycode)
			: m_KeyCode(Keycode)
		{}

		int m_KeyCode;
	};

	class FIREFLY_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int KeyCode, int repeatCount)
			: KeyEvent(KeyCode), m_repeatCount(repeatCount)
		{
		}

		inline int GetRepeatCount() const { return m_repeatCount; }
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_KeyCode << " (" << m_repeatCount << " repeats)";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)

	private:
		int m_repeatCount;
	};

	class FIREFLY_API KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int KeyCode)
			: KeyEvent(KeyCode)
		{
		}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyRelasedEvent: " << m_KeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};
}