#include <stdio.h>

int arr[20] = {0};
int tree[20] = {0};

int st(int node, int s, int e){
    int mid = (s+e)/2;
    if(s == e){
        return tree[node] = arr[s];
    }
    return tree[node] = st(node*2,s,mid) + st(node*2+1,mid+1,e);

}

int main(){
    int n;
    int i;
    n = 16;
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    st(1,0,n-1);
    for(i=0;i<n;i++){
        printf("%d ",tree[i]);
    }
}

