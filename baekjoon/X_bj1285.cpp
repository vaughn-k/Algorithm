#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n;
char map[21][21];
int half;

int col[21]; // 세로로 다 더한개수
int row[21]; // 가로로 다 더한개수

void print(){
    cout << "------------------" << '\n';
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << map[i][j];
        }
        cout << '\n';
    }
    for(int j=0;j<n;j++){
        cout << "row " << j << " : " << row[j] << endl;
    }
    for(int j=0;j<n;j++){
        cout << "col " << j << " : " << col[j] << endl;
    }
    cout << '\n';


    cout << "------------------" << '\n';
}

void makeMap(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            col[i] = 0;
            row[j] = 0;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(map[i][j] == 'H'){
                col[j] = col[j] + 1;
                row[i] = row[i] + 1;
            }
        }
    }
}


void reverse(char c, int t){
    if(c == 'c'){
        for(int i=0;i<n;i++){
            if(map[i][t] == 'T'){
                map[i][t] = 'H';
            }
            else{
                map[i][t] = 'T';
            }
        }
    }
    else{
        for(int i=0;i<n;i++){
            if(map[t][i] == 'T'){
                map[t][i] = 'H';
            }
            else{
                map[t][i] = 'T';
            }
        }
    }

    if(c == 'c'){
        col[t] = n - col[t];
        for(int i=0;i<n;i++){
            if(map[i][t] == 'H'){
                row[i]++;
            }
            else{
                row[i]--;
            }
        }
    }
    else{
        row[t] = n - row[t];
        for(int i=0;i<n;i++){
            if(map[t][i] == 'H'){
                col[i]++;
            }
            else{
                col[i]--;
            }
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            col[i] = 0;
            row[j] = 0;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(map[i][j] == 'H'){
                col[j] = col[j] + 1;
                row[i] = row[i] + 1;
            }
        }
    }
}

int findMinRC(){
    // 가장 적은 H를 가진 열 또는 행을 reverse 한다.
    int minCol = 999;
    int minRow = 999;
    int indexCol;
    int indexRow;
    for(int i=0;i<n;i++){
        if(minCol > col[i]){
            minCol = col[i];
            indexCol = i;
        }
    }
    for(int i=0;i<n;i++){
        if(minRow > row[i]){
            minRow = row[i];
            indexRow = i;
        }
    }
    int mini;
    int index;
    char c;
    if(minRow < minCol){
        mini = minRow;
        index = indexRow;
        c = 'r';
    }
    else{
        mini = minCol;
        index = indexCol;
        c = 'c';
    }
    // cout << "maxi : " << mini << endl;
    
    if(mini <= half){
        // cout << "reverse : " << c << " index : " << index << endl;
        reverse(c, index);
        return 1;
    }  
    return 0;
}

int main(){
    string s;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> s;
        for(int j=0;j<n;j++){
            map[i][j] = s[j];
        }
    }
    if(n%2 == 0){
        half = n/2;
    }
    else{
        half = n/2 + 1;
    }
    makeMap();
    while(true){
        print();
        if(findMinRC() == 0){
            break;
        }
    }

    print();
    int tot = 0;
    for(int i=0;i<n;i++){
        tot = tot + row[i];
    }
    tot = n*n - tot;
    cout << tot;
}


/*

4
HTHT
THTH
HTHT
THTH


*/