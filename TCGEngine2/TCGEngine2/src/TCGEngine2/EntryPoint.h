#pragma once

#ifdef TCGE_PLATFORM_WINDOWS

extern TCGEngine2::Application* TCGEngine2::CreateApplication();

int main(int argc, char** argv) {

	TCGEngine2::Log::Init();
	TCGE_CORE_WARN("Initialized Log!");
	int a = 5;
	TCGE_CORE_INFO("Hello! Var={0}", a);

	auto app = TCGEngine2::CreateApplication();
	app->Run();
	delete app;
}

#endif