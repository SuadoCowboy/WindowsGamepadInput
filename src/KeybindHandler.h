#pragma once

#include <vector>

#include <Windows.h>

namespace KeybindHandler {
	struct KeyData {
		WORD key = 0;
		bool press = false;
	};

	struct Keybind {
		unsigned button = -1;
		std::vector<KeyData> keys{};
	};

	enum BindButton {
		A = 0,
		B,
		X,
		Y,

		LEFT,
		RIGHT,

		BACK,
		START,

		LEFT_THUMB,
		RIGHT_THUMB,

		BINDS_COUNT
	};

	extern Keybind binds[BINDS_COUNT];

	/**
	 * @param path path/to/file
	 * @return true if success
	 * @return false if is not a regular file
	 */
	bool load(const char* path);
}