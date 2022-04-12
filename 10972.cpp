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
        int tmp;
        cin>>tmp;
        vi.push_back(tmp);
    }
    if(next_permutation(vi.begin(), vi.end())){
        for(int i=0; i<vi.size(); i++){
            cout<<vi.at(i)<<" ";
        }
        cout<<"\n";
    }
    else cout<<"-1\n";
    return 0;

}