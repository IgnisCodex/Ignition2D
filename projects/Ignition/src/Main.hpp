#pragma once

#ifdef IG_SYS_MACOS
extern Ignition::Engine::Core::Application* Ignition::Engine::Core::CreateApplication();

int main(int argc, char** argv) {
    Ignition::Engine::Log::Init();

    auto app = Ignition::Engine::Core::CreateApplication();
    app->Run();

    delete app;

    return 0;
}

#endif

#ifdef IG_SYS_WINDOWS
extern Ignition::Engine::Core::Application* Ignition::Engine::Core::CreateApplication();

int main(int argc, char** argv) {
    Ignition::Engine::Log::Init();
    auto app = Ignition::Engine::Core::CreateApplication();
    app->Run();
    delete app;
    return 0;
}

#endif