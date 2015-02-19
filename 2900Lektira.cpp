#include <iostream>
#include <stack>

using namespace std;

int main(int argc, const char *argv[])
{
  std::ios_base::sync_with_stdio(false);
  string input, output = "";
  cin >> input;

  stack<char> inversePart;

  int len = input.length();

  int neededParts = 2;
  while ( neededParts > 0 ){

    int smallestIndex = 0;
    int elementsToPop = 0;
    int j;
    for (j = 0; j < ( len-neededParts ); j++) {
       inversePart.push(input[j]);
       elementsToPop += 1;
       if (input[j] <= input[smallestIndex]) {
         if ( !( j > 0  && input[j-1] != input[j] && input[j] == input[smallestIndex] )) {
           smallestIndex = j;
           elementsToPop = 0;
         }

       }
    }
    // dcbagfekjih
    while ( elementsToPop > 0 ){

      inversePart.pop();
      elementsToPop--;

    }

    while ( !inversePart.empty() ) {
      output += inversePart.top();
      inversePart.pop();
    }

    input = input.substr(smallestIndex + 1);
    len = input.length();
    neededParts--;

  }

  // last part
  for (int i = len - 1; i >= 0; i--){

    output += input[i];

  }
  cout << output << endl;
  return 0;
}
