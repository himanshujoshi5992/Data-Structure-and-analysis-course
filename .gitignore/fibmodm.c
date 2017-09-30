#include <stdio.h>
#include <string.h>


void MM(int A[2][2],int B[2][2],int n,int m) {

	while(n) {

		int i, j, k,C[2][2];
	    for (i = 0; i < 2; i++)
	    {
	        for (j = 0; j < 2; j++)
	        {
	            C[i][j] = 0;
	            for (k = 0; k < 2; k++)
	                C[i][j] = (C[i][j] + A[i][k]*B[k][j]);
	        }
	        
	    }
		for (int i = 0; i < 2; ++i)
	    {
	    	for (int j = 0; j < 2; ++j)
	    	{
	    		A[i][j] = C[i][j];
	    	}
	    }
	    n--;
	}
}

void multiply(int A[2][2], int B[2][2],int D[2][2],int m)
{
    int i, j, k,C[2][2];
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            C[i][j] = 0;
            for (k = 0; k < 2; k++)
                C[i][j] = (C[i][j] + A[i][k]*B[k][j]);// % m;
        }
    }
    for (int i = 0; i < 2; ++i)
    {
    	for (int j = 0; j < 2; ++j)
    	{
    		D[i][j] = C[i][j];
    		//printf("%d\n", D[i][j]);
    	}
    }
}

int main() {

	int t;
	scanf("%d", &t);
	while(t) {

		int res[2][2],i,m;
		char num[1000000];
		int A[2][2],B[2][2];

		// Initializing the array and storing a copy in B for future multiplication
		B[0][0] = A[0][0] = 1;
		B[0][1] = A[0][1] = 1;
		B[1][0] = A[1][0] = 1;
		B[1][1] = A[1][1] = 0;

		//Identity matrix stored in res
		res[0][0] = 1;
		res[0][1] = 0;
		res[1][0] = 0;
		res[1][1] = 1;

		scanf("%s", &num);
		scanf("%d", &m);
		i = strlen(num) - 1;

		while(i >= 0) {

			if((num[i] - 48) > 0) {
				MM(A,B,(num[i] - 48),m);
				multiply(res,A,res,m);
			}
				
			MM(A,B,10,m);
			i--;
		}
		printf("%d\n", res[1][0] % m);
		t--;

	}

	return 0;
}