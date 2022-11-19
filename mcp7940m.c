/*
 * mcp7940m.c
 *
 * Created: 2022-04-06 23:22:09
 *  Author: ch5152ce
 */ 

#include "mcp7940m.h"

void set_clock(void) {
	i2c_start(RTC_WRITE);
	i2c_write(0x00);
	i2c_write(set_sec | (1 << 7) );
	i2c_write(set_min);
	i2c_write(set_h);
	i2c_stop();
}

void get_time() {
	i2c_start(RTC_WRITE);
	i2c_write(0x00);
	i2c_start(RTC_READ);
	get_sec = i2c_read_ack();
	get_min = i2c_read_ack();
	get_h = i2c_read_nack();
	i2c_stop();
}