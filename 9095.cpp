//
// Created by 최희연 on 2022/04/09.
//

#include <iostream>
using namespace std;

// n을 만드는 경우의 수
int sol(int ans, int n) {
    if(ans > n) return 0;
    if(ans == n) return 1;
    int now = 0;
    for(int i=1; i<=3; i++){
        now += sol(ans+i, n);
    }
    return now;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>> n;
        cout<<sol(0, n)<<"\n";
    }
    return 0;

}