/*/////////////////////////////////////////////////////////////////////////
날짜 : 2021.03.26

소요시간 : 1h

문제명 - 백준 14890 - 경사로
   
알고리즘
    - 구현

문제개요
    n by n 배열에서 각각 높이들이 주어지고 l길이의 경사로를 놓을 수 있을때 만들수 있는 길의 개수

    이전블록보다 현재블록이 높아질때와 낮아질때의 차이를 구분해야했다.

    (단, 이전블록과 2칸이상 차이나면 무조건 불가능)
    만약 이전블록보다 높아진다면 이미 지나왔던 블록들위에 경사로를 쌓아야하므로 쌓을수 있는 이전블록
    들 개수를 알고있어야했고

    이전블록보다 낮아진다면 이제 앞으로 경사로를 만들어야하므로 l길이가 될때까지 높이가 같은지를 확
    인해 줬어야했다.
    
    n사이즈 미스로 시간허비

*//////////////////////////////////////////////////////////////////////////


#include <iostream>

using namespace std;

int n,l;
int map[101][101];

int di[] = {1,0};
int dj[] = {0,1};

int road(int si, int sj, int direction){
    int s = si;
    int e = sj;

    int cot;
    int value;
    bool making = false; // 현재 경사로를 만드는 중인가
    int left = 0;
    for(int i=0;i<n;i++){
        // cout << " (" << si << "," << sj << ") " ;
        if(i == 0){
            cot = 1;
            value = map[si][sj];
        }
        else{
            if(making){
                if(value != map[si][sj]){
                    // cout << s << "," << e << " : no " << "<" << direction << ">" << endl;
                    return 0;
                }
                else{
                    left--;
                }
                if(left == 0){
                    making = false;
                }
            }
            else{
                if(map[si][sj] == value){ // 이전칸과 값이 같다
                    cot++;
                }
                else{
                    if(abs(map[si][sj] - value) > 1){ // 높이차가 2이상이라 불가능
                        // cout << s << "," << e << " : height " << direction << endl;
                        return 0;
                    }
                    else{ // 높이차가 1이므로 가능할수도 있음
                        if(map[si][sj] > value){ // 이전보다 올라감
                            if(cot >= l){ // 경사로 놓기 가능
                                cot = 1;
                                value = map[si][sj];
                            }
                            else{ // 경사로 놓기 불가능
                                // cout << s << "," << e << " : impossible" << direction << endl;
                                return 0;
                            }
                        }
                        else{ // 이전보다 내려감
                            if(l == 1){
                                value = map[si][sj];
                                cot = 0;
                            }
                            else{
                                left = l-1;
                                making = true;
                                value = map[si][sj];
                                cot = 0;
                            }
                        }
                    }
                }

            }
        }
        si = si + di[direction];
        sj = sj + dj[direction];
    }
    if(left > 0){
        // cout << s << "," << e << " : left " << "<" << direction << ">" << endl;
        return 0;
    }
    return 1;
}


int main(){
    cin >> n >> l;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> map[i][j];
        }
    }

    int tot = 0;
    for(int i=0;i<n;i++){
        tot = tot + road(i,0,1);
        // tot = tot + road(0,i,0);
    }
    // for(int i=0;i<n;i++){
    //     // tot = tot + road(i,0,1);
    //     tot = tot + road(0,i,0);
    // }
    cout << tot;
}

/*

6 6
1 2 3 4 5 6
1 1 1 2 1 1
1 1 1 1 1 1
1 1 1 1 3 1
1 1 1 1 5 1
5 4 3 4 5 4


*/