#pragma once

#include "TCGEngine2/Core.h"
#include "TCGEngine2/Events/Event.h"

namespace TCGEngine2 {

	class TCGE_API Layer
	{

	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnEvent(Event& event) {}

		inline const std::string& GetName() const { return m_DebugName; }

	protected:
		std::string m_DebugName;

	};

}



