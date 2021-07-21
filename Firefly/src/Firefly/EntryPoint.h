#pragma once

#ifdef FF_PLATFORM_WINDOWS

	extern Firefly::Application* Firefly::CreateApplication();

	int main()
	{
		Firefly::Log::Init();
		FF_CORE_ERROR("Engine: error");
		FF_INFO("Sandbox: info");

		Firefly::Application* app = Firefly::CreateApplication();
		app->Run();
		delete app;
	}

#endif 

