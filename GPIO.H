#ifndef GPIO_H_
#define GPIO_H_

void vfnpinMode(char port, int pin, char io);
void vfndigitalWire(char port, int pin, int value);
#endif
