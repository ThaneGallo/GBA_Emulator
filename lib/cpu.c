#include <cpu.h>
#include <bus.h>

cpu_context ctx = {0};

void cpi_init()
{
}

static void fetch_instruction()
{
    ctx.cur_opcode = bus_read(ctx.regs.pc++);
    ctx.cur_inst = instruction_by_opcode(ctx.cur_opcode);

    if(ctx.cur_inst == NULL){
        printf("unknown instruction ! %02X\n", ctx.cur_opcode);
        exit(-7);
    }
}

static void fetch_data()
{
    ctx.mem_dest = 0;
    ctx.dest_is_mem = false;

    switch (ctx.cur_inst->mode)
    {
    case AM_IMP:
        return;
    case AM_R:
        ctx.fetch_data = cpu_read_reg(ctx.cur_inst->reg_1);
        return;
    case AM_R_D8:
        ctx.fetch_data = bus_read(ctx.regs.pc);
        emu_cycles(1); // emulates cyles for instructions
        ctx.regs.pc++;
        return;

    case AM_D16:
    {
        u16 lo = bus_read(ctx.regs.pc);
        emu_cycles(1);

        u16 hi = bus_read(ctx.regs.pc);
        emu_cycles(1);

        ctx.fetch_data = lo | (hi << 8);
        ctx.regs.pc += 2;
    }
    default:
        printf("Unkown addr mode! %d\n", ctx.cur_inst->mode);
        exit(-7);
        return;
    }
}

static void execute()
{
    printf("not executing");
}

bool cpu_step()
{

    if (!ctx.halted)
    {
        fetch_instruction();
        fetch_data;
        execute();
    }
}