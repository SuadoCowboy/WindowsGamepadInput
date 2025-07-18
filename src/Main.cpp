#include <iostream>

#include <Windows.h>

#include "GamepadInput.h"
#include "MouseInput.h"
#include "KeyboardInput.h"
#include "KeybindHandler.h"

constexpr DWORD DELTA_TIME = 10;

constexpr int DPAD_SCROLL_SENSITIVITY_DEFAULT = 120;
constexpr int DPAD_SCROLL_SENSITIVITY_SLOW = 60;

constexpr float SENSITIVITY_DEFAULT = 0.00095f;
constexpr float SENSITIVITY_SLOW = 0.0001f;

constexpr float THUMB_SCROLL_SENSITIVITY_DEFAULT = 240.0f/32768.0f;
constexpr float THUMB_SCROLL_SENSITIVITY_SLOW = 120.0f/32768.0f;

int main() {
	KeybindHandler::load("keybinds.txt");

	GamepadInput gamepadInput{};
	if (gamepadInput.update())
		std::cout << "Gamepad detected\n";

	while (true) {
		gamepadInput.update();

		{ // Mouse buttons
			if (gamepadInput.isLeftTriggerPressed())
				MouseInput::press(MouseInput::RIGHT);
			else if (gamepadInput.isLeftTriggerReleased())
				MouseInput::release(MouseInput::RIGHT);

			if (gamepadInput.isRightTriggerPressed())
				MouseInput::press(MouseInput::LEFT);
			else if (gamepadInput.isRightTriggerReleased())
				MouseInput::release(MouseInput::LEFT);

			if (gamepadInput.isButtonPressed(XINPUT_GAMEPAD_RIGHT_SHOULDER))
				MouseInput::press(MouseInput::MIDDLE);
			else if (gamepadInput.isButtonReleased(XINPUT_GAMEPAD_RIGHT_SHOULDER))
				MouseInput::release(MouseInput::MIDDLE);
		}

		{ // Scroll with DPAD
			if (gamepadInput.isButtonDown(XINPUT_GAMEPAD_DPAD_UP))
				MouseInput::scrollVertical(gamepadInput.isButtonDown(XINPUT_GAMEPAD_LEFT_SHOULDER)? DPAD_SCROLL_SENSITIVITY_SLOW : DPAD_SCROLL_SENSITIVITY_DEFAULT);

			if (gamepadInput.isButtonDown(XINPUT_GAMEPAD_DPAD_DOWN))
				MouseInput::scrollVertical(-(gamepadInput.isButtonDown(XINPUT_GAMEPAD_LEFT_SHOULDER)? DPAD_SCROLL_SENSITIVITY_SLOW : DPAD_SCROLL_SENSITIVITY_DEFAULT));
		}

		{ // Thumbs -> Move mouse cursor and scroll
			// left thumb -> move cursor
			float x = static_cast<float>(gamepadInput.state.Gamepad.sThumbLX);
			float y = static_cast<float>(gamepadInput.state.Gamepad.sThumbLY);

			if (abs(x) > XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE || abs(y) > XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE) {
				float sensitivity = gamepadInput.isButtonDown(XINPUT_GAMEPAD_LEFT_SHOULDER)? SENSITIVITY_SLOW : SENSITIVITY_DEFAULT;

				MouseInput::move(
					(int)(x * sensitivity),
					(int)(-y * sensitivity) // negative because up is negative
				);
			}

			// right thumb -> scroll
			x = static_cast<float>(gamepadInput.state.Gamepad.sThumbRX);
			y = static_cast<float>(gamepadInput.state.Gamepad.sThumbRY);

			if ((abs(x) > XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE || abs(y) > XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE)) {
				float scroll = gamepadInput.isButtonDown(XINPUT_GAMEPAD_LEFT_SHOULDER)? THUMB_SCROLL_SENSITIVITY_SLOW : THUMB_SCROLL_SENSITIVITY_DEFAULT;

				MouseInput::scrollVertical((int)(y * scroll));
				Sleep(1);
				MouseInput::scrollHorizontal((int)(x * scroll));
			}
		}

		// Keyboard Keys
		for (auto& bind : KeybindHandler::binds) {
			if (gamepadInput.isButtonPressed(bind.button)) {
				for (auto& key : bind.keys) {
					if (key.press)
						KeyboardInput::press(key.key);
					else
						KeyboardInput::release(key.key);
				}

			} else if (gamepadInput.isButtonReleased(bind.button)) {
				for (auto& key : bind.keys)
					if (!key.press)
						KeyboardInput::release(key.key);
			}
		}

		Sleep(DELTA_TIME);
	}

	return 0;
}