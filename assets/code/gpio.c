//////////////////////////////////////////////////////////////////////////////
// Author: Curtis Reedy
// Date: 8/1/2019
// Description:
// A simple program to toggle GPIO pins on a MCP23017 gpio expander IC
// Compilation Command: gcc gpio.c -o gpio
//////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <poll.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <inttypes.h>  // uint8_t, uint16_t, etc
#include <linux/i2c-dev.h> // I2C bus definitions
#include <linux/rtc.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <errno.h>


int fd_gpio;
// i2c address determined by 3 bit config of pins A0, A1, and A2
int gpio_addr = 0x20;
// buffer for holding registers and values
uint8_t buf[3];
// counter
uint16_t i = 0;


int main(void) 
{
	// open the i2c gpio expander
	if ((fd_gpio = open("/dev/i2c-1", O_RDWR)) < 0) 
	{
		// if errors while opening, log it and exit
		printf("Error: Couldn't open device! %d\n", fd_gpio);
		exit (1);
	}
	// check that the gpio expander is available on the i2c bus
	if (ioctl(fd_gpio, I2C_SLAVE, gpio_addr) < 0) 
	{
		// if errors while opening, log it and exit
		printf("Error: Couldn't find device on address!\n");
		exit (1);
	}

	// port config register 0x00 [IODIRA]
	buf[0] = 0b00000000;
	// 0xFE or 0b11111110 to configure GPIOA0 as an output and GPIOA1-7 as inputs
	buf[1] = 0b11111110; 
	// write the buffer containing ADDRESS and VALUE to the gpio expander
	write(fd_gpio, buf, 2);

	// loop and toggle the led ON/OFF 3 times
	while (i < 3) 
	{	
		// register to write to 0x12 [GPIOA]
		buf[0] = 0b00010010;
		// value to write just GPIOA0 to HIGH
		buf[1] = 0b00000001; 
		// write the buffer containing ADDRESS and VALUE to the gpio expander
		write(fd_gpio, buf, 2);
		// sleep for 1 second
		sleep(1);

		// register to write to 0x12 [GPIOA]
		buf[0] = 0b00010010; 
		// value to write just GPIOA0 to LOW
		buf[1] = 0b00000000;
		// write the buffer containing ADDRESS and VALUE to the gpio expander
		write(fd_gpio, buf, 2);
		// sleep for 1 second
		sleep(1);

		// increment counter
		i++;
	}

	// clean up and close the i2c connection with the gpio expander
	close(fd_gpio);

	return 0;
}