#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <wait.h>

int main(void)
{
  int pipefd[2]; // 0 read, 1 write
  pid_t child_pid;
  char buf[100];

  // create pipe
  if (pipe(pipefd) == -1)
  {
    perror("failed to create pipe");
    exit(EXIT_FAILURE);
  }

  // fork child process
  child_pid = fork();
  if (child_pid == -1)
  {
    perror("failed to fork child process");
    exit(EXIT_FAILURE);
  }

  if (child_pid == 0)
  {
    close(pipefd[1]); // close write

    read(pipefd[0], buf, sizeof(buf));
    printf("recv: %s\n", buf);

    close(pipefd[0]);
    exit(EXIT_SUCCESS);
  }
  else
  {
    close(pipefd[0]); // close read
    char *msg = "HelloWorld";
    write(pipefd[1], msg, strlen(msg));
    close(pipefd[1]);
    wait(NULL); // wait for child process to send
  }

  return 0;
}