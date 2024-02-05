#ifndef AVM_H
#define AVM_H

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

extern int program[];

#define SOURCE program;

#define STACK_CAPACITY (4 * 1024) // 4kB

typedef enum {
	PUSH,
	POP,
	ADD,
	SUB,
	MUL,
	DIV,
	JUMP,
	MOVE,
	LOG
} Ins;

#define INSTRUCTION_COUNT 8

typedef struct {
	Ins ins_type;
	int32_t value;
} UIns;

typedef struct {
	Ins ins_type;
	int32_t first_value;
	int32_t second_value;
} BIns;

typedef enum {
	GRA,
	GRB,
	GRC,
	GRD,
	GRE,
	GRF,
	IP,
	SP
} Reg;

#define REGISTER_COUNT 8

void ins_stack_push(int32_t value);
void ins_add(Reg dest, Reg src);
void ins_sub(Reg dest, Reg src);
void ins_stack_pop();

#endif // AVM_H
