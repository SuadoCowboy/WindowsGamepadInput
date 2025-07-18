#include "MouseInput.h"

void MouseInput::press(MouseButton button) {
	INPUT input{};
	input.type = INPUT_MOUSE;
	input.mi.dwFlags = button;
	SendInput(1, &input, sizeof(INPUT));
}

void MouseInput::release(MouseButton button) {
	INPUT input{};
	input.type = INPUT_MOUSE;
	input.mi.dwFlags = (button << 1);
	SendInput(1, &input, sizeof(INPUT));
}

void MouseInput::move(int dx, int dy) {
	INPUT input{};
	input.type = INPUT_MOUSE;
	input.mi.dx = dx;
	input.mi.dy = dy;
	input.mi.dwFlags = MOUSEEVENTF_MOVE;
	SendInput(1, &input, sizeof(INPUT));
}

void MouseInput::scrollVertical(int amount) {
	INPUT input{};
	input.type = INPUT_MOUSE;
	input.mi.dwFlags = MOUSEEVENTF_WHEEL;
	input.mi.mouseData = amount; // 120 units = 1 notch
	SendInput(1, &input, sizeof(INPUT));
}

void MouseInput::scrollHorizontal(int amount) {
	INPUT input{};
	input.type = INPUT_MOUSE;
	input.mi.dwFlags = MOUSEEVENTF_HWHEEL;
	input.mi.mouseData = amount;
	SendInput(1, &input, sizeof(INPUT));
}