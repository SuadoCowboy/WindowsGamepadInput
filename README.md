# Hard Coded Mouse Binds
The main objective of this project were to simulate mouse input from a controller. Although I could make something more dynamic I'm too lazy and this project is for my own use and I like the way it is.

**Those binds are:**
```
LEFT THUMB = Move mouse cursor
LEFT SHOULDER = Move mouse cursor and scroll slowly
LEFT TRIGGER = Right mouse button

RIGHT THUMB = Move scroll (both horizontal and vertical)
RIGHT SHOULDER = Middle mouse button
RIGHT TRIGGER = Left mouse button

DPAD UP = Move vertical scroll
DPAD DOWN = Move vertical scroll
```

# Key Binding
The file `keybinds.txt` is where you bind your gamepad buttons to simulate keyboard key presses and releases. Insert a `!` before a key to simulate a release.

**Example:**
```
// this is a comment and is ignored by the key bind handler
Y = LCTRL+LSHIFT+T // open previously closed tab in your navigator
X = LALT+TAB // Quick alt tab
LEFT = LEFT
RIGHT = RIGHT
```


**Available gamepad buttons:**
```
A,
B,
X,
Y,
LEFT,
RIGHT,
BACK,
START,
LEFT_THUMB,
RIGHT_THUMB
```

**Available keyboard keys:** (`/` means the same key contains different names; `0-9` means 0 through 9. Same goes for `A-Z`)
```
BACKSPACE/BACK,
TAB,
CLEAR,
RETURN/ENTER,
SHIFT,
CONTROL/CTRL,
MENU/ALT,
LSHIFT,
RSHIFT,
LCONTROL/LCTRL,
RCONTROL/RCTRL,
LMENU/LALT,
RMENU/RALT,
PAUSE,
CAPITAL,
KANA,
HANGEUL,
HANGUL,
IME_ON,
JUNJA,
FINAL,
HANJA,
KANJI,
IME_OFF,
ESCAPE,
CONVERT,
NONCONVERT,
ACCEPT,
MODECHANGE,
SPACE,
PRIOR,
NEXT,
END,
HOME,
LEFT,
UP,
RIGHT,
DOWN,
SELECT,
PRINT,
EXECUTE,
SNAPSHOT,
INSERT,
DELETE,
HELP,

0-9,
A-Z,

LWIN/WIN,
RWIN,
APPS,
SLEEP,

NUMPAD0,
NUMPAD1,
NUMPAD2,
NUMPAD3,
NUMPAD4,
NUMPAD5,
NUMPAD6,
NUMPAD7,
NUMPAD8,
NUMPAD9,

MULTIPLY,
ADD,
SEPARATOR,
SUBTRACT,
DECIMAL,
DIVIDE,

F1,
F2,
F3,
F4,
F5,
F6,
F7,
F8,
F9,
F10,
F11,
F12,
F13,
F14,
F15,
F16,
F17,
F18,
F19,
F20,
F21,
F22,
F23,
F24
```