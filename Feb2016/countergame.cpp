//HAS BEEN COMPLETED USING BITWISE OPERATORS

#include<iostream>
#include<math.h>
using namespace std;

int main(){
  int t;
  cin>>t;
  while(t--){
    long long int n;
    cin>>n;
    int flag = 0; //0 = Louise's Turn
    while(n > 1){
      long num = n;
      int count = 0;
      int power = 0;
      while(num > 1){
        if(num%2 == 0 && (num = num/2) == 1){
          power = 1;
        }else{
          num = num/2;
        }
        count++;
      }

      if(power){
        n = n/2;
        flag = !flag;
      }else{
        n = n - pow(2,count);
        flag = !flag;
      }

    }
    if(!flag){
      cout<<"Louise"<<endl;
    }else cout<<"Richard"<<endl;
  }


}
