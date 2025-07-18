#include "KeybindHandler.h"

#include <fstream>
#include <string>
#include <filesystem>
#include <iostream>

#include <Windows.h>
#include <Xinput.h>

#include "KeyboardInput.h"

KeybindHandler::Keybind KeybindHandler::binds[KeybindHandler::BINDS_COUNT] = {
	{XINPUT_GAMEPAD_A, {}},
	{XINPUT_GAMEPAD_B, {}},
	{XINPUT_GAMEPAD_X, {}},
	{XINPUT_GAMEPAD_Y, {}},

	{XINPUT_GAMEPAD_DPAD_LEFT, {}},
	{XINPUT_GAMEPAD_DPAD_RIGHT, {}},

	{XINPUT_GAMEPAD_BACK, {}},
	{XINPUT_GAMEPAD_START, {}},

	{XINPUT_GAMEPAD_LEFT_THUMB, {}},
	{XINPUT_GAMEPAD_RIGHT_THUMB, {}}
};

bool KeybindHandler::load(const char* path) {
	if (!std::filesystem::is_regular_file(path)) {
		std::cout << "File does not exist or is not a regular file\n";
		return false;
	}

	/*
	File Example:

	// Comments can be made using '//'
	A = CTRL+W // Comments can be written after a bind as well
	LEFT = CTRL+SHIFT+T
	*/

	std::ifstream file(path);

	std::string line = "";
	while (std::getline(file, line)) {
		if (line.empty())
			continue;

		size_t separatorIndex = 0;
		size_t keyboardKeyEndIndex = line.size();
		for (size_t i = 0; i < line.size(); ) {
			if (isspace(line[i])) {
				line.erase(line.begin()+i);
				continue;
			}

			if (line[i] == '/' && i < line.size()-1 && line[i+1] == '/') { // comment
				keyboardKeyEndIndex = i;
				break;
			}

			if (line[i] == '=') // bind
				separatorIndex = i;

			++i;
		}

		if (separatorIndex == 0)
			continue;

		Keybind* pKeyBind = nullptr;
		{ // Get keybind position by gamepad button
			std::string gamepadButton = line.substr(0, separatorIndex);
			if (gamepadButton == "A")
				pKeyBind = &binds[BindButton::A];
			else if (gamepadButton == "B")
				pKeyBind = &binds[BindButton::B];
			else if (gamepadButton == "X")
				pKeyBind = &binds[BindButton::X];
			else if (gamepadButton == "Y")
				pKeyBind = &binds[BindButton::Y];

			else if (gamepadButton == "LEFT")
				pKeyBind = &binds[BindButton::LEFT];
			else if (gamepadButton == "RIGHT")
				pKeyBind = &binds[BindButton::RIGHT];

			else if (gamepadButton == "BACK")
				pKeyBind = &binds[BindButton::BACK];
			else if (gamepadButton == "START")
				pKeyBind = &binds[BindButton::START];

			else if (gamepadButton == "LEFT_THUMB")
				pKeyBind = &binds[BindButton::LEFT_THUMB];
			else if (gamepadButton == "RIGHT_THUMB")
				pKeyBind = &binds[BindButton::RIGHT_THUMB];
				
			else {
				std::cerr << "Unknown gamepad button: \"" << line << "\"\n";
				continue;
			}
		}

		pKeyBind->keys.clear();

		std::string keyboardKeys = line.substr(separatorIndex+1, keyboardKeyEndIndex-(separatorIndex+1));
		{ // Split keyboard keys by '+' character
			std::string key = "";

			size_t keyIndex = 0;
			for (size_t i = 0; i < keyboardKeys.size(); ++i) {
				if (keyboardKeys[i] == '+') {
					bool press = true;
					if (keyboardKeys[keyIndex] == '!') {
						press = false;
						++keyIndex;
					}

					key = keyboardKeys.substr(keyIndex, i-keyIndex);
					keyIndex = i+1;

					if (KeyboardInput::stringToKeyMap.count(key) == 0) {
						std::cerr << "Unknown key \"" << key << "\", skipping...\n";
						continue;
					}

					pKeyBind->keys.push_back({
						.key=KeyboardInput::stringToKeyMap[key],
						.press=press
					});
				}
			}

			bool press = true;
			if (keyboardKeys[keyIndex] == '!') {
				press = false;
				++keyIndex;
			}

			key = keyboardKeys.substr(keyIndex);
			if (KeyboardInput::stringToKeyMap.count(key) == 0) {
				std::cerr << "Unknown key \"" << key << "\", skipping...\n";
				continue;
			}

			pKeyBind->keys.push_back({
				.key=KeyboardInput::stringToKeyMap[key],
				.press=press
			});
		}

	}

	return true;
}