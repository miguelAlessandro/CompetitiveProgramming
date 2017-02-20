#include<iostream>
using namespace std;int a[100],n,r,p,q,i,j;main(){cin>>n;while(cin>>n){r=0;for(i=0;i<n;++i)for(j=0;j<=i;++j){if(!i)p=0,q=0;else if(!j)p=0,q=a[0];else if(j!=i)p=q,q=a[j];else p=q,q=0;cin>>a[j];r=max(r,a[j]+=max(p,q));}cout<<r<<'\n';}}
