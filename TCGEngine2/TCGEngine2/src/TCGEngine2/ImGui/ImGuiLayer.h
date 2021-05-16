#pragma once

#include "TCGEngine2/Layer.h"

namespace TCGEngine2 
{

	class TCGE_API ImGuiLayer : public Layer
	{
	
	public:
		ImGuiLayer();
		~ImGuiLayer();


		void OnAttach();
		void OnDetach();
		void OnUpdate();
		void OnEvent(Event& event);

	private:
		float m_Time = 0.0f;

	
	};

}