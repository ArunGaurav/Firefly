#pragma once
#include "Firefly/Core.h"

#include <string>
#include <functional>

namespace Firefly {
	// events currently are blocking, which means they'll be dispatched immediately when the events occur
	// in the future, buffer events in an event bus, where we can process the events later

	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		Apptick, AppUpdate, AppRender,
		KeyPressed, KeyReleased,
		MousebuttonClicked, MousebuttonReleased, MouseMoved, MouseScrolled
	};

	enum EventCategory
	{
		None = 0,
		EventCategoryApplication = BIT(0),
		EventCategoryInput = BIT(1),
		EventCategoryKeyboard = BIT(2),
		EventCategoryMouse = BIT(3)
	};

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() {return EventType::##type;}\
	virtual EventType GetEventType() const override { return GetStaticType();}\
	virtual const char* GetEventName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

	class FIREFLY_API Event
	{
		friend class EventDispatcher;
	public:
		virtual EventType GetEventType() const = 0;
		virtual const char* GetEventName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetEventName(); }

		inline bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}

	protected:
		bool m_Handled = false;
	};


	class FIREFLY_API EventDispatcher
	{
		template<typename T>
		using EventFn = std::function<bool(T&)>;

	public:
		EventDispatcher(Event& event)
			: m_Event(event)
		{
		}

		template<typename T>
		bool Dispatch(EventFn<T> func)
		{
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				m_Event.m_Handled = func(*(T*)&m_Event);
				return true;
			}
			return false;
		}

	private:
		Event& m_Event;
	};


	inline std::ostream& operator<<(std::ostream& stream, const Event& e)
	{
		return stream << e.ToString();
	}
}