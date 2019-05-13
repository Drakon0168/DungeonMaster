#pragma once

#include "pch.h"

struct Vector2fComparer {
	bool operator()(const sf::Vector2f& lhs, const sf::Vector2f& rhs) const {
		if (lhs.x < rhs.x) {
			return true;
		}
		else if (lhs.x == rhs.x) {
			if (lhs.y < rhs.y) {
				return true;
			}
		}
		return false;
	}
};