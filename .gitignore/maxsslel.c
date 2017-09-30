#include <stdio.h>

int main() {


	int a[100],n,k,s[100],l = 0,r = 0,x,m = 0,sar;
	scanf("%d%d",&n,&k);
	for(int i = 0;i < n;i++) {
		scanf("%d", &a[i]);
	}
	int sum = a[0];
	s[0]=sum;
	int length = 1;
	
	for(int i = 1;i < n;i++) {

		sum += a[i];
		length++;
		while(sum > s[r] && r >= l) 
			r--;

		s[++r] = sum;
		

		printf("\n\n elements under consideration\n");
		for(sar=0;sar<length;sar++)
		{
			printf("%d |",a[i-sar]);
		}
		printf("\n\n");

		if(length > k) {

			printf("length = %d | l = %d\n", length,l);
			sum -= s[l];
			//l++;
			length--;
			
		}
		printf("%d || %d ", s[l],sum);			
		x = s[l];
		if(x > m) 
			m = x;
		printf("Current max: %d\n", m);
		
		//printf("a[i] = %d | r = %d | l = %d \n", a[i],r,l);
		
		for(int j = 0;j <= r;j++) {
			printf("s[%d] = %d",j,s[j]);
		}
		printf("\n");
		
		//printf("");
			
	}

	printf("%d\n", m);
	return 0;



/*
	int s = 0,m = 0,a[100],n,l;
	scanf("%d", &n);
	scanf("%d", &l);
	for(int i = 0;i < n;i++) {
		scanf("%d", &a[i]);
	}
	int j = 0;
	int p = 0;
	while(j < n) {

		if(j-p+1 > l) {
			s -= a[p];
			p++;
		}
		if(s < 0) {
			p = j;
			s = 0;
			printf("s set as zero at a[%d] = %d\n", j,a[j]);
		}
		
		s += a[j];
		printf("s = %d\n", s);
		if(s > m)
			m = s;

		j++;
	}


	printf("%d\n", m);
	return 0;

*/
}