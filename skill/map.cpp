#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <utility>
using namespace std;

// map 정의
map <string, int> gemsName;

int main(){
    // 맵에 세트 추가
    gemsName.insert(pair<string,int>("diamond",10));
    gemsName.insert(pair<string,int>("ruby",3));
    gemsName.insert(pair<string,int>("gold",2));

    // 맵에 원소 존재여부 확인
    vector<string> v;
    v.push_back("diamond");
    v.push_back("ruby");
    v.push_back("silver");
    for(int i=0;i<v.size();i++){
        if(gemsName.find(v[i]) == gemsName.end()){
            cout << "map에 " << v[i] << "(이)가 존재하지 않습니다" << endl;
        }
        else{
            cout << "map에 " << v[i] << "(이)가 존재합니다" << endl;
        }
    }

    // 키값 찾기
    for(int i=0;i<v.size()-1;i++){
        if(gemsName.find(v[i]) != gemsName.end()){ // 존재할때만 진입
            cout << v[i] << "의 키값은 " << gemsName.at(v[i]) << endl;
        }
    }

}