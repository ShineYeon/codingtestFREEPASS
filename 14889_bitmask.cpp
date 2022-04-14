//
// Created by 최희연 on 2022/04/14.
//

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int synergy[21][21];


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin>>n;
    int ans=98765432;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>synergy[i][j];
        }
    }
    for(int i=(1<<(2/n + 1))-1; i<(1<<n); i++){

        vector<int> t1;
        vector<int> t2;

        for(int j=0; j<n; j++){
            if(i&(1<<j)) t1.push_back(j);
            else t2.push_back(j);
        }

        if(t1.size()!=n/2 && t2.size()!=n/2) continue;
        //점수 계산
        int s1=0, s2=0;
        for(int j=0; j<t1.size(); j++){
            for(int k=0; k<t1.size();k++){
                s1+=synergy[t1[j]][t1[k]];
            }
        }
        for(int j=0; j<t2.size(); j++){
            for(int k=0; k<t2.size(); k++){
                s2+=synergy[t2[j]][t2[k]];
            }
        }
        int diff=s1-s2;
        if(diff<0) diff=-diff;
        ans=min(ans, diff);
    }



    cout<<ans<<"\n";

}