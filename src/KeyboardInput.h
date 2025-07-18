#pragma once

#include <unordered_map>
#include <string>

#include <Windows.h>

namespace KeyboardInput {
	typedef std::unordered_map<std::string, WORD> StringToKeyMap;
	extern StringToKeyMap stringToKeyMap;

	void press(WORD vk);
	void release(WORD vk);
}