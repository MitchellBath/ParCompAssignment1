//#include <unistd.h>
#include <stdio.h>
int main () {
	
  char hostname[HOST_NAME_MAX + 1];
  gethostname(hostname, HOST_NAME_MAX + 1);
  
  printf("Hostname: %s\n", hostname);
  return 0;
}
