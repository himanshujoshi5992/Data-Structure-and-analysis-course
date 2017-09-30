#include <stdio.h>

int main() {

	int n,x;
	scanf("%d%d", &x,&n);
	long int y = 1;
	while(n) {
		if(n % 2 == 1)
			y = y * x;
		x = x * x;
		n /= 2;
	}
	printf("%ld\n", y);
	return 0;
}