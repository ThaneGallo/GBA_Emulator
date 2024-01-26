#pragma once 

#inclucde "common.h"

typedef struct {
    u8 a;
    u8 f;
    u8 b;
    u8 c;
    u8 d;
    u8 e;
    u8 h;
    u8 l;
    u16 pc;
    u16 sp;

} cpu_registers;

typedef struct {
    cpu_registers regsl

    u16 fetch_data;
    u16 mem_dest;
    u8 cur_opcode;

    bool halted;
    bool stepping;

} cpu_context;

void cpt_init();
int cpu_step();