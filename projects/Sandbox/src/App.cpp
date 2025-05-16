#define IGN_APPLICATION
#include <Ignition.hpp>

class Sandbox : public Ignition::Core::Application {
public:
	Sandbox() {

	}

	~Sandbox() {

	}
};

Ignition::Core::Application* Ignition::Core::CreateApplication() {
	return new Sandbox();
}