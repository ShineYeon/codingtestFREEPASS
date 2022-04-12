//
// Created by 최희연 on 2022/04/12.
//

#include <iostream>
#include <vector>
using namespace std;
vector<long long> sum(1000001, 1); // 자기자리에서 약수의 합
vector<long long> ans(1000001); // 자기 자리까지 모든 합


int main() {
    for(int i=2; i<=1000000; i++){
        for(int j=1; i*j<=1000000; j++){
            sum[i*j] += i;
        }
    }
    for(int i=1; i<=1000000; i++){
        ans[i] = ans[i-1] + sum[i];
    }
    int T;
    scanf("%d", &T);
    while(T--){
        int n;
        scanf("%d", &n);
        printf("%lld\n", ans[n]);
    }
}