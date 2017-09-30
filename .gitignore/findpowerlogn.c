#include <stdio.h>



int f(long int x,long int n) {

	if(n == 0)
		return 1;
	else if(n == 1) 
		return x;
	else if(n % 2 == 0) 
		return f(x,n/2) * f(x,n/2);
	else if(n % 2 == 1) 
		return x * f(x,n/2) * f(x,n/2);
}
int main() {

	long int n,x;
	scanf("%ld%ld", &x,&n);
	long int result = f(x,n);
	printf("%ld\n", result);
}