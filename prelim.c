#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
int main(void) {
  char hostname[HOST_NAME_MAX + 1];
  gethostname(hostname, HOST_NAME_MAX + 1);

  printf("hostname: %s\n", hostname);

  return EXIT_SUCCESS;
}