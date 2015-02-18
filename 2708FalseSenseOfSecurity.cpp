#include <iostream>
#include <cstdio>
#include <map>
#include <stack>
#include <queue>

using namespace std;

int main(int argc, const char *argv[])
{
  string encoded = "";
  map<string,char> morseLetters;
  map<char, string> lettersMorse;

  // fill the alphabet
  morseLetters[".-"  ] = 'A';
  morseLetters["-..."] = 'B';
  morseLetters["-.-."] = 'C';
  morseLetters["-.." ] = 'D';
  morseLetters["."   ] = 'E';
  morseLetters["..-."] = 'F';
  morseLetters["--." ] = 'G';
  morseLetters["...."] = 'H';
  morseLetters[".."  ] = 'I';
  morseLetters[".---"] = 'J';
  morseLetters["-.-" ] = 'K';
  morseLetters[".-.."] = 'L';
  morseLetters["--"  ] = 'M';
  morseLetters["-."  ] = 'N';
  morseLetters["---" ] = 'O';
  morseLetters[".--."] = 'P';
  morseLetters["--.-"] = 'Q';
  morseLetters[".-." ] = 'R';
  morseLetters["..." ] = 'S';
  morseLetters["-"   ] = 'T';
  morseLetters["..-" ] = 'U';
  morseLetters["...-"] = 'V';
  morseLetters[".--" ] = 'W';
  morseLetters["-..-"] = 'X';
  morseLetters["-.--"] = 'Y';
  morseLetters["--.."] = 'Z';
  morseLetters["..--"] = '_';
  morseLetters["---."] = '.';
  morseLetters[".-.-"] = ',';
  morseLetters["----"] = '?';
  // fill the alphabet
  lettersMorse['A'] = ".-"  ;
  lettersMorse['B'] = "-...";
  lettersMorse['C'] = "-.-.";
  lettersMorse['D'] = "-.." ;
  lettersMorse['E'] = "."   ;
  lettersMorse['F'] = "..-.";
  lettersMorse['G'] = "--." ;
  lettersMorse['H'] = "....";
  lettersMorse['I'] = ".."  ;
  lettersMorse['J'] = ".---";
  lettersMorse['K'] = "-.-" ;
  lettersMorse['L'] = ".-..";
  lettersMorse['M'] = "--"  ;
  lettersMorse['N'] = "-."  ;
  lettersMorse['O'] = "---" ;
  lettersMorse['P'] = ".--.";
  lettersMorse['Q'] = "--.-";
  lettersMorse['R'] = ".-." ;
  lettersMorse['S'] = "..." ;
  lettersMorse['T'] = "-"   ;
  lettersMorse['U'] = "..-" ;
  lettersMorse['V'] = "...-";
  lettersMorse['W'] = ".--" ;
  lettersMorse['X'] = "-..-";
  lettersMorse['Y'] = "-.--";
  lettersMorse['Z'] = "--..";
  lettersMorse['_'] = "..--";
  lettersMorse['.'] = "---.";
  lettersMorse[','] = ".-.-";
  lettersMorse['?'] = "----";

  queue<char> enc;
  stack<int>  encLen;
  queue<char> dec;
  while ( cin >> encoded ) {
    int i = 0;
    int len = encoded.length();
    int tmpI, tmpLen;
    string tmpS;
    while ( i < len ){
      // add the encoded chars to the enc stack
      tmpI = 0;
      tmpS = lettersMorse[encoded[i]];
      tmpLen = tmpS.length();
      encLen.push(tmpLen);
      while (tmpI < tmpLen) {
        enc.push(tmpS[tmpI]);
        tmpI++;
      }
      i++;
    }
    // read lengths in order, and pop chars from the stack accordingly
    while(!enc.empty()){
      tmpI = 0;
      tmpS = "";
      while (tmpI < encLen.top()){
        tmpS += enc.front();
        enc.pop();

        tmpI++;
      }
      // add letter to decode stack
      dec.push(morseLetters[tmpS]);
      encLen.pop();
    }

    // print output
    while(!dec.empty()){
      printf("%c", dec.front());
      dec.pop();
    }
    printf("\n");
  }
  return 0;
}
