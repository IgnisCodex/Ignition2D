#pragma once

#include <memory>

#include <glm/glm.hpp>

// ---- Igniton Typedefs ----
template <typename T>
using IGScope = std::unique_ptr<T>;
template <typename T, typename ... Args>
constexpr IGScope<T> IGCreateScope(Args&& ... args) {
	return std::make_unique<T>(std::forward<Args>(args)...);
}

template <typename T>
using IGRef = std::shared_ptr<T>;
template <typename T, typename ... Args>
constexpr IGRef<T> IGCreateRef(Args&& ... args) {
	return std::make_shared<T>(std::forward<Args>(args)...);
}

using IGVec2 = glm::vec2;
using IGVec3 = glm::vec3;
using IGVec4 = glm::vec4;
using IGMat3 = glm::mat3;
using IGMat4 = glm::mat4;