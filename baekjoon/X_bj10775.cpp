#include <iostream>

using namespace std;

int g,p;
int visited[100002];
int d[100002];

int main(){
    cin >> g >> p;
    int now;
    for(int i=1;i<g+1;i++){
        visited[i] = -1;
        save[i] = i;
    }
    int cot = 0;
    int tmp;
    bool continue_  = true;
    for(int i=0;i<p;i++){
        cin >> now;
        if(continue_){
            now = save[now];
            tmp = now;
            while(visited[now] != -1 && now > 0){
                now = now - 1;
            }
            if(now == 0){
                continue_ = false;
            }
            else{
                visited[now] = 1;
                save[tmp] = now;
                cot++;
            }
        }
    }
    cout << cot;
}



// #include <iostream>

// using namespace std;

// int g,p;
// int visited[100002];
// int save[100002];

// int main(){
//     cin >> g >> p;
//     int now;
//     for(int i=1;i<g+1;i++){
//         visited[i] = -1;
//         save[i] = i;
//     }
//     int cot = 0;
//     int tmp;
//     bool continue_  = true;
//     for(int i=0;i<p;i++){
//         cin >> now;
//         if(continue_){
//             now = save[now];
//             tmp = now;
//             while(visited[now] != -1 && now > 0){
//                 now = now - 1;
//             }
//             if(now == 0){
//                 continue_ = false;
//             }
//             else{
//                 visited[now] = 1;
//                 save[tmp] = now;
//                 cot++;
//             }
//         }
//     }
//     cout << cot;
// }