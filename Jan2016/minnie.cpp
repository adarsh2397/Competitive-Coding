//She's my little Minnie Mouse
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

bool select_a(pair<long, long> a,pair<long, long> b){
  return a.second>b.second;
}

int main(){
  long n,q;
  cin>>n>>q;

  vector<long long> v;
  vector<long long> sum;
  vector<pair<long, long> > m;
  m.resize(100000);
  sum.resize(100000);

  for(long i=0;i<n;i++){
    long long data;
    cin>>data;
    v.push_back(data);
  }

  vector<long> l;
  vector<long> r;
  for(long i=0;i<q;i++){
    long l_data,r_data;
    cin>>l_data;
    cin>>r_data;
    l.push_back(l_data);
    r.push_back(r_data);
    for(long x = l_data;x<=r_data;x++){
      m[x].second++;
      m[x].first = x;
    }
  }

  sort(m.begin(),m.end(),select_a);

  make_heap(v.begin(),v.end());

  long i=0;
  while(m[i].second != 0){
    sum[m[i].first] = v.front();
    pop_heap (v.begin(),v.end());
    v.pop_back();
    if(i>0){
      if(m[i].second == m[i-1].second && m[i].first > m[i-1].first){
        long long temp = sum[m[i].first];
        sum[m[i].first] = sum[m[i-1].first];
        sum[m[i-1].first] = temp;
      }
    }
    i++;
  }

  for(long i=0;i<q;i++){
    long long sumT = 0;
    for(long x = l[i];x<=r[i];x++){
      sumT += sum[x];
    }
    cout<<sumT<<endl;
  }

  long x = 0;



}
