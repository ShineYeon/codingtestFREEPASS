//
// Created by 최희연 on 2022/04/12.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int N;
    cin>>N;
    vector<int> vi;
    for(int i=0; i<N; i++){
        vi.push_back(i+1);
    }
    do{
        for(int i=0; i<vi.size(); i++){
            cout<<vi.at(i)<<" ";
        }
        cout<<"\n";
    }while(next_permutation(vi.begin(), vi.end()));
    return 0;


}