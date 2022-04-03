//
// Created by 최희연 on 2022/04/02.
//

#include <iostream>
using namespace std;

int ans;
int tmp;
int N, M;
int broken[11];

int many(int n){ //검사해서 만약에 고장났으면 0을 리턴, 고장난게 하나도 없으면 자릿수 리턴
    if(n==0){
        if(broken[n]) return 0;
        else return 1;
    }
    int num = 0;
    while(n!=0){
        if(broken[n%10] == true) return 0;
        num++;
        n/=10;
    }
    return num;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    cin>>N>>M;
    for(int i=0;i<M; i++){
        broken[i] = false;
    }
    for(int i=0;i<M; i++){
        cin>>tmp;
        broken[tmp] = true;
    }

    ans = N-100;
    if(ans<0) ans = -ans;

    int digit = 0;
    int diff = 0;
    for(int i=0;i<=1000000; i++){
        digit = many(i);    //자릿수 받음
        if(digit==0) continue;
        diff = i-N;
        if(diff<0) diff=-diff;
        if(ans > digit + diff) {
            ans = digit + diff;
        }
    }
    cout<<ans<<"\n";

}