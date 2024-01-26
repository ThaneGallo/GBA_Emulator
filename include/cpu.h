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

void cpt_init();
int cpu_step();