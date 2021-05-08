#include "TCGEpch.h"
#include "Application.h"

#include "TCGEngine2/Events/ApplicationEvent.h"
#include "TCGEngine2/Log.h"

namespace TCGEngine2 {

	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run() {
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			TCGE_TRACE(e);
		}

		if (e.IsInCategory(EventCategoryInput))
		{
			TCGE_TRACE(e);
		}

		while (true);
	}
}
