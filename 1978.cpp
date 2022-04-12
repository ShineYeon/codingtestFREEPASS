//
// Created by 최희연 on 2022/04/13.
//

#include <iostream>
#include <vector>
using namespace std;
int N;
vector<int> ans;

bool isPrime(int a){
    if(a==1) return false;
    bool ok = true;
    for(int i=2; i<a; i++){
        if(a%i == 0) ok=false;
    }
    return ok;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>N;
    for(int i=0; i<N; i++){
        int tmp;
        cin>>tmp;
        if(isPrime(tmp)) ans.push_back(tmp);
    }

    cout<<ans.size()<<"\n";
}