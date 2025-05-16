#pragma once

#ifdef IGN_SYS_MACOS
extern Ignition::Core::Application* Ignition::Core::CreateApplication();

int main(int argc, char** argv) {
    // Ignition::Log::Init();

    auto app = Ignition::Core::CreateApplication();
    app->Run();

    delete app;

    return 0;
}

#endif