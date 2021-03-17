/*/////////////////////////////////////////////////////////////////////////
소요시간 : 15m

문제명 - 백준 9576 - 책 나눠주기
    (회의실 문제와 비슷)
알고리즘
    - 그리디
    - 우선순위큐(2개 전달형)
    - 받을수있는 책구간 제한 + 최대로 책 나눠주기

문제개요
    n개의 책이 있고 각 m명의 학생이 각각 가져갈수있는 책 시작번호와 끝번호가 있을때
    최대한 많은 사람이 책을 가져가게 하고싶을때 그 수는?

*//////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int t,n,m;

struct Book{
    int start;
    int end;
};

struct cmpEnd{
    bool operator()(Book a, Book b){
        return a.end < b.end;
    }
};

struct cmpStart{
    bool operator()(Book a, Book b){
        return a.start < b.start;
    }
};

priority_queue<Book, vector<Book>, cmpEnd> pqEnd;
priority_queue<Book, vector<Book>, cmpStart> pqStart;

int main(){
    Book book;
    int t1,t2,tot;
    cin >> t;
    for(int i=0;i<t;i++){
        while(pqEnd.size() > 0){pqEnd.pop();}
        while(pqStart.size() > 0){pqStart.pop();}
        cin >> n >> m;
        for(int j=0;j<m;j++){
            cin >> t1 >> t2;
            book.start = t1;
            book.end = t2;
            pqEnd.push(book);
        }
        tot = 0;
        for(int num=n; num>0; num--){
            while(pqEnd.size() > 0){
                if(pqEnd.top().end == num){
                    pqStart.push(pqEnd.top());
                    pqEnd.pop();
                }
                else{
                    break;
                }
            }

            while(pqStart.size() > 0){
                if(pqStart.top().start > num){
                    pqStart.pop();
                }
                else{
                    pqStart.pop();
                    tot++;
                    break;
                }
            }
        }
        cout << tot << endl;
    }

}