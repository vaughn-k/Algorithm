#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int n;
vector<string> v;
unsigned long long alph[26];
int zero[26];
int zeroCount = 10; // 0이 될수있는개수

struct Alphabet{
    unsigned long long value;
    int index;
};

struct cmp{
    bool operator()(Alphabet a, Alphabet b){
        return a.value < b.value;
    }
};

priority_queue<Alphabet, vector<Alphabet>,cmp > pq;

int main(){
    string s;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> s;
        v.push_back(s);
    }
    for(int i=0;i<n;i++){
        zero[i] = 1;
    }

    int index;
    unsigned long long mtp;
    for(int i=0;i<n;i++){
        if(zero[v[i][0] - 65] == 1){
            zeroCount--;
            zero[v[i][0] - 65] = 0; // zero 인지 아닌지
        }
        mtp = 1;
        for(int j=v[i].size()-1;j>=0;j--){
            index = v[i][j] - 65;
            alph[index] += mtp;
            mtp *= 10;
        }
    }

    Alphabet alphabet;
    for(int i=0;i<26;i++){
        if(alph[i] > 0){
            alphabet.value = alph[i];
            alphabet.index = i;
            pq.push(alphabet);
        }
    }
    unsigned long long tot = 0;
    int nowNumber = 9;
    while(pq.size() > 0){
        alphabet = pq.top();
        pq.pop();


        if(zero[alphabet.index] == 1){ // 0 가능한 알파벳
            if(zeroCount ==  0){
                tot = tot + nowNumber * alphabet.value;
                nowNumber--;
            }
            zeroCount--;
        }
        else{ // 0이 절대 될수없는 알파벳
            tot = tot + nowNumber * alphabet.value;
            nowNumber--;
        }
    }
    cout << tot;
}

/*
10
A
B
C
D
E
F
G
H
I
I


*/