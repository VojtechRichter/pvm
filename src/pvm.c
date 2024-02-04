#include "pvm.h"

int8_t regs[REGISTER_COUNT];
int32_t stack[STACK_CAPACITY];

int program[] = {
	MOVE, GRA, 4,
	ADD, GRA, 10,
	LOG, GRA
};


