#include <iostream>

using namespace std;

int p,q,r,a,b,c,d;
int sub[4];
int tot;
int t;
int df1[] = {0,0,1,1};
int df2[] = {2,3,2,3};

int main(){
    cin >> t;
    for(int i=1;i<=t;i++){
        tot = 0;
        cin >> p >> q >> r;
        cin >> a >> b >> c >> d;
        // 상하좌우 각각 네모가 원 안에있을때 1, 아니면 0
        sub[0] = abs(p-a);
        sub[1] = abs(p-c);
        sub[2] = abs(q-b);
        sub[3] = abs(q-d);
        for(int j=0;j<4;j++){
            if(pow(sub[df1[j]],2) + pow(sub[df2[j]],2) <= pow(r,2)){
                tot = tot + 1;
            }
        }
        
        if(p-r <= a){
            tot = tot + 1;
        }
        if(p+r >= c){
            tot = tot + 1;
        }
        if(q-r <= b){
            tot = tot + 1;
        }
        if(q+r >= d){
            tot = tot + 1;
        }
        if(p-r == a){
            res--;
        }
        if(p+r == c){
            res--;
        }
        if(q-r == b){
            res--;
        }
        if(q+r == d){
            res--;
        }

        if(tot == 0){
            cout << "NY" << endl;
        }
        else if(tot == 8){
            cout << "YN" << endl;
        }
        else{
            cout << "YY" << endl;
        }
    }
}

299934