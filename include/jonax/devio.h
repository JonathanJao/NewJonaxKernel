void keyboard_install();
void dev_install();
void init_video(void);

void scroll(void);
void move_csr(void);
void settextcolor(unsigned char forecolor, unsigned char backcolor);
void cls();
void putchar(char c);

void keyboard_handler(struct regs *r);
int do_scan(unsigned char *input);
