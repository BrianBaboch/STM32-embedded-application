#include <stdio.h>
#include <stdint.h>

//variables pour tester le init.c
int8_t y;
int8_t z;

int fibo(int n){
	if (n == 0){
		return 0;
	}
	else if (n == 1){
		return 1;
	}
	else{
		return (fibo(n-1) + fibo(n-2));
	}
}

int main() {
	return (fibo(8));
}
