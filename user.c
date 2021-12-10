#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>


int main() {
  mkfifo("pipe", 0644);
  mkfifo("pipe2", 0644);

  int fd, fd2;
  fd = open("pipe", O_WRONLY);
  fd2 = open("pipe2", O_RDONLY);

  while(1) {
    printf("Enter input: ");
    char line[1000];

    fgets(line, sizeof(line), stdin);
    write(fd, line, strlen(line));

    printf("Response: ");
    char line2[1000];

    read(fd2, line2, sizeof(line2));
    printf("%s\n", line2);
  }
  return 0;
}
