#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

// algorithm
// Read sequentially the string until the most I can read depending on how many parts I have left
// to pick.
// While reading, if you found a smallest letter, read all other equal consecutive letters while counting.
// This way I can provide a comparison of.

string getCutPart(string s, int endIndex, int *cutIndex) {
  string cut = "";
  stack<char> inverse;

  int min = 0, toPop = 0, minSize = 1;
  inverse.push(s[0]);
  for (int i = 1; i < endIndex; i++){
    printf("Iteration %d, min %d\n", i, min);
    inverse.push(s[i]);
    toPop += 1;

    if (s[i] < s[min]){

      min = i;
      toPop = 0;

      i += 1;
      // collect all contiguous equal chars
      while ( i < endIndex && s[i] == s[min] ){
        inverse.push(s[0]);
        min = i;
        minSize++;
        i++;
      }
      i -= 1;

    }else if ( s[i] == s[min] ) {
      int tmp = i;
      int tmpSize = 1;
      i += 1;
      // collect all contiguous equal chars
      while ( i < endIndex && s[i] == s[min] ){
        inverse.push(s[0]);
        toPop++;
        tmp = i;
        tmpSize++;
        i++;
      }

      if (tmpSize > minSize) {
        minSize = tmpSize;
        min = tmp;
        toPop = 0;
      }
      i -= 1;

    }
    printf("Finished iteration %d, min %d, toPop %d\n", i, min, toPop);

  }
  printf("Finished iterations\n ");

  while ( toPop > 0 ){
    inverse.pop();
    toPop--;
  }
  cout << endl;
  while ( !inverse.empty() ){
    cut += inverse.top();
    inverse.pop();
  }
  *cutIndex = min;
  return cut;

}



int main(int argc, const char *argv[])
{
  std::ios_base::sync_with_stdio(false);

  string input, output = "";
  cin >> input;


  int len = input.length();

  int neededParts = 2;
  int cutIndex = 0;
  while ( neededParts > 0 ){

    output += getCutPart(input, len - neededParts, &cutIndex);

    input = input.substr(cutIndex + 1);
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
