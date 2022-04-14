//
// Created by 최희연 on 2022/04/14.
//

#include <iostream>
using namespace std;
bool check[1000001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    check[0] = false, check[1] = true;
    for(int i=2; i*i<=1000000; i++){
        if(check[i] == false){
            for(int j=i+i; j<=1000000; j+=i){
                check[j] =true;
            }
        }
    }

    int M, N;
    cin>>M>>N;
    for(int i=M; i<=N; i++){
        if(check[i] == false)
            cout<<i<<"\n";
    }
    return 0;
}