#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
int main(int argc, const char *argv[])
{
  int qX[8], qY[8];

  string line = "";
  int row = 0;
  int x = 0;
  int queenCount = 0;
  string response = "valid";
  while (row < 8){
    getline(cin, line);
    for (int i = 0; i<line.length(); i++){
        x = line.find("*", i);
        if (x >= 0){
          i = x;
          qX[queenCount] = i;
          qY[queenCount] = row;
          queenCount++;
        }else{
          i = line.length();
        }
    }
    row++;
  }

  for (int i = 0; i<7; i++){
    for (int j = i+1; j<8; j++){
      if( qX[i]==qX[j] || qY[i]==qY[j] || abs( qX[i] - qX[j] ) == abs( qY[i] - qY[j] ) ){
        response = "invalid";
        break;
      }
    }
  }
  cout << response << endl;
  return 0;
}
