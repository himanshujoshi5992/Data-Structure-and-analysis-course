#include <stdio.h>

int main() {

	int a[100],n,k,s[100],l = 0,r = 0,x,m = 0;
	scanf("%d%d",&n,&k);
	for(int i = 0;i < n;i++) {
		scanf("%d", &a[i]);
	}
	s[0] = 0;
	for(int i = 1;i < n;i++) {

		
		while(a[i] < a[s[r]] && r >= l) 
			r--;

		s[++r] = i;
		

		if(s[r]-s[l]+1 > k) {
			l++;
			
		}
		//printf("%d ", a[s[l]]);			
		x = s[l];
		if(a[i] - a[x] > m) 
			m = a[i] - a[x];

		
		//printf("a[i] = %d | r = %d | l = %d \n", a[i],r,l);
		/*
		for(int j = 0;j <= r;j++) {
			printf("s[%d] = %d",j,a[s[j]]);
		}
		printf("\n");
		*/
		printf("");
			
	}

	printf("%d\n", m);
	return 0;
}