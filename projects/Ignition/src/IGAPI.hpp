#pragma once

#include <memory>

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