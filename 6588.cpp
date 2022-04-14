//
// Created by 최희연 on 2022/04/14.
//

#include <iostream>
using namespace std;
bool check[1000001];


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    check[0] = true, check[1] = true;
    for(int i=1; i*i<=1000000; i++){
        if(check[i] == false){
            for(int j=i+i; j<=1000000; j+=i){
                check[j] = true;
            }
        }
    }

    while(1){
        int n;
        cin>>n;
        if(n==0) break;
        for(int i=1; i<=n; i++){
            if(!check[i] && !check[n-i]){
                cout<<n<<" = "<<i<<" + "<<n-i<<"\n";
                break;
            }
        }
    }
}