#pragma once
#include "Core.h"
#include "Events/Events.h"
#include "Firefly/Events/ApplicationEvents.h"

#include "Window.h"

class Window;
namespace Firefly {

	class FIREFLY_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
		void OnEvent(Event& e);

	private:
		bool OnWindowClose(WindowClose& close);
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	Application* CreateApplication();

}
