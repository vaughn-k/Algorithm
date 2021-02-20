#include <iostream>
#include <string>

using namespace std; 
string original, example;
int store[2000][2000];

int wildcard(int ori, int ex){
    if(ori == original.size()){
        if(ex == example.size()){
            // cout <<"1 || " << ori << " , " << ex << endl;
            return 1;
        }
        else{
            return 0;
        }
    }
    if(ex == example.size()){
        for(int i = ori; i<original.size(); i++){
            // cout << "now compare " << original.at(ori) << " : " << endl;
            if(original.at(i) != '*'){
                return 0;
            }
        }
        // cout <<"2 || " << ori << " , " << ex << endl;
        return 1;
    }

    int success = 0;
    if(store[ori][ex] != -1){
        return store[ori][ex];
    }


    // cout << "pass" << endl;
    if(original.at(ori) == '*'){
        success = success + wildcard(ori+1, ex);
        success = success + wildcard(ori+1, ex+1);
        success = success + wildcard(ori, ex+1);
    }
    if(original.at(ori) == '?'){
        success = success + wildcard(ori+1, ex+1);
    }
    else{
        if(original.at(ori) == example.at(ex)){
            success = success + wildcard(ori+1,ex+1);
        }
    }
    if(success > 0){
        store[ori][ex] = 1;
        return 1;
    }
    else{
        store[ori][ex] = 0;
        return 0;
    }
}

int main(){
    cin >> original;
    cin >> example;

    for(int i = 0;i < 2000; i++){
        for(int j=0 ; j < 2000; j++){
            store[i][j] = -1;
        }
    }

    int ans = wildcard(0,0);
    if(ans == 1){
        cout << "find it" << endl;
    }
    else{
        cout << "not founded" << endl;
    }
}