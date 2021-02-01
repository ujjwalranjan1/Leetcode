#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N=1e5+5;
const int X=1e15;
int stmin[4*N];
int stadd[4*N];


//is addition cummutative ---yes
//no need for lazy propogation

//is minimum associative ---yes

void update(int l,int r,int idx,int ql,int qr,int val)
{
  if(l>qr || r<ql)
    return;
  if(ql<=l && r<=qr)
  {
    stadd[idx]+=val;
    stmin[idx]+=val;
    return;
  }
  int mid=(l+r)/2;
  update(l,mid,2*idx+1,ql,qr,val);
  update(mid+1,r,2*idx+2,ql,qr,val);
  stmin[idx]=min(stmin[2*idx+1],stmin[2*idx+2])+stadd[idx];
}

int findmin(int l,int r,int idx,int ql,int qr)
{
  if(l>qr || r<ql)
    return X;
  if(ql<=l && r<=qr)
    return stmin[idx];
  int mid=(l+r)/2;
  return min(findmin(l,mid,2*idx+1,ql,qr),findmin(mid+1,r,2*idx+2,ql,qr))+stadd[idx];
}





void solve()
{
  int n,m;
  cin>>n>>m;
  while(m--)
  {
    int x;
    cin>>x;
    if(x==1)
    {
      int l,r,v;
      cin>>l>>r>>v;
      r--;
      update(0,n-1,0,l,r,v);
    }
    else
    {
      int l,r;
      cin>>l>>r;
      r--;
      cout<<findmin(0,n-1,0,l,r)<<endl;
    }
    // for(int i=0;i<10;i++)
    //   cout<<st[i]<<" ";
    // cout<<endl;
  }

}


int32_t main()
{
  ios_base::sync_with_stdio(false);
   cin.tie(NULL);
  int z=1;
  //cin>>z;
  while(z--)
    solve();
  return 0;
}
