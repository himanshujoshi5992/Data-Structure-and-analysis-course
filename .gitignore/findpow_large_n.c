#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {

	char *N = (char*)malloc(sizeof(1000000000));
	long int x,y = 1;
	scanf("%ld", &x);
	scanf("%s", N); // Assume the input is given in the form of binary number
	//printf("%d\n", strlen(N));
	for(int i = strlen(N)-1;i >= 0;i--) {
		if(N[i] - '0')
			y = y * x % 10;
		x = x * x;
		//printf("%ld\n", y);
	}
	printf("%ld\n", y);
	return 0;
}