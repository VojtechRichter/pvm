#include "pvm.h"

int8_t regs[REGISTER_COUNT];
int32_t stack[STACK_CAPACITY];

int program[] = {
	MOVE, GRA, 4,
	ADD, GRA, 10,
	LOG, GRA
};

void ins_stack_push(int32_t value)
{
	regs[SP] += 1;
	stack[regs[SP]] = value;
}
void ins_stack_pop()
{
	if ((regs[SP] - 1) > -1) {
		stack[regs[SP]] = 0;
		regs[SP] -= 1;
	}
}

void ins_add(Reg dest, Reg src)
{
	regs[dest] += regs[src];
}

void ins_sub(Reg dest, Reg src)
{
	regs[dest] -= regs[src];
}
