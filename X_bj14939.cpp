#include <iostream>

using namespace std;

int p[10][10];

int tt = 0;

int di[] = {-1,0,0,0,1};
int dj[] = {0,-1,0,1,0};
int si[] = {-2,0,0,0,2};
int sj[] = {0,-2,0,2,0};
int count_ = 0;

// void print(){
//     cout << "------------------------" << endl;
//     for(int i=0;i<10;i++){
//         for(int j=0;j<10;j++){
//             if(p[i][j] == 1){
//                 cout << 'O';
//             }
//             else{
//                 cout << '#';
//             }
//         }
//         cout << endl;
//     }
//     cout << "------------------------" << endl;
// }



int sth(int n){
    if(n == 1){
        return 0;
    }
    else {
        return 1;
    }
}

bool spe(){
    int turn_off = false;
    int xi,xj,total;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            total = 0;
            for(int k=0;k<5;k++){
                xi = i + si[k];
                xj = j + sj[k];
                if(xi >= 0 && xj >= 0 && xi < 10 && xj < 10){
                    if(p[xi][xj] == 1){
                        total = total + 1;
                    }
                }
                else{
                    total = -10000;
                }
            }
            if(total == 5){
                count_ = count_ + 4;
                turn_off = true;
                tt = tt - 5;
                for(int k=0;k<5;k++){
                    xi = i + si[k];
                    xj = j + sj[k];
                    p[xi][xj] = 0;
                }
            }
            if(total == 4){
                count_ = count_ + 4;
                turn_off = true;
                tt = tt - 3;
                for(int k=0;k<5;k++){
                    xi = i + si[k];
                    xj = j + sj[k];
                    p[xi][xj] = sth(p[xi][xj]);
                }

            }
        }
    }
    return turn_off;
}

bool run(int n){
    int total;
    int turn_off = false;
    // 자신 주변에 켜진전구가 n개일때만 끈다.
    // 하나라도 껐다면 1리턴, 하나도 못껏다면 0리턴
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            total = 0;
            for(int k=0;k<5;k++){
                if(i+di[k] >= 0 && j+dj[k] >= 0 && i+di[k] < 10 && j+dj[k] < 10){
                    if(p[i+di[k]][j+dj[k]] == 1){
                        total = total + 1;
                    }
                }
                else{
                    total = -10000;
                }
            }
            if(total == n){
                turn_off = true;
                count_++;
                for(int k=0;k<5;k++){
                    p[i+di[k]][j+dj[k]] = sth(p[i+di[k]][j+dj[k]]);
                }
                if(n == 5){
                    tt = tt - 5;
                }
                else if(n == 4){
                    tt = tt - 3;
                }
                else{
                    tt = tt - 1;
                }
            }
        }
    }
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            total = 0;
            for(int k=0;k<5;k++){
                if(i+di[k] >= 0 && j+dj[k] >= 0 && i+di[k] < 10 && j+dj[k] < 10){
                    if(p[i+di[k]][j+dj[k]] == 1){
                        total = total + 1;
                    }
                }
                else{
                    total = -10000;
                }
            }
            if(total == n){
                turn_off = true;
                count_++;
                for(int k=0;k<5;k++){
                    p[i+di[k]][j+dj[k]] = sth(p[i+di[k]][j+dj[k]]);
                }
                if(n == 5){
                    tt = tt - 5;
                }
                else if(n == 4){
                    tt = tt - 3;
                }
                else{
                    tt = tt - 1;
                }
            }
        }
    }
    // print();
    return turn_off;
}

int main_run(){
    bool check = true;
    int now = 5;
    while(check){
        if(!run(now)){ // now 개 끄러갔는데 실패한경우
            now = now -1;
            if(now == 2){
                if(spe()){ // 마지막 다이아몬드 발견
                    now = 5;
                }
                else{
                    check = false;
                }
            }
        }
        else{
            now = 5;
        }
        if(tt == 0){
            return 1;
        }
    }
    return -1;
}

int main(){
    char tmp;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cin >> tmp;
            if(tmp == '#'){
                p[i][j] = 0;
            }
            else{
                p[i][j] = 1;
                tt++;
            }
        }
    }

    if(main_run() == 1){
        cout << count_;
    }
    else{
        cout << -1;
    }
}

/*

##########
###O###O##
##########
#O#O###O#O
##########
###O###O##
##########
#######OO#
######O##O
#######OO#


*/