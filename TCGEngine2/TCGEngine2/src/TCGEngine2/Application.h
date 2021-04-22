#pragma once
#include "Core.h"
#include "Events/Event.h"

namespace TCGEngine2 {

	class TCGE_API Application
	{
	public: 
		Application();
		virtual ~Application();
		void Run();
	};


	//TO BE DEFINED IN CLIENT
	Application* CreateApplication();

}


