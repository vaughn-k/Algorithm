#include <stdio.h>

int main(void){
	int i, j, k, n, w, v, res[100001]={0,};

	scanf("%d %d", &n, &k);

	for(i=0; i<n; ++i){
		scanf("%d %d", &w, &v);
    // j = 최대 담을수 있는 무게부터 현재 고른 물건 무게까지 순환
		for(j=k; j>=w; --j){
			if(res[j]<res[j-w]+v){
				res[j]=res[j-w]+v;
			}
		}
	}

	printf("%d", res[k]);

	return 0;
}