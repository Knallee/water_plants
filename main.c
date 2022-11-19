/*
 * lcd.c
 *
 * Created: 2022-04-06 18:41:08
 * Author : ch5152ce
 */ 


#include "f_cpu.h"
#include "lcd.h"
#include "mcp7940m.h"
#include "i2c.h"
#include <util/delay.h>
#include <avr/io.h>
#include <stdlib.h>
#include <avr/interrupt.h>

void ext_int1_init();
uint8_t set_sec=0, set_min=2, set_h=1 ,get_sec,get_min,get_h;

uint8_t sec_to_dec;

volatile uint8_t enc_a, enc_b, enc_flag;
volatile int16_t enc_dir, enc_cnt, enc_cnt_old;

char buf[2];

int main(void)
{
    lcd_init();
    lcd_put_string("Hello");
	i2c_init();
	i2c_start(0xDE);
	i2c_write(0x00);
	i2c_start(0xDF);
	i2c_stop();
	set_clock();
	//ext_int1_init();
	


	sei();
    while (1) {
		get_time();
		sec_to_dec = (((get_sec & 0b01111111) >> 4) * 10) + (get_sec & 0b00001111);
		
		//if (enc_flag) {
			//enc_flag = 0;
			//lcd_commmand(0b00000001);		// Clear display
			//_delay_ms(5);
			//lcd_commmand(0b10000000);		// Return home
			//_delay_us(50);
			//itoa(enc_cnt, buf, 10);
			//lcd_put_string(buf);
			//enc_cnt_old = enc_cnt;
		//}
		
		
		//_delay_ms(500);
    }
}
//
//void ext_int1_init(){
	//MCUCR	|= (1 << ISC10);
	//GICR	|= (1 << INT1);
//}
//
//ISR(INT1_vect) {
	//
	//enc_flag = 1;
	//
	//enc_a = (PIND & (1 << PD3)) >> PD3;
	//enc_b = (PIND & (1 << PD7)) >> PD7;
	//
	//
	//if (enc_a != enc_b) {
		//enc_dir = -1;
	//}
	//
	//if(enc_a == enc_b) {
		//enc_dir = 1;
	//}
	//
	//
	//enc_cnt += enc_dir;
	//
//}

//
//#include "f_cpu.h"
//#include "lcd.h"
//#include <avr/io.h>
//#include <avr/interrupt.h>
//#include <stdlib.h>
//
//void ext_int1_init();
//
//volatile uint8_t enc_a, enc_b, enc_flag;
//volatile int16_t enc_dir, enc_cnt, enc_cnt_old;
//char buf[10];
//
//int main(void)
//{
	//ext_int1_init();
	//lcd_init();
	//sei();
	///* Replace with your application code */
	//while (1) {
		//if(enc_flag == 1) {
			//enc_flag = 0;
			//lcd_commmand(0b00000001);		// Clear display
			//_delay_ms(5);
			//lcd_commmand(0b10000000);		// Return home
			//_delay_us(50);
			//itoa(enc_cnt, buf, 10);
			//lcd_put_string(buf);
//
//
		//}
		//
	//}
//}
//
//void ext_int1_init(){
	//MCUCR	|= (1 << ISC10);
	//GICR	|= (1 << INT1);
//}
//
//ISR(INT1_vect) {
	//enc_flag = 1;
	//
	//enc_a = (PIND & (1 << PIND3)) >> PIND3;
	//enc_b = (PIND & (1 << PIND7)) >> PIND7;
	//
	//
	//if (enc_a != enc_b) {
		//enc_dir = -1;
	//}
	//
	//if(enc_a == enc_b) {
		//enc_dir = 1;
	//}
//
	//enc_cnt += enc_dir;
	//
//}