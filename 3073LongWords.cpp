#include <iostream>

using namespace std;

int main(){
  string s;
  int N, length;
  cin >> N;
  while (N > 0){
    cin >> s;
    length = s.length();
    if (length > 10){
      cout << s[0] << length - 2 << s[length-1] << endl;
    }else{
      cout << s << endl;
    }

    N--;
  }

  return 0;
}
