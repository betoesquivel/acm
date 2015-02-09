#include <iostream>

using namespace std;

int main(int argc, const char *argv[])
{
  int a, b, ans, T;
  string response = "  ";
  char op, eq;
  cin >> T;
  while (T > 0) {
     cin >> a >> op >> b >> eq >> ans;
     if (eq == '='){
       switch (op){

         case '+': response = (ans == a+b) ? "Yes":"No";
           break;
         case '-': response = (ans == a-b) ? "Yes":"No";
           break;
         case '*': response = (ans == a*b) ? "Yes":"No";
           break;
         case '/': response = (a!=0 && b!=0 && ans == a/b) ? "Yes":"No";
           break;
         default:
                   response = "No";
       }

       cout << response << endl;
     }else{
       cout << "No" << endl;
     }

     T--;
  }
  return 0;
}
