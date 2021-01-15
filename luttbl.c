#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXNUM 128

uint8_t outs[MAXNUM] = {0};
char numbuf[9] = {0};
uint8_t len = 0;

void putbin(uint16_t n) {
	for(int16_t i = len-1; i >= 0 ; i--) {
		numbuf[i] = (n & 1) + '0';
		n >>= 1;
	}
}

int main(int argc, char **argv) {
	len = atoi(argv[1]);
	uint16_t total = 1<<len;
	char c = 0;
	for(int16_t i = total-1; i >= 0; i--) {
		while((c = getchar()) < '0' || c > '1');
		outs[i] = c;
	}
	for(uint16_t i = 0; i < total; i++) {
		putbin(i);
		printf("%s %c\n", numbuf, outs[i]);
	}
	return 0;
}

