#include <iostream>
#include <stack>

using namespace std;

// algorithm
// Read sequentially the string until the most I can read depending on how many parts I have left
// to pick.
// While reading, if you found a smallest letter, read all other equal consecutive letters while counting.
// This way I can provide a comparison of.

string getCutPart(string s, int endIndex) {
  string cut = "";
  stack<char> inverse;

  int min = 0, toPop = 0, minSize = 1;
  inverse.push(s[0]);
  for (int i = 1; i < endIndex; i++){
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

  }

  while ( toPop > 0 ){
    inverse.pop();
  }
  while ( !inverse.empty() ){
    cut += inverse.top();
    inverse.pop();
  }
  return cut;

}



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
    int smallestIndexSize = 1;
    int elementsToPop = 1;
    int j;
     inversePart.push(input[j]);
     elementsToPop += 1;
    for (j = 1; j < ( len-neededParts ); j++) {
       inversePart.push(input[j]);
       elementsToPop += 1;
       if (input[j] < input[smallestIndex]) {
         smallestIndex = j;
         elementsToPop = 0;
         smallestIndexSize = 1;
         // eat all the same contiguous letters
         for ( j = j+1; j < (len - neededParts) ; j++){
             if(input[j] != input[smallestIndex]) { j-=1; break; }
             smallestIndexSize+=1;
             smallestIndex = j;
             inversePart.push(input[j]);
             elementsToPop += 1;
         }
       }else if (input[j] == input[smallestIndex]){
         // found an equal smallest letter
         // Now I have to keep the one that repeats itself the most
         int indexRepetitions = 1;
         int tempIndex = j;
         for ( j = j+1; j < (len - neededParts) ; j++){
             if(input[j] != input[tempIndex]) { break; }
             indexRepetitions+=1;
             tempIndex = j;
             inversePart.push(input[j]);
             elementsToPop += 1;
         }
         if (indexRepetitions > smallestIndexSize) {
             smallestIndex = j - 1;
             smallestIndexSize = indexRepetitions;
             elementsToPop = 0;
         }

       }
    }
    // dcbagfekjih
    // anakonda
    // bbabbbdddxddddaa
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
