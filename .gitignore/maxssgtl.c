#include <stdio.h>

int main() {

	int s = 0,m = 0,a[100],n,l;
	scanf("%d", &n);
	scanf("%d", &l);
	for(int i = 0;i < n;i++) {
		scanf("%d", &a[i]);
	}
	int j = 0;
	int p = 0;
	while(j < n) {
		if(s < 0) {
			p = j;
			s = 0;
			//printf("s set as zero at a[%d] = %d\n", j,a[j]);
		}
		
		s += a[j];
		//printf("s = %d\n", s);
		if(s > m && j-p+1 >= l)
			m = s;

		j++;
	}
	printf("%d\n", m);
	return 0;
}