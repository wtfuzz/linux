#ifndef RPI_SENSORS_H_
#define RPI_SENSORS_H_

#include <linux/mpu.h>
#include <linux/gpio.h>

static struct mpu_platform_data gyro_platform_data = {
	.int_config  = 0x10,
	.level_shifter = 0,
	.orientation = {  -1,  0,  0,
			   0,  1,  0,
			   0,  0, -1 },
	.sec_slave_type = SECONDARY_SLAVE_TYPE_NONE,
};

static struct i2c_board_info __initdata mpu_board_info[] = {
	{
		I2C_BOARD_INFO("mpu6050", 0x68),
		.irq = GPIO_TO_IRQ(27),
		.platform_data = &gyro_platform_data,
	},
};

#endif
