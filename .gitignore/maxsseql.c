#include <stdio.h>

int main() {

	int s = 0,m = 0,a[100],n,l;
	scanf("%d", &n);
	scanf("%d", &l);
	for(int i = 0;i < n;i++) {
		scanf("%d", &a[i]);
	}

	for(int i = 0;i < l;i++) {
		s += a[i];
	}
	for(int i = l;i < n;i++) {
		s += a[i] - a[i - l];
		if(s > m) 
			m = s;
	}
	printf("%d\n", m);
	return 0;
}