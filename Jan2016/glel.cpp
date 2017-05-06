#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int goodCount(int v[],long n,long k){
  long last = -1;
  long first0 = -1;
  int f = 1;
  long start = 0;
  long count = 0;
  long i = 0;
  while(start<n){
    for(i=start;i<start+k && i<n;i++){
      if(v[i] == 1){
        last = i;
      }else {
        if(f){
          first0 = i;
          f = 0;
        }
      }
    }
    if(last == -1){
      long pos = first0;
      long it = -1;
      while(pos >= first0-k+1){
        if(v[pos] == 3){
          it = pos;
          break;
        }
        pos--;
      }
      if(it == -1){
        return -1;
      }
      for(i = it;i<=(it+k-1);i++){
        if(v[i] == 0){
          v[i] = 2;
        }else v[i] = 3;
      }
      start = i;
      last = -1;
      f = 1;
      count++;
      continue;
    }
    if(last-k+1 >= 0){
      i = last - k + 1;
    }else i = 0;
    for(;i<=(last+k-1) && i<n;i++){
      if(v[i] == 0){
        v[i] = 2;
      }else v[i] = 3;
    }
    start = i;
    last = -1;
    f = 1;
    count++;
  }
  return count;
}

int goodCountRev(int v[],long n,long k){
  long last = -1;
  long first0 = -1;
  int f = 0;
  long start = n-1;
  long count = 0;
  long i = 0;
  while(start>=0){
    f = 1;
    for(i=start;i>start-k && i>=0;i--){
      if(v[i] == 1){
        last = i;
      }else{
        if(f){
          first0 = i;
        }
      }
    }
    if(last == -1){
      long pos = first0;
      long it = -1;
      while(pos<=first0+k-1){
        if(v[pos] == 3){
          it = pos;
          break;
        }
        pos++;
      }
      if(it == -1){
        return -1;
      }
      for(i=it;i>=(it-k+1);i--){
        if(v[i] == 0){
          v[i] = 2;
        }else v[i] = 3;
      }
      start = i;
      last = -1;
      count++;
      continue;
    }

    if(last+k-1 < n){
      i = last + k - 1;
    }else i = n-1;
    for(;i>=0 && i>=(last-k+1);i--){
      if(v[i] == 0){
        v[i] = 2;
      }else v[i] = 3;
    }
    start = i;
    last = -1;
    count++;
    continue;
    start = i;
    last = -1;
    count++;
  }
  return count;
}

int main(){
  int v[100000];
  int a[100000];
  long n,k;
  cin>>n>>k;

  for(long i=0;i<n;i++){
    cin>>v[i];
    a[i] = v[i];
  }
  int x = goodCount(v,n,k);
  int y = goodCountRev(a,n,k);
  if(x == -1){
    cout<<y<<endl;
  }else if(y==-1){
    cout<<x<<endl;
  }else cout<<(x<y?x:y);


}
