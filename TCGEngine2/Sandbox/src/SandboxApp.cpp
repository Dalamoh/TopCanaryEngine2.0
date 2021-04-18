#include <TCGEngine2.h>

class Sandbox : public TCGEngine2::Application {

public:
	Sandbox() 
	{

	}
	~Sandbox()
	{

	}


};

TCGEngine2::Application* TCGEngine2::CreateApplication() {
	return new Sandbox;
}