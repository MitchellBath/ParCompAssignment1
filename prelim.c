#include <unistd.h>
#include <limits.h>
#include <stdio.h>
int main () {
	//int HOST_NAME_MAX = 64;
  char hostname[1024];
  int gethostname(hostname, HOST_NAME_MAX+1);
  
  printf("Hostname: %s\n", hostname);
  return 0;
}
