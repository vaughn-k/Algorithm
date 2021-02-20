//22m

#include <stdio.h>

char dna[1000001] = {};

void agct(int i);
int agct_main(int n);

int main(){
    int i,j,n;
    scanf("%d\n",&n);

    for(i=0;i<n;i++){
        scanf("%c",&dna[i]);
    }

    agct_main(n);
    printf("%c",dna[0]);    
}

int agct_main(int n){
    int i,j;
    for(i=n-2;i>=0;i--){
        agct(i);
    }
    return 0;
}

void agct(int i){
    char a = dna[i];
    char b = dna[i+1];
    if((a=='A'&&b=='A')||(a=='C'&&b=='A')||(a=='A'&&b=='C')||(a=='G'&&b=='T')||(a=='T'&&b=='G')){
        dna[i] = 'A';
        return;
    }
    if((a=='G'&&b=='A')||(a=='A'&&b=='G')||(a=='C'&&b=='C')){
        dna[i] = 'C';
        return;
    }
    if((a=='T'&&b=='A')||(a=='G'&&b=='G')||(a=='T'&&b=='C')||(a=='A'&&b=='T')||(a=='C'&&b=='T')){
        dna[i] = 'G';        
        return;
    }
    if((a=='C'&&b=='G')||(a=='G'&&b=='C')||(a=='T'&&b=='T')){
        dna[i] = 'T';
        return;
    }
}