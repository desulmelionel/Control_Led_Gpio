# Control_Led_Gpio
access to the leds and and switch valuesT
This Programs access the GPIO of the Petalinux system running on a zybo board.
For this program to work properly the GPIOs have to be exported.
example: on exporting the gpios and testing them out.
also check the directions of said Gpio just in case a mistake was made during the Vivado design process.

zynq> echo 1016 > /sys/class/gpio/export
zynq> echo in > /sys/class/gpio/gpio1016/direction
zynq> echo out > /sys/class/gpio/gpio1016/direction
zynq> echo 1 > /sys/class/gpio/gpio1016/value
