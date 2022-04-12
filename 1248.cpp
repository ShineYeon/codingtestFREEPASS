//
// Created by 최희연 on 2022/04/12.
//

#include <iostream>
#include <string>
using namespace std;

int N;
string s;
int sign[11][11];
int num[11];

bool check(int idx) {
    int sum=0;
    for(int i=idx; i>=0; i--){
        sum+=num[i];
        if(sign[i][idx]>0){
            if(sum<=0) return false;
        }
        else if(sign[i][idx]<0){
            if(sum>=0) return false;
        }
        else if(sign[i][idx]==0){
            if(sum!=0) return false;
        }

    }
    return true;
}

bool go(int idx){
    if(idx==N){
        return true;
    }
    if(sign[idx][idx]==0){
        num[idx] = 0;
        return check(idx)&&go(idx+1);
    }
    for(int i=1;i<=10;i++){

        num[idx] = sign[idx][idx]*i;
        if(check(idx) && go(idx+1)) return true;
    }
    return false;

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>N;
    cin>>s;
    int cnt=0;
    for(int i=0; i<N; i++){
        for(int j=i; j<N; j++){
            if(s[cnt] == '0')
                sign[i][j] = 0;
            else if(s[cnt]=='+')
                sign[i][j] = 1;
            else if(s[cnt]=='-')
                sign[i][j]=-1;

            cnt++;
        }
    }

    go(0);
    for(int i=0; i<N; i++)
        cout<<num[i]<<" ";
    cout<<"\n";
    return 0;
}