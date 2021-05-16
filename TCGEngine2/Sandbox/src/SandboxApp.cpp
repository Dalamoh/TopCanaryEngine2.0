#include <TCGEngine2.h>

class TestLayer : public TCGEngine2::Layer
{

public:
	TestLayer()
		:Layer("Test")
	{
	}

	void OnUpdate() override
	{
	
		TCGE_INFO("TestLayer -> OnUpdate");
	
	}

	void OnEvent(TCGEngine2::Event& event) override
	{
	
		TCGE_TRACE("{0}", event);

	}
};


class Sandbox : public TCGEngine2::Application {

public:
	Sandbox() 
	{
		PushLayer(new TestLayer());

		PushOverlay(new TCGEngine2::ImGuiLayer());
	}
	~Sandbox()
	{

	}


};

TCGEngine2::Application* TCGEngine2::CreateApplication() {
	return new Sandbox;
}