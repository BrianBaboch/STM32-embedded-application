#include <stdint.h>
#include <stdio.h>

/*
After initialising different global variables and performing the 
arm-none-eabi-objdump -t command, I noticed that the variables that are 
initialised are being put behind each other in the data section (x is at 
0x00, b is at 0x04, v is at 0x08) and seperated by 4 octets since they're 
all 32 bits variables.
Same goes for variables initiliased to 0, they're stored in the same way but
in the BSS, (r is at 0x00, s is at 0x04).
The global variables that are not initialised, like y, are in the *COM* 
state, since we're not sure if they're in BSS or data, in this case the 
value  that is written is the offset and not the exact address since it 
depends whether they will be in the BSS or the data section so the offset 
indicates, in the case of y,  that this variable will take 4 octets after 
the last variable that was stored.
*/

int32_t x = 34;
double y;
int32_t b = 4;
int32_t r = 0;
int32_t s = 0;
int32_t w;
int32_t v = 34;
int32_t k;
int32_t l;
const char mesg[] = "Hello World!";

int main() {
	static uint8_t z;
	uint16_t t;
	y = 12;
	z = z + 1;
	t = 12+z;
	printf(mesg);
	printf("x = %d, y = %d, z = %d, t = %d\n", x, y, z, t);
	return 0;
}
