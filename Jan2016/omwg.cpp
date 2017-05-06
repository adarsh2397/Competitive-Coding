#include<iostream>
using namespace std;

int main(){

  int t;
  cin>>t;
  while(t){
    int m,n;
    cin>>m;
    cin>>n;
    long answer = 0;

    if(m==1){
      cout<<n-1<<endl;
      t--;
      continue;
    }else if(n==1){
      cout<<m-1<<endl;
      t--;
      continue;
    }

    answer = (m-2)*(n-2);
    answer /= 2;
    answer *= 4;
    if(m%2&& n%2){
      answer += (m+n-2)*3;
    }else answer += (m+n-4)*3 + 4;

    cout<<answer<<endl;

    t--;
  }

  return 0;

}
