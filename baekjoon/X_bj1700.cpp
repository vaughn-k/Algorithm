#include <iostream>

using namespace std;

int n,k;
int ccount;
int c[101]; // 콘센트
int list[101]; // 사용순서
int lef[101];


int findMostUse(){ // 현재 플러그에 꼽혀있는 물건 중 앞으로 가장 많이 사용할 물건 출력

}

int main(){
    cin >> n >> k;
    for(int i=0;i<=k;i++){
        lef[i] = 0;
    }
    for(int i=0;i<=n;i++){
        c[i] = 0;
    }
    for(int i=0;i<k;i++){
        cin >> list[i];
        if(i > 0){
            if(list[i-1] != list[i]){
                lef[list[i]]++;
            }
        }
    }

    ccount = 0;
    int now;
    for(int i=0;i<k;i++){ // 코드 하나씩 꼽기
        now = list[i];
        if(ccount < n){ // 빈 플러그가 있음
            if(c[now] != 0){ // 현재 이 기기가 플러그에 꼽혀있지 않음
                c[now] = 1;
                ccount++;
            }
            // else : pass
            lef[now]--;
        }
        else{

        }
    }
}