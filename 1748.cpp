//
// Created by 최희연 on 2022/04/06.
//

#include <iostream>
using namespace std;
//100,000,000


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin>>n;
    long long ans = 0;
    for(int start=1, len=1; start<=n; start*=10, len++){
        int end = start*10-1;
        if(end > n) end=n;
        ans+= (long long)(end-start+1) * len;
    }
    cout<<ans<<"\n";
    return 0;


}