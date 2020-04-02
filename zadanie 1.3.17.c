#include <stdio.h>
#include <math.h>
#include <stdlib.h>

char nahodna_permutacia_cyklickeho_typu(int *p, int *cyc, int ncyc){
	int i,j,k,n=0,m,a,b,c,match;

	for (i=0;i<ncyc;i++){
		n+=cyc[i];
	}
	
	int r[n+1];
//pole nahodnych cisel od 1 po n

	for (i = 0; i < n;i ++){
	r[i]=i+1;
	}

	for (i = 0; i < n ; ++i){
        j = rand() % (i+1);
        b = r[i];
        r[i] = r[j];
        r[j] = b;
  	}

//vytvorenie cyklickej permutacie
	m=0;
	a=0;

	for(i=0;i<ncyc;i++){
		a+=cyc[i];
		p[r[m]-1]=r[a-1];
		for(j=1;j<=cyc[i]-1;j++){
			p[r[a-j]-1]=r[a-j-1];
			
		}
		m+=cyc[i];
	}

return 0;	
}

int main(){
	int perm[100];
	int cyc[10];
	int ncyc = 3;
	int j,i,n;
	
	srand(time(NULL));
	
	cyc[0]=4;
	cyc[1]=3;
	cyc[2]=2;
	
	nahodna_permutacia_cyklickeho_typu(perm,cyc,ncyc);
	
	for (i=0;i<ncyc;i++){
		n+=cyc[i];
	}
	for (j=0;j<n;j++){
		printf("%d ",perm[j]);
	}
}
