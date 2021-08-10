#include "ffpch.h"
#include "Application.h"
#include "Firefly/Log.h"	
#include "Firefly/Events/ApplicationEvents.h"

#include <GLFW/glfw3.h>

namespace Firefly {

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{
		std::cout << "destructed application object!\n";
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
