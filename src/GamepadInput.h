#pragma once

#include <iostream>

#include <Windows.h>
#include <Xinput.h>
#pragma comment(lib, "Xinput9_1_0.lib")

class GamepadInput {
public:
	XINPUT_STATE state, previousState;
	DWORD xInputResult;
	unsigned char gamepadId = 0;

	GamepadInput(unsigned char gamepadId = 0);

	/**
	 * @return false if input result at first wasn't successful
	 * @return true if input result was successful from the beginning
	 */
	bool update();

	bool isButtonDown(short button);
	bool isButtonPressed(short button);
	bool isButtonUp(short button);
	bool isButtonReleased(short button);

	bool isLeftTriggerDown(BYTE threshold = XINPUT_GAMEPAD_TRIGGER_THRESHOLD);
	bool isLeftTriggerPressed(BYTE threshold = XINPUT_GAMEPAD_TRIGGER_THRESHOLD);
	bool isLeftTriggerReleased(BYTE threshold = XINPUT_GAMEPAD_TRIGGER_THRESHOLD);
	bool isRightTriggerDown(BYTE threshold = XINPUT_GAMEPAD_TRIGGER_THRESHOLD);
	bool isRightTriggerPressed(BYTE threshold = XINPUT_GAMEPAD_TRIGGER_THRESHOLD);
	bool isRightTriggerReleased(BYTE threshold = XINPUT_GAMEPAD_TRIGGER_THRESHOLD);
};