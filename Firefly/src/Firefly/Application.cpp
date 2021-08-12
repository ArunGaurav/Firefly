#include "ffpch.h"
#include "Application.h"
#include "Firefly/Log.h"	

#include <GLFW/glfw3.h>

namespace Firefly {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
	}

	Application::~Application()
	{
		std::cout << "destructed application object!\n";
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		bool Isdispatched = dispatcher.Dispatch<WindowClose>(BIND_EVENT_FN(OnWindowClose));

		FF_CORE_TRACE("{0}", e);
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
			m_Window->OnUpdate();
		}
	}

}
