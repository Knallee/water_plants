/*
 * mcp7940m.h
 *
 * Created: 2022-04-06 23:21:51
 *  Author: ch5152ce
 */ 


#ifndef MCP7940M_H_
#define MCP7940M_H__

#include "f_cpu.h"
#include "i2c.h"
#include <util/delay.h>
#include <avr/io.h>

#define RTC_READ		(0xDF)	// 0b11011111 - 1101 is a 4-bit control code, next 3 bits needs to be 1's last bit is for read/write
#define RTC_WRITE		(0xDE)	// 0b11011110

extern uint8_t set_sec, set_min, set_h, get_sec, get_min, get_h;

void set_clock(void);
void get_time(void);

#endif /* MCP7940M_H_ */