#include <iostream>
#include <queue>

using namespace std;

int main(){
  queue<int> connectorTester;
  int i = 0, input;
  char response = 'Y';
  while(cin >> input){
    if (i < 5){
      connectorTester.push(input);
    }else{
      if(connectorTester.front() == input){
        response = 'N';
      }
      connectorTester.pop();
    }
    i++;
  }
  cout << response << endl;
  return 0;
}
