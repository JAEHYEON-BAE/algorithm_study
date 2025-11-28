#include<iostream>
using namespace std;
int main(){cin.tie(0);int t,n,m,x;cin>>t;while(t--){cin>>n>>m;x=n*m%4;cout<<((!x)?'D':(x==1)?'W':'L');}}