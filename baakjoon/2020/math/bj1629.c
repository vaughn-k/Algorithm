#include <stdio.h>
#include <stdlib.h>

int main(){
    long long a,b,c;
    int i;
    long long ans;
    long long *store;
    int check = 0;
    // long long store[214748];

    scanf("%lld",&a);
    scanf("%lld",&b);
    scanf("%lld",&c);
    store = (int*)malloc(sizeof(int)*c);

    ans = a%c;
    store[0] = ans;
    a = a%c;
    for(i=0; i<b-1; i++){
        ans = (ans * a) % c;
        printf("%lld\n",b%(i+1));

        if(store[0] == (int)ans){
            check = 1;
            // printf("%lld",b%(i+1));
            printf("%d",store[(int)b%(i+1)]);
            break;
        }
        store[i+1] = ans;
        // printf("| : %lld\n",ans);
    }
    if(check == 0){
        printf("%lld",ans);
    }
}