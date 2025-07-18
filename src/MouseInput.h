#pragma once

#include <Windows.h>

namespace MouseInput {
	enum MouseButton {
		LEFT = MOUSEEVENTF_LEFTDOWN,
		RIGHT = MOUSEEVENTF_RIGHTDOWN,
		MIDDLE = MOUSEEVENTF_MIDDLEDOWN
	};

	void press(MouseButton button);
	void release(MouseButton button);
	void move(int dx, int dy);
	void scrollVertical(int amount);
	void scrollHorizontal(int amount);
}