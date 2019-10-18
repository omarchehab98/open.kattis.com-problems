#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#define ll long long
using namespace std;
char a[100005];
int n;
ll ans=0, cnt[100005][26], p[26];
int main() {
  cin >> (a + 1);
  n = strlen(a + 1);
  for(int i=0;i<26;i++) {
    p[i] = 0;
  }
  for(int i=1;i<=n;i++) {
    int l = (int)(a[i]-'a');
    int idx = p[l];
    
    ll uni = 0;
    for(int j=0;j<26;j++) {
      if(cnt[i-1][j] - cnt[idx][j] > 0) uni++;
    }
    //cout<<i<<" "<<idx<<" "<<uni<<endl;
    for(int j=0;j<26;j++) {
      cnt[i][j] = cnt[i-1][j];
      if(j==l) cnt[i][j]++;
    }
    ans += uni;
    p[l] = i;
  }
  /*for(int i=1;i<=n;i++){
  for(int j=0;j<26;j++) cout<<cnt[i][j]<<"";
  cout<<endl;
  }*/
  cout<<ans<<endl;
  return 0;
}