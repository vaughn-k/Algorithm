#include <iostream>

using namespace std;

int n;

int cal(int n){
    if(n == 1){
        return 1;
    }
    return cal(n-1)*2 + 1;
}

int rest(int a,int b){
    return 6-a-b;
}
void move(int s, int e){
    // s에 있는거 e로 옮기기
    cout << s << " " << e << '\n';
}

void dump_move(int k, int s, int e){
    // k개까지 s에서 e로 옮기기
    if(k == 1){
        move(s,e);
    }
    else{
        dump_move(k-1,s,rest(s,e));
        move(s,e);
        dump_move(k-1,rest(s,e),e);
    }
}

int main(){
    cin >> n;
    cout << cal(n) << endl;
    dump_move(n,1,3);
}