/* 20 = Shifts 21 = arrows 26 & 27 = function keys */
unsigned char kbdus[128] =
{
    0,  27, '1', '2', '3', '4', '5', '6', '7', '8',	/* 9 */
  '9', '0', '-', '=', '\b',	/* Backspace */
  '\t',			/* Tab */
  'q', 'w', 'e', 'r',	/* 19 */
  't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n',		/* Enter key */
    0,			/* 29   - Control */
  'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';',	/* 39 */
 '\'', '`',   201,		/* Left shift */
 '\\', 'z', 'x', 'c', 'v', 'b', 'n',			/* 49 */
  'm', ',', '.', '/',   202,					/* Right shift */
  '*',
    0,	/* Alt */
  ' ',	/* Space bar */
    0,	/* Caps lock */
    261,	/* 59 - F1 key ... > */
    262,   263,   264,   265,   266,   267,   268,   269,
    270,	/* < ... F10 */
    0,	/* 69 - Num lock*/
    0,	/* Scroll Lock */
    0,	/* Home key */
    210,	/* Up Arrow */
    0,	/* Page Up */
  '-',
    211,	/* Left Arrow */
    0,
    213,	/* Right Arrow */
  '+',
    0,	/* 79 - End key*/
    212,	/* Down Arrow */
    0,	/* Page Down */
    0,	/* Insert Key */
    0,	/* Delete Key */
    0,   0,   0,
    271,	/* F11 Key */
    272,	/* F12 Key */
    0,	/* All other keys are undefined */
};
unsigned char kbdus_shift[128] =
{
    0,  27, '!', '@', '#', '$', '%', '^', '&', '*',	/* 9 */
  '(', ')', '_', '+', '\b',	/* Backspace */
  '\t',			/* Tab */
  'Q', 'W', 'E', 'R',	/* 19 */
  'T', 'Y', 'U', 'I', 'O', 'P', '{', '}', '\n',		/* Enter key */
    0,			/* 29   - Control */
  'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ':',	/* 39 */
 '"', '~',   201,		/* Left shift */
 '\\', 'Z', 'X', 'C', 'V', 'B', 'N',			/* 49 */
  'm', '<', '>', '?',   202,					/* Right shift */
  '*',
    0,	/* Alt */
  ' ',	/* Space bar */
    0,	/* Caps lock */
    261,	/* 59 - F1 key ... > */
    262,   263,   264,   265,   266,   267,   268,   269,
    270,	/* < ... F10 */
    0,	/* 69 - Num lock*/
    0,	/* Scroll Lock */
    0,	/* Home key */
    210,	/* Up Arrow */
    0,	/* Page Up */
  '-',
    211,	/* Left Arrow */
    0,
    213,	/* Right Arrow */
  '+',
    0,	/* 79 - End key*/
    212,	/* Down Arrow */
    0,	/* Page Down */
    0,	/* Insert Key */
    0,	/* Delete Key */
    0,   0,   0,
    271,	/* F11 Key */
    272,	/* F12 Key */
    0,	/* All other keys are undefined */
};

