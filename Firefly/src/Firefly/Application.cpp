#include "Application.h"
#include <iostream>

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
		while (true);
	}
}
