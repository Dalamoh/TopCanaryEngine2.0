#pragma once
#include "Core.h"
#include "Events/Event.h"
#include "TCGEngine2/Events/ApplicationEvent.h"

#include "Window.h"

namespace TCGEngine2 {

	class TCGE_API Application
	{
	public: 
		Application();
		virtual ~Application();
		void Run();


		void OnEvent(Event& event);
	private:

		bool OnWindowClose(WindowCloseEvent& event);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};


	//TO BE DEFINED IN CLIENT
	Application* CreateApplication();

}


