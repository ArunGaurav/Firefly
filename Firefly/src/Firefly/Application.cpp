#include "Application.h"
#include "stdio.h"

namespace Firefly {
	Application::Application()
	{

	}

	Application::~Application()
	{
		printf("destructed application object!");
	}

	void Application::Run()
	{
		while (true);
	}
}
