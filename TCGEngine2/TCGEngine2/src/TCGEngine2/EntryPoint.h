#pragma once

#ifdef TCGE_PLATFORM_WINDOWS

extern TCGEngine2::Application* TCGEngine2::CreateApplication();

int main(int argc, char** argv) {
	auto app = TCGEngine2::CreateApplication();
	app->Run();
	delete app;
}

#endif