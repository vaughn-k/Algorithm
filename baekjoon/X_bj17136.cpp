#include <iostream>

using namespace std;

int map[101][101];

int leftBox[] = {0,5,5,5,5,5};
int used = 0;

int di[] = {-1,0};
int dj[] = {0,-1};

void fill(int si, int sj, int able){
    for(int i = si; i<si+able; i++){
        for(int j= sj; j<sj+able; j++){
            map[i][j] = 0;
        }
    }
}

void print(){
    cout << "---- 1,2,3,4,5 : ";
    for(int i=1;i<6;i++){
        cout << leftBox[i] << " ";
    }
    cout << endl;
}

bool findBox(int si, int sj, int maxi){
    for(int i=si; i<si + maxi; i++){
        for(int j=sj; j<sj + maxi; j++){
            if(map[i][j] == 0){
                return false;
            }
        }
    }
    return true;
}

int main(){
    bool posible;
    bool pass;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cin >> map[i][j];
        }
    }
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(map[i][j] == 1){
                pass = false;
                for(int s=5;s>0;s--){
                    if(leftBox[s] > 0){
                        posible = findBox(i,j,s);
                        if(posible){
                            leftBox[s]--;
                            fill(i,j,s);
                            used++;
                            pass = true;
                        }
                    }
                }
                if(!pass){
                    cout << -1;
                    return 0;
                }
            }
        }
    }
    cout << used;
}