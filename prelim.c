#include <unistd.h>
#include <limits.h>
#include <stdio.h>
int main () {
	//int HOST_NAME_MAX = 64;
  size_t size = 255;
  char* hostname[size];
  gethostname(hostname, size);
  
  printf("Hostname: %s\n", hostname);
  return 0;
}
