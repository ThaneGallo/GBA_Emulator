#include <cpu.h>

static void proc_none(cpu_context *ctx)
{
    printf("INVALID INST\n");
    exit(-7);
}

static void proc_ld(cpu_context *ctx)
{
    // to do
}

static bool check_cond(cpu_context *ctx)
{
    bool z = CPU_FLAG_Z;
    bool c = CPU_FLAG_C;

    switch (ctx->cur_inst->cond)
    {
    case CT_NONE:
        return true;
    case CT_C:
        return c;
    case CT_NC:
        return !c;
    case CT_Z:
        return z;
    case CT_NZ:
        return !z;
    }
    return false;
}

static void proc_jp(cpu_context *ctx)
{
    if (check_cond(ctx))
    {
        ctx->regs.pc = ctx->fetch_data;
        emu_cycles(1);
    }
}

static void proc_nop(cpu_context *ctx)
{
   printf("No Op\n");
    exit(-7);
}

// process cpu inst
IN_PROC processors[] = {
    [IN_NONE] = proc_none, // IN_NONE
    [IN_NOP] = proc_nop,
    [IN_LD] = proc_ld,
    [IN_JP] = proc_jp,
    [IN_LD] = proc_ld,

};

IN_PROC inst_get_processor(in_tyoe type){
    return processors[type];
}
