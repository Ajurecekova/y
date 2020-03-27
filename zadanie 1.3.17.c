#include <stdlib.h>
#include <math.h>
#include <stdlib.h>

char nahodna_permutacia_cyklickeho_typu(int *perm, int *cyc, int ncyc){
int i,j,k,n=0,m,a,b,c,match;

for (i=0;i<ncyc;i++){
	n+=cyc[i];
}
int r[n],p[n+1];
//pole nahodnych cisel po n okrem 1
printf("%d \n",n);
for (j=0;j<n-1;j++){
	do{
	match = 0;
	r[j]=(rand()%(n-1))+2;
	for (i=0;i<j;i++){
		if (r[i] == r[j]){
			match=1;
		}
	}
	}while(match!=0);
}
//vypis pola
for(i=0;i<n-1;i++)
	printf("%d",r[i]);
printf("\n");

//vytvorenie cyklickej permutacie
m=rand()%n;
for(i=0;i<ncyc;i++){
	p[m]=r[cyc[i]-2];
	for(j=1;j<=cyc[i]-2;j++){
		p[r[cyc[i]-j-1]-1]=r[cyc[i]-j-2];
		a=r[cyc[i]-j-2];
	}
	p[a-1]=m+1;
	m=cyc[i+1];
}

//vypis permutacie
for (j=0;j<n;j++){
	printf("%d ",p[j]);
}

	
}

int main(){
	int *perm;
	int *cyc;
	int ncyc=1,m=7;
	srand(time(NULL));
	cyc=&m;
	nahodna_permutacia_cyklickeho_typu(perm,cyc,ncyc);
}
