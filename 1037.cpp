//
// Created by 최희연 on 2022/04/12.
//


#include <iostream>
using namespace std;
int arr[51];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    sort(arr, arr+n);
    cout<<arr[0]*arr[n-1]<<"\n";

}