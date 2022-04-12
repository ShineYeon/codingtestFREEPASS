//
// Created by 최희연 on 2022/04/12.
//

#include <iostream>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    long long ans = 0;
    for(int i=1; i<=n; i++){
        ans += i*(n/i);
    }
    printf("%lld\n", ans);
}