#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#define ll long long
using namespace std;
ll T,n,m, a;
int main() {
    cin >>T;
    while(T--) {
        cin>>n>>m;
        a = n + m + 1;
        //ll r = a*(a+1)/2;
        ll l = a*(a-1)/2 +1;
        cout << l+m <<endl;
    }
    return 0;
}