#include <iostream>
#include <string>
#include <vector>

using namespace std;

string core;
vector<string> s;
string s1;
string s2;
int n,k;

int save[101][21][2];

int main(){
    cin >> core >> s1 >> s2;
    s.push_back(s1);
    s.push_back(s2);
    n = s1.size();
    k = core.size();
    for(int i=0;i<101;i++){
        for(int j=0;j<21;j++){
            for(int k=0;k<2;k++){
                save[i][j][k] = 0;
            }
        }
    }
    int p;
    for(int i=0;i<k;i++){
        for(int j=0;j<n;j++){
            if(i == 0){
                if(core[i] == s[0][j]){
                    save[j][i][0] = 1;
                }
                if(core[i] == s[1][j]){
                    save[j][i][1] = 1;
                }
            }
            else{
                if(core[i] == s[0][j]){
                    for(int k=0;k<j;k++){
                        save[j][i][0] = save[j][i][0] + save[k][i-1][1];
                    }
                }
                if(core[i] == s[1][j]){
                    for(int k=0;k<j;k++){
                        save[j][i][1] = save[j][i][1] + save[k][i-1][0];
                    }
                }
            }
        }
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        ans = ans + save[i][k-1][0] + save[i][k-1][1];
    }

    // for(int i=0;i<k;i++){
    //     for(int p=0;p<=1;p++){
    //         for(int j=0;j<n;j++){
    //             cout << save[j][i][p] << " ";
    //         }
    //         cout << endl;
    //     }
    //     // cout << endl;
    // }

    cout << ans;
}