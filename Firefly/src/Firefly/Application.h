#pragma once
#include "Core.h"
#include "Events/Events.h"
#include "Firefly/Events/ApplicationEvents.h"
#include "Firefly/LayerStack.h"
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

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		inline Window& GetWindow() const { return *m_Window; }
		inline static Application& Get() { return *s_Instance;  }

	private:
		LayerStack m_Layerstack;
		bool OnWindowClose(WindowClose& close);
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;

		static Application* s_Instance;
	};

	Application* CreateApplication();

}
