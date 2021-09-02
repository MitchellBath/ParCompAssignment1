//#include <unistd.h>
#include <stdio.h>
int main () {
	
  char hostname[1024]];
  gethostname(hostname, 1024);
  
  printf("Hostname: %s\n", hostname);
  return 0;
}
