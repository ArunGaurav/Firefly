#include "ffpch.h"
#include "Application.h"
#include "Firefly/Log.h"	
#include "Firefly/Events/ApplicationEvents.h"

namespace Firefly {
	Application::Application()
	{
	}

	Application::~Application()
	{
		std::cout << "destructed application object!\n";
	}

	void Application::Run()
	{
		WindowClose close;
		WindowResizeEvent R(1920, 1080);
		FF_CORE_TRACE(R);
		FF_CORE_WARN(close.ToString());
		while (true);
	}
}
