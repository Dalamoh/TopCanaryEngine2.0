#pragma once
#include "Core.h"

#include "Window.h"
#include "TCGEngine2/LayerStack.h"
#include "Events/Event.h"
#include "TCGEngine2/Events/ApplicationEvent.h"



namespace TCGEngine2 {

	class TCGE_API Application
	{
	public: 
		Application();
		virtual ~Application();
		void Run();


		void OnEvent(Event& event);

		void PushLayer(Layer * layer);
		void PushOverlay(Layer * overlay);

		inline static Application& Get() { return *s_Instance; };
		inline Window& GetWindow() { return *m_Window; };
	private:

		bool OnWindowClose(WindowCloseEvent& event);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;

		LayerStack m_LayerStack;
		static Application* s_Instance;
	};


	//TO BE DEFINED IN CLIENT
	Application* CreateApplication();

}


