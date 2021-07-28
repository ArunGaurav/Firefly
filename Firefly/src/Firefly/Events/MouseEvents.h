#pragma once
#include "Events.h"

namespace Firefly {
	class FIREFLY_API MouseMoveEvent : public Event
	{
	public:
		MouseMoveEvent(float X, float Y)
			: m_MouseX(X), m_MouseY(Y)
		{
		}

		inline float GetMouseX() const { return m_MouseX; }
		inline float GetMouseY() const { return m_MouseY; }
	    std::string ToString() const override 
		{ 
			std::stringstream ss;
			ss << "MousePosition:: " << "(" << m_MouseX << "," << m_MouseY << ")";
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	private:
		float m_MouseX, m_MouseY;
	};


	class FIREFLY_API MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(float xOffset, float yOffset)
			: m_Xoffset(xOffset), m_Yoffset(yOffset)
		{
		}

		inline float GetOffsetX() const { return m_Xoffset; }
		inline float GetOffsetY() const { return m_Yoffset; }
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrollOffset:: " << "(" << m_Xoffset << "," << m_Yoffset << ")";
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	private:
		float m_Xoffset, m_Yoffset;
	};

	
	class FIREFLY_API MouseButtonEvent : public Event
	{
	public:
		inline int GetMouseButton() const { return m_Button; }
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	protected:
		MouseButtonEvent(int button)
			: m_Button(button)
		{
		}

		int m_Button;
	};

	class FIREFLY_API MouseButtonClickedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonClickedEvent(int button)
			: MouseButtonEvent(button)
		{
		}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonClicked: " << m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MousebuttonClicked)
	};

	class FIREFLY_API MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int button)
			: MouseButtonEvent(button)
		{
		}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonReleased: " << m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MousebuttonReleased)
	};
}
