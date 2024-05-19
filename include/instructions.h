#pragma once
#include "common.h"

typedef enum
{
    AM_R_D16,    // Operand is a register or a direct 16-bit value
    AM_R_R,      // Operand is two registers
    AM_MR_R,     // Operand is a memory address specified by a register, and another register
    AM_R,        // Operand is a register
    AM_R_D8,     // Operand is a register and a direct 8-bit value
    AM_R_MR,     // Operand is a register and a memory address specified by another register
    AM_R_HLI,    // Operand is a register, and the address is pointed to by the HL register pair, and the HL register pair is incremented after the operation
    AM_R_HLD,    // Operand is a register, and the address is pointed to by the HL register pair, and the HL register pair is decremented after the operation
    AM_HLI_R,    // Operand is a value pointed to by the HL register pair, and the HL register pair is incremented after the operation
    AM_HLD_R,    // Operand is a value pointed to by the HL register pair, and the HL register pair is decremented after the operation
    AM_R_A8,     // Operand is a register and an 8-bit address
    AM_A8_R,     // Operand is an 8-bit address and a register
    AM_HL_SPR,   // Operand is the HL register pair or SP (Stack Pointer)
    AM_D16,      // Operand is a direct 16-bit value
    AM_D8,       // Operand is a direct 8-bit value
    AM_IMP,      // Operand is implied or does not need to be specified explicitly
    AM_D16_R,    // Operand is a direct 16-bit value and a register
    AM_MR_D8,    // Operand is a memory address specified by a register and a direct 8-bit value
    AM_MR,       // Operand is a memory address specified by a register
    AM_A16_R,    // Operand is a 16-bit address and a register
    AM_R_A16     // Operand is a register and a 16-bit address
} addr_mode;

typedef enum
{
    RT_NONE,
    RT_A,
    RT_F,
    RT_B,
    RT_C,
    RT_D,
    RT_E,
    RT_H,
    RT_L,
    RT_AF, 
    RT_BC,
    RT_DE,
    RT_HL,
    RT_SP,
    RT_PC
} reg_type;

typedef enum
{
    IN_NONE,

    IN_NOP,
    IN_LD,
    IN_INC,
    IN_DEC,
    IN_RLCA,
    IN_ADD,
    IN_RRCA,
    IN_STOP,
    IN_RLA,
    IN_JR,
    IN_RRA,
    IN_DAA,
    IN_CPL,
    IN_SCF,
    IN_CCF,
    IN_HALT,
    IN_ADC,
    IN_SUB,
    IN_SBC,
    IN_AND,
    IN_XOR,
    IN_OR,
    IN_CP,
    IN_POP,
    IN_JP,
    IN_PUSH,
    IN_RET,
    IN_CB,
    IN_CALL,
    IN_RETI,
    IN_LDH,
    IN_JPHL,
    IN_DI,
    IN_EI,
    IN_RST,
    IN_ERR,
    // cb inst
    IN_RLC,
    IN_RRC,
    IN_RL,
    IN_RR,
    IN_SLA,
    IN_SBA,
    IN_SWAP,
    IN_SRL,
    IN_BIT,
    IN_RES,
    IN_SET
} in_type;

//
typedef enum // for flags
{
    CT_NONE, 
    CT_NZ, //!zero
    CT_Z, //zero
    CT_NC, //!carry
    CT_C //carry
} cond_type;

typedef struct
{
    in_type type;
    addr_mode mode;
    reg_type reg_1;
    reg_type reg_2;
    cond_type cond;
    u8 param;
} instruction;

instruction *instruction_by_opcode(u8 opcode);