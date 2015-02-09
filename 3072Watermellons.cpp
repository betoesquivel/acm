#include <iostream>

using namespace std;

int main(){
  int input = 0;
  cin >> input;
  string output = (input % 2 == 0 && input > 2) ? "YES":"NO";
  cout << output <<endl;
}
