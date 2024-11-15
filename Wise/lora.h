#ifndef LORA_H
#define LORA_H

#include <stdint.h>

void lora_init();
void lora_send_packet(uint8_t *data, int length);
void lora_set_frequency(long frequency); 

#endif // LORA_H