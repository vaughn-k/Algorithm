#include <iostream>

using namespace std;

int main(){
    int l,p,v;
    int tot;
    int t = 1;
    while(true){
        cin >> l >> p >> v;
        if(l+p+v == 0){
            break;
        }
        tot = v/p * l + min(v%p,l);
        cout << "Case " << t << ": " << tot << '\n';
        t++;
    }
}