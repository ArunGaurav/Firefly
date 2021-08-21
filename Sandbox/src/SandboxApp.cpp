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
		FF_INFO("Example layer updating!");
	}

	void OnEvent(Firefly::Event& e) override
	{
		FF_TRACE(e);
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