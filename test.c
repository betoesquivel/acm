#include <stdio.h>

int main () {

  char str[80];
  char *nombre = "juan";

  sprintf(str,"Tu cara es %s %s y mas.\n", "tonta", nombre);


  printf("%s", str);
  return 0;

}
