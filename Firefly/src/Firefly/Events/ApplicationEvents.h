#pragma once
#include "Events.h"
#include <sstream>

namespace Firefly {
	class FIREFLY_API WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(int width, int height)
			: m_Width(width), m_Height(height)
		{
		}

		inline unsigned int GetWidth() const { return m_Width; }
		inline unsigned int GetHeight() const { return m_Height; }
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowResized: " << m_Width << ", " << m_Height;
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)

	private:
		unsigned int m_Width, m_Height;
	};

	class FIREFLY_API WindowClose : public Event
	{
	public:
		WindowClose() {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Window Closed!:";
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class FIREFLY_API ApptickEvent : public Event
	{
	public:
		ApptickEvent() {}

		EVENT_CLASS_TYPE(Apptick)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class FIREFLY_API AppUpdateEvent : public Event
	{
	public:
		AppUpdateEvent() {}

		EVENT_CLASS_TYPE(AppUpdate)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class FIREFLY_API AppRenderEvent : public Event
	{
	public:
		AppRenderEvent() {}

		EVENT_CLASS_TYPE(AppRender)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};
}
