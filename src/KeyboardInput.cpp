#include "KeyboardInput.h"

KeyboardInput::StringToKeyMap KeyboardInput::stringToKeyMap = {
	{ "BACK", VK_BACK }, { "BACKSPACE", VK_BACK },
	{ "TAB", VK_TAB },
	{ "CLEAR", VK_CLEAR },
	{ "RETURN", VK_RETURN }, { "ENTER", VK_RETURN },

	{ "SHIFT", VK_SHIFT },
	{ "LSHIFT", VK_LSHIFT },
	{ "RSHIFT", VK_RSHIFT },

	{ "CONTROL", VK_CONTROL }, { "CTRL", VK_CONTROL },
	{ "LCONTROL", VK_LCONTROL }, { "LCTRL", VK_LCONTROL },
	{ "RCONTROL", VK_RCONTROL }, { "RCTRL", VK_RCONTROL },

	{ "MENU", VK_MENU }, { "ALT", VK_MENU },
	{ "LMENU", VK_LMENU }, { "LALT", VK_LMENU },
	{ "RMENU", VK_RMENU }, { "RALT", VK_RMENU },

	{ "PAUSE", VK_PAUSE },
	{ "CAPITAL", VK_CAPITAL },
	{ "KANA", VK_KANA },
	{ "HANGEUL", VK_HANGEUL },
	{ "HANGUL", VK_HANGUL },
	{ "IME_ON", VK_IME_ON },
	{ "JUNJA", VK_JUNJA },
	{ "FINAL", VK_FINAL },
	{ "HANJA", VK_HANJA },
	{ "KANJI", VK_KANJI },
	{ "IME_OFF", VK_IME_OFF },
	{ "ESCAPE", VK_ESCAPE },
	{ "CONVERT", VK_CONVERT },
	{ "NONCONVERT", VK_NONCONVERT },
	{ "ACCEPT", VK_ACCEPT },
	{ "MODECHANGE", VK_MODECHANGE },
	{ "SPACE", VK_SPACE },
	{ "PRIOR", VK_PRIOR },
	{ "NEXT", VK_NEXT },
	{ "END", VK_END },
	{ "HOME", VK_HOME },
	{ "LEFT", VK_LEFT },
	{ "UP", VK_UP },
	{ "RIGHT", VK_RIGHT },
	{ "DOWN", VK_DOWN },
	{ "SELECT", VK_SELECT },
	{ "PRINT", VK_PRINT },
	{ "EXECUTE", VK_EXECUTE },
	{ "SNAPSHOT", VK_SNAPSHOT },
	{ "INSERT", VK_INSERT },
	{ "DELETE", VK_DELETE },
	{ "HELP", VK_HELP },

	{"0", 0x30},
	{"1", 0x31},
	{"2", 0x32},
	{"3", 0x33},
	{"4", 0x34},
	{"5", 0x35},
	{"6", 0x36},
	{"7", 0x37},
	{"8", 0x38},
	{"9", 0x39},

	{"A", 0x41},
	{"B", 0x42},
	{"C", 0x43},
	{"D", 0x44},
	{"E", 0x45},
	{"F", 0x46},
	{"G", 0x47},
	{"H", 0x48},
	{"I", 0x49},
	{"J", 0x4A},
	{"K", 0x4B},
	{"L", 0x4C},
	{"M", 0x4D},
	{"N", 0x4E},
	{"O", 0x4F},
	{"P", 0x50},
	{"Q", 0x51},
	{"R", 0x52},
	{"S", 0x53},
	{"T", 0x54},
	{"U", 0x55},
	{"V", 0x56},
	{"W", 0x57},
	{"X", 0x58},
	{"Y", 0x59},
	{"Z", 0x5A},

	{ "LWIN", VK_LWIN }, { "WIN", VK_LWIN },
	{ "RWIN", VK_RWIN },
	{ "APPS", VK_APPS },
	{ "SLEEP", VK_SLEEP },

	{ "NUMPAD0", VK_NUMPAD0 },
	{ "NUMPAD1", VK_NUMPAD1 },
	{ "NUMPAD2", VK_NUMPAD2 },
	{ "NUMPAD3", VK_NUMPAD3 },
	{ "NUMPAD4", VK_NUMPAD4 },
	{ "NUMPAD5", VK_NUMPAD5 },
	{ "NUMPAD6", VK_NUMPAD6 },
	{ "NUMPAD7", VK_NUMPAD7 },
	{ "NUMPAD8", VK_NUMPAD8 },
	{ "NUMPAD9", VK_NUMPAD9 },

	{ "MULTIPLY", VK_MULTIPLY },
	{ "ADD", VK_ADD },
	{ "SEPARATOR", VK_SEPARATOR },
	{ "SUBTRACT", VK_SUBTRACT },
	{ "DECIMAL", VK_DECIMAL },
	{ "DIVIDE", VK_DIVIDE },

	{ "F1", VK_F1 },
	{ "F2", VK_F2 },
	{ "F3", VK_F3 },
	{ "F4", VK_F4 },
	{ "F5", VK_F5 },
	{ "F6", VK_F6 },
	{ "F7", VK_F7 },
	{ "F8", VK_F8 },
	{ "F9", VK_F9 },
	{ "F10", VK_F10 },
	{ "F11", VK_F11 },
	{ "F12", VK_F12 },
	{ "F13", VK_F13 },
	{ "F14", VK_F14 },
	{ "F15", VK_F15 },
	{ "F16", VK_F16 },
	{ "F17", VK_F17 },
	{ "F18", VK_F18 },
	{ "F19", VK_F19 },
	{ "F20", VK_F20 },
	{ "F21", VK_F21 },
	{ "F22", VK_F22 },
	{ "F23", VK_F23 },
	{ "F24", VK_F24 }
};

void KeyboardInput::press(WORD vk) {
	INPUT input = { 0 };
	input.type = INPUT_KEYBOARD;
	input.ki.wVk = vk;
	input.ki.dwFlags = 0;
	SendInput(1, &input, sizeof(INPUT));
}

void KeyboardInput::release(WORD vk) {
	INPUT input = { 0 };
	input.type = INPUT_KEYBOARD;
	input.ki.wVk = vk;
	input.ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput(1, &input, sizeof(INPUT));
}