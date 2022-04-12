//
// Created by 최희연 on 2022/04/12.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int k;
int s[14];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    while(1){
        cin>>k;
        if(k==0) return 0;

        vector<int> vi;
        vector<vector<int>> vi2;

        for(int i=0; i<k; i++){
            cin>>s[i];
        }
        for(int i=0; i<6; i++){
            vi.push_back(1);
        }
        for(int i=0; i<(k-6); i++){
            vi.push_back(0);
        }
        do{
            vector<int> tmp;
            for(int i=0; i<k; i++){
                if(vi[i] == 1){
                    tmp.push_back(s[i]);
                }
                else continue;
            }
            vi2.push_back(tmp);
        }while(prev_permutation(vi.begin(), vi.end()));

        for(int i=0; i<vi2.size(); i++){
            for(int j=0; j<vi2[i].size(); j++){
                cout<<vi2[i][j]<<" ";
            }
            cout<<"\n";

        }
        cout<<"\n";
    }
}