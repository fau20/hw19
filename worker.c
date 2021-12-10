#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>


int main() {
  int fd, fd2;
  fd = open("pipe", O_RDONLY);
  fd2 = open("pipe2", O_WRONLY);

  while(1) {
    char line[1000];
    read(fd, line, sizeof(line));

    int i = 0;
    while(line[i]) {
      if(line[i] >= 'a' && line[i] <= 'z') {
        line[i] = line[i] - 'a' + 'A';
      }
      i++;
    }
    
    write(fd2, line, strlen(line));
    }
  return 0;
}
