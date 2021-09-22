#include <iostream>

using namespace std;

int t;
int n;
int bread[1001][2];
int save[1001][5001][2][2];
// a가 더 많다면 0
// b가 더 많다면 1

struct ST{
    int value;
    int position;
};

int swit(int a, int b){
    if(a > b){
        return 0;
    }
    else{
        return 1;
    }
}

ST dfs(int now, int totA, int totB){
    // now번째에서 totA, totB 시간을 가지고나올수 있는 최선의 시간
    int ans1,ans2,answer;
    ST st1,st2,st3;
    if(totA >= 5000 || totB >= 5000){
        st3.value = 99999999;
        st3.position = 0;
        return st3;
    }
    if(now == n){
        ST st;
        st.value = max(totA,totB);
        if(totA > totB){
            st.position = 0;
        }
        else{
            st.position = 1;
        }
        return st;
    }
    if(save[now][abs(totA-totB)][swit(totA,totB)][0]){
        st3.value = save[now][abs(totA-totB)][swit(totA,totB)][0] + bread[now][0];
        st3.position = 0; 
        return st3;
    }
    if(save[now][abs(totA-totB)][swit(totA,totB)][1]){
        st3.value = save[now][abs(totA-totB)][swit(totA,totB)][1] + bread[now][1];
        st3.position = 1; 
        return st3;
    }

    st1 = dfs(now+1,totA+bread[now][0],totB);
    st2 = dfs(now+1,totA,totB+bread[now][1]);
    if(st1.value < st2.value){
        save[now][abs(totA-totB)][swit(totA,totB)][st1.position] = st1.value-bread[now][st1.position];
        return st1;
    }
    else{
        save[now][abs(totA-totB)][swit(totA,totB)][st2.position] = st2.value-bread[now][st2.position];
        return st2;
    }
}

int main(){
    cin >> t;
    ST st;
    for(int z=0;z<t;z++){
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> bread[i][0] >> bread[i][1];
        }
        st = dfs(0,0,0);
        cout << st.value << '\n';
    }
}