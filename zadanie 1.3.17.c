#include <stdio.h>
#include <math.h>
#include <stdlib.h>

char nahodna_permutacia_cyklickeho_typu(int *p, int *cyc, int ncyc){
int i,j,k,n=0,m,a,b,c,match;

for (i=0;i<ncyc;i++){
	n+=cyc[i];
}
int r[n+1];
//pole nahodnych cisel po n okrem 1

for (j=0;j<n;j++){
	do{
	match = 0;
	r[j]=(rand()%(n))+1;
	for (i=0;i<j;i++){
		if (r[i] == r[j]){
			match=1;
		}
	}
	}while(match!=0);
}
//vypis pola
for(i=0;i<n;i++)
	printf("%d ",r[i]);
printf("\n");

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

//vypis permutacie
for (j=0;j<n;j++){
	printf("%d ",p[j]);
}
return 0;	
}

int main(){
	int perm[100];
	int cyc[10];
	int ncyc = 3;
	
	srand(time(NULL));
	cyc[0]=4;
	cyc[1]=3;
	cyc[2]=5;
	nahodna_permutacia_cyklickeho_typu(perm,cyc,ncyc);
}
