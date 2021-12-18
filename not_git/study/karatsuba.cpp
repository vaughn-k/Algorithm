#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std; 
int maximum_length = 10;


// int basic_karatsuba_algorithm(){
//     vector<int> v(maximum_length);
    

// }

void print_vector(vector<int>& a){
    int i;
    cout << "-------------------" << endl;
    for(i=0;i<a.size();i++){
        cout << "index [" << i << "] = " << a[i] << endl;
    }
    cout << "-------------------" << endl;
}

vector<int> ten_shift(vector<int>& c){
    // cout << "check2";
    int i;
    for(i = c.size()-1; i >= 1; i--){
        if(c[i] > 9){
            c[i-1] = c[i-1] + c[i]/10;
            c[i] = c[i]%10;
            // cout << "now c[";
            // cout << i;
            // cout << "] = ";
            // cout << c[i] << endl;
        }
    }
    return c;
}

vector<int> normal_muli(const vector<int>& a,const vector<int>& b){
    // cout << "check1";
    int i,j;
    vector<int> c(a.size() + b.size());
    for(i = 0; i < a.size() ; i++){
        for(j = 0; j < b.size() ; j++){
            c[i+j+1] = c[i+j+1] + a[i] * b[j];
        }
    }
    for(int i = 0 ; i < 9; i++){
        cout << c[i];
        cout << " / ";
    }
    cout << endl;

    return ten_shift(c);
}

// a * 10^k + b
vector<int> add_vector(vector<int> a, vector<int> b, int k){
    int len = max(a.size() + k, b.size());
    vector<int> c(len,0);
    int i;
    for(i = 0;i < a.size(); i++){
        c[i] = a[i];
    }
    for(i = 0;i < b.size(); i++){
        c[a.size()-1+i] = c[a.size()-1+i] + b[i];
    }


}

vector<int> karatsuba(vector<int> a, vector<int> b){
    if(a.size() < b.size()){
        return karatsuba(b, a);
    }
    if(a.size() < 50){
        return normal_muli(a, b);
    }

    int half = a.size()/2;
    vector<int> a1(a.begin(), a.begin() + half);
    vector<int> a2(a.begin() + half, a.end());
    vector<int> b1(b.begin(), b.begin() + min<int>(half, b.size()));
    vector<int> b2(b.begin() + min<int>(half, b.size()), b.end());

    vector<int> z1 = karatsuba(a1,b1);
    vector<int> z2 = karatsuba(add_vector(a1,a2,0),add_vector(b1,b2,0));
    vector<int> z3 = karatsuba(a2,b2);
    
    return 
    

}



int main(){
    // vector를 이용한 곱셈
    vector<int> A(5),B(4),C(8);
    int len, input;

    // cout << "enter A : " << endl;
    // cin >> len;
    for(int i = 0 ; i < 5 ; i++){
        cin >> input;
        A[i] = input;
    }

    // cout << "enter B : " << endl;
    // cin >> len;
    for(int i = 0 ; i < 4 ; i++){
        cin >> input;
        B[i] = input;
    }

    // for(int i = 0 ; i < maximum_length ; i++){
    //     cout << A[i];
    // }
    // cout << endl;
    // for(int i = 0 ; i < maximum_length ; i++){
    //     cout << B[i];
    // }

    vector<int> X = normal_muli(A,B);
    print_vector(X);

    int half = X.size()/2;
    vector<int> Y1(X.begin(), X.begin() + half);
    vector<int> Y2(X.begin() + half, X.end());
    print_vector(Y1);
    print_vector(Y2);




    return 0;
}

