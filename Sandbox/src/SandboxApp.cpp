#include <Firefly.h>

class ExampleLayer : public Firefly::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{

	}

	void OnUpdate() override
	{
		//FF_INFO("Example layer updating!");
	}

	void OnEvent(Firefly::Event& e) override
	{
		if (e.GetEventType() == Firefly::EventType::KeyPressed)
		{
			Firefly::KeyPressedEvent& event = (Firefly::KeyPressedEvent&)e;
			if (event.GetKeyCode() == FF_KEY_SPACE)
			{
				FF_WARN("Spacebar pressed! (Input Poll)");
				FF_TRACE("Spacebar pressed! (Event)");
			}

			FF_ERROR("{0}", (char)event.GetKeyCode());
		}
	}
};

class Sandbox : public Firefly::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer);
		PushLayer(new Firefly::ImGuiLayer);
	}

	~Sandbox()
	{

	}
};

Firefly::Application* Firefly::CreateApplication()
{
	return new Sandbox();
}