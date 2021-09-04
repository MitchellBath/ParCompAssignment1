#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
int main(void) {
  char *command = "hostname -a";
  system(command);

}