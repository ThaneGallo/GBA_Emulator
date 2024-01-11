#pragma once

#include "common.h"

//uses 16 byte address and outputs 8 byte value at bus
u8 bus_read(u16 address);

//writes u8 value to u16 address
void bus_write(u16 address, u8 value);
