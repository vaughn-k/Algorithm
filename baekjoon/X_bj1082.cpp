// 33m 이것도 어렵다;;

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n,k;
int cost[11];

struct Product{
    int cst;
    int num;
};

struct cmpCst{
    bool operator()(Product a, Product b){
        if(a.cst == b.cst){
            return a.num > b.num;
        }
        return a.cst > b.cst;
    }
};

struct cmpNum{
    bool operator()(Product a, Product b){
        return a.num < b.num;
    }
};

priority_queue<Product, vector<Product>, cmpCst> list;
priority_queue<Product, vector<Product>, cmpCst> able;
priority_queue<Product, vector<Product>, cmpCst> last;




int main(){
    Product product;
    Product tmpduct;
    int tmp;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> tmp;
        product.num = i;
        product.cst = tmp;
        list.push(product);
    }
    cin >> k;

    while(list.size() > 0 && k > 0){
        product = list.top();
        while(product.cst <= k){
            k = k - product.cst;
            able.push(product);
        }
        list.pop();
    }

    while()

}