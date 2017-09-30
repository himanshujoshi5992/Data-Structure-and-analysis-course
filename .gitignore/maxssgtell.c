#include <stdio.h>

int maxss(int *a,int i,int n) {
	int j = i;
	int m = 0;
	int s = 0;

	//int p = 0;
	while(j < n) {

		if(s < 0) {
			//p = j;
			s = 0;
			//printf("s set as zero at a[%d] = %d\n", j,a[j]);
		}
		printf("%d\t%d | ",s,a[j]);
		s += a[j];
		//printf("s = %d\n", s);
		if(s > m)
			m = s;

		j++;
	}
	printf("\n\nmax=%d\n\n",m);

	return m;
}

	
int main() {




	int s = 0,m = 0,a[100],n,l;
	scanf("%d", &n);
	scanf("%d", &l);
	for(int i = 0;i < n;i++) {
		scanf("%d", &a[i]);
	}

	int i  = 0,j = l;
	while(j <= n) {
		int temp = maxss(a,i,j);
		if(temp > m) 
			m = temp;
		j++;
		i++;
	}

	printf("%d\n", m);
	return 0;


}