//
// Created by 최희연 on 2022/04/09.
//

//
// Created by 최희연 on 2022/04/09.
//

#include <iostream>
#include <algorithm>
using namespace std;
int N;
int times[16];
int pay[16];
int ans = 0;

void sol(int now, int sum) {
    if(now == N) {
        ans = max(ans, sum);
        return;
    }
    if(now>N) return;

    sol(now+1, sum);
    sol(now+times[now], sum+pay[now]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>times[i]>>pay[i];
    }
    sol(0, 0);
    cout<<ans<<"\n";
}