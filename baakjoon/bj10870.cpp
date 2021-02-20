#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int n;
vector<int> v;

int main(){
    v.push_back(0);
    v.push_back(1);
    for(int i=2;i<21;i++){
        v.push_back(v[i-2] + v[i-1]);
    }

    cin >> n;
    cout << v[n];
} 