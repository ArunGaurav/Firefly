#pragma once
#include "Core.h"
#include "Events/Events.h"

namespace Firefly {
	class FIREFLY_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();
}
