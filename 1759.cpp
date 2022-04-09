//
// Created by 최희연 on 2022/04/09.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
char ready[16];
bool selected[16];

/*
 *
 * 암호는 서로 다른 L개의 알파벳 소문자들로 구성되며 최소 한 개의 모음(a, e, i, o, u)과 최소 두 개의 자음으로 구성되어 있다고 알려져 있다.
 * 또한 정렬된 문자열을 선호하는 조교들의 성향으로 미루어 보아 암호를 이루는 알파벳이 암호에서 증가하는 순서로 배열되었을 것이라고 추측된다.
 *
 *새 보안 시스템에서 조교들이 암호로 사용했을 법한 문자의 종류는 C가지가 있다고 한다.
 * C개의 문자들이 모두 주어졌을 때, 가능성 있는 암호들을 모두 구하는 프로그램을 작성하시오.
 */

bool check(vector<char> in) {
    int mo=0, ja=0;
    for(int i=0; i<in.size(); i++){
        if(in[i] == 'a' || in[i] =='e' || in[i] =='i' || in[i] == 'o' ||in[i]=='u'){
            mo++;
        }
        else
            ja++;
    }
    if(mo>=1 && ja>=2) return true;
    else return false;
}

/*
 * idx, start, N, M
 * if(idx==M){
        print(M);
        return;
    }
    for(int i=start; i<=N; i++){
        if(selected[i]) continue;
        selected[i] = true;
        sequence[idx] = i;
        fill(idx+1, i+1, N, M);
        selected[i] = false;
    }

 */

void sol(vector<char> tmp, int start, int now, int goal, int C) {
    if(now>goal) return;
    if(now == goal){
        if(check(tmp)) {
            for(int i=0; i<tmp.size(); i++)
                cout<<tmp[i];
            cout<<"\n";
        }
        return;
    }
    for(int i=start; i<C; i++){
        if(selected[i]) continue;
        selected[i] = true;
        tmp.push_back(ready[i]);
        sol(tmp, i+1, now+1, goal, C);
        selected[i] = false;
        tmp.pop_back();
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int L, C; //L:암호 길이, C:주어지는 문자 길이
    cin>>L>>C;
    for(int i=0; i<C; i++){
        cin>>ready[i];
    }
    sort(ready, ready+C);

    vector<char> tmp;
    sol(tmp, 0, 0, L, C);

    return 0;
}