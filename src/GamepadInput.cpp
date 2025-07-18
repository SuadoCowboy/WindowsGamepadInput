#include "GamepadInput.h"

GamepadInput::GamepadInput(unsigned char gamepadId) : gamepadId(gamepadId) {
	ZeroMemory(&state, sizeof(XINPUT_STATE));
	ZeroMemory(&previousState, sizeof(XINPUT_STATE));
}

bool GamepadInput::update() {
	previousState = state;

	xInputResult = XInputGetState(gamepadId, &state);
	if (xInputResult != ERROR_SUCCESS) {
		std::cout << "Listening for gamepad input...\n";

		while (xInputResult != ERROR_SUCCESS) {
			xInputResult = XInputGetState(gamepadId, &state);
			Sleep(250);
		}

		std::cout << "Gamepad detected\n";
		return false;
	}
	return true;
}


bool GamepadInput::isButtonDown(short button) {
	return (state.Gamepad.wButtons & button);
}

bool GamepadInput::isButtonPressed(short button) {
	return (state.Gamepad.wButtons & button) && !(previousState.Gamepad.wButtons & button);
}

bool GamepadInput::isButtonUp(short button) {
	return !(state.Gamepad.wButtons & button);
}

bool GamepadInput::isButtonReleased(short button) {
	return !(state.Gamepad.wButtons & button) && (previousState.Gamepad.wButtons & button);
}


bool GamepadInput::isLeftTriggerDown(BYTE threshold) {
	return state.Gamepad.bLeftTrigger > threshold;
}

bool GamepadInput::isLeftTriggerPressed(BYTE threshold) {
	return state.Gamepad.bLeftTrigger > threshold && previousState.Gamepad.bLeftTrigger <= threshold;
}

bool GamepadInput::isLeftTriggerReleased(BYTE threshold) {
	return state.Gamepad.bLeftTrigger <= threshold && previousState.Gamepad.bLeftTrigger > threshold;
}

bool GamepadInput::isRightTriggerDown(BYTE threshold) {
	return state.Gamepad.bRightTrigger;
}

bool GamepadInput::isRightTriggerPressed(BYTE threshold) {
	return state.Gamepad.bRightTrigger > threshold && previousState.Gamepad.bRightTrigger <= threshold;
}

bool GamepadInput::isRightTriggerReleased(BYTE threshold) {
	return state.Gamepad.bRightTrigger <= threshold && previousState.Gamepad.bRightTrigger > threshold;
}