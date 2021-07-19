#pragma once
#include "Application.h"

extern Firefly::Application* Firefly::CreateApplication();

int main()
{
	Firefly::Application* app = Firefly::CreateApplication();
	app->Run();
	delete app;
}
