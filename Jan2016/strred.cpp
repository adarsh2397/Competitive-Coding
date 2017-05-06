#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;

int countLetters(char str[101],char a){
  int n = strlen(str);
  int count = 0;
  for(int i=0;i<n;i++){
    if(str[i] == a)
      count++;
  }

  return count;
}
void number(int a, int b, int c){
  if((a+b+c)%2){
    if(a%2 == 0 || b%2 ==0){
      cout<<1<<endl;
    }else{
      cout<<2<<endl;
    }
  }else{
    if(a%2 || b%2){
      cout<<1<<endl;
    }else{
      cout<<2<<endl;
    }
  }
}
int main(){
  int t;
  cin>>t;
  while(t){
    char str[101];
    cin>>str;
    int n = strlen(str);
    int a = countLetters(str,'a');
    int b = countLetters(str,'b');
    int c = countLetters(str,'c');


    if(a == 0 && b == 0 && c){
      cout<<c<<endl;
    }else if(c == 0 && b == 0 && a){
      cout<<a<<endl;
    }else if(a == 0 && c == 0 && b){
      cout<<b<<endl;
    }else number(a,b,c);

    t--;
  }
}


/*


int i=0;
while(i<n){
  if(str[i]!=str[i+1]){
    char c;
    if(str[i]+str[i+1] == 195){
      c = 'c';
    }else if(str[i] + str[i+1] == 196){
      c = 'b';
    }else if(str[i] + str[i+1] == 197){
      c = 'a';
    }
    for(int k=i;k<n;k++){
      str[k] = str[k+1];
    }
    str[i] = c;
    n--;
    i = 0;
    continue;
  }
  i++;
  cout<<str<<endl;

*/
