#define IG_APPLICATION
#include <Ignition.hpp>

class Sandbox : public Ignition::Engine::Core::Application {
public:
	Sandbox() {

	}

	~Sandbox() {

	}
};

Ignition::Engine::Core::Application* Ignition::Engine::Core::CreateApplication() {
	return new Sandbox();
}