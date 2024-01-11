#pragma once

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


// makes the data types(green) referred to by their new name (white)
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

//reads bit n of number a
#define BIT(a,n) ((a & (1 << n)) ? 1 : 0)

//uses on to decide whether to set a bit to 0 or 1 then shifts to bit n and does operation to number a
#define BIT_SET(a, n, on) (on ? a |= (1<<n) : a &= ~(1 << n)) 

//checks if number a is between b and c 
#define BETWEEN(a, b, c) ((a >= b) && (a <= c))

void delay(u32 ms);
