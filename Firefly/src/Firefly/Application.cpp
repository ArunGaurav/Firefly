#include "ffpch.h"
#include "Application.h"
#include "Firefly/Log.h"	

#include <glad/glad.h>

namespace Firefly {

	Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		FF_CORE_ASSERT(!s_Instance, "Application already created!");
		Application::s_Instance = this;
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(FF_BIND_EVENT_FN(Application::OnEvent));
	}

	Application::~Application()
	{
		std::cout << "destructed application object!\n";
	}

	void Application::PushLayer(Layer* layer)
	{
		m_Layerstack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* overlay)
	{
		m_Layerstack.PushOverlay(overlay);
		overlay->OnAttach();
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		bool Isdispatched = dispatcher.Dispatch<WindowClose>(FF_BIND_EVENT_FN(Application::OnWindowClose));

		//FF_CORE_TRACE("{0}", e);
		for (auto it = m_Layerstack.end(); it != m_Layerstack.begin(); )
		{
			(*--it)->OnEvent(e);
			if (e.m_Handled)
				break;
		}
	}

	bool Application::OnWindowClose(WindowClose& close)
	{
		m_Running = false;
		return true;
	}

	void Application::Run()
	{
		while (m_Running)
		{
			glClearColor(1.0, 1.0, 0.0, 1.0);
			glClear(GL_COLOR_BUFFER_BIT);

			for (Layer* layer : m_Layerstack)
				layer->OnUpdate();

			m_Window->OnUpdate();
		}
	}

}
