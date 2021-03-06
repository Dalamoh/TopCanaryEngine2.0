#include "TCGEpch.h"
#include "Application.h"

#include "TCGEngine2/Log.h"

#include <glad/glad.h>

namespace TCGEngine2 {


#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)

	Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		TCGE_CORE_ASSERT(s_Instance, "App already exists.")
		s_Instance = this;
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));
	}

	Application::~Application()
	{
	}

	void Application::PushLayer(Layer * layer) 
	{

		m_LayerStack.PushLayer(layer);
		layer->OnAttach();

	}

	void Application::PushOverlay(Layer * overlay)
	{

		m_LayerStack.PushOverlay(overlay);
		overlay->OnAttach();

	}



	void Application::Run() {

		while (m_Running) 
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			
		
			for (Layer* layer : m_LayerStack)
				layer->OnUpdate();
			m_Window->OnUpdate();
		}
	}
	void Application::OnEvent(Event& event)
	{
		EventDispatcher dispatcher(event);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowClose));

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();)
		{

			(*--it)->OnEvent(event);
			if (event.Handled)
				break;

		}

	}
	bool Application::OnWindowClose(WindowCloseEvent & event)
	{
		m_Running = false;
		return true;
	}
}
