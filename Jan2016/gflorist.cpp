#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
  int n,k;
  cin>>n;
  cin>>k;

  vector<long> c;
  for(int i=0;i<n;i++){
    long data;
    cin>>data;
    c.push_back(data);
  }

  sort(c.begin(),c.end());

  long int cost = 0;
  int x = 1;
  for(int i=n-1,j=1;i>=0;i--,j++){
    if(j>k){
      x++;
      j = 0;
      i++;
      continue;
    }
    cost += (x)*c[i];
  }

  cout<<cost<<endl;
}
