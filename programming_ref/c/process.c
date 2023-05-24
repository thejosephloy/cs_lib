#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <setjmp.h>

/*
 * waitpid(pid_t pid, int *status, int options)
 * status:
 * WIFEXITED(status) :
 * WEXITSTATUS(status) :
 * WTERMSIG(status) :
 * WIFSTOPPED(status) :
 * WSTOPSIG(status) :
 * options / error conditions
 * WNOHANG :
 * WUNTRACED :
 * WNOHANG|WUNTRACED :
 */



/*
 * fork()
 * returns pid of child process in parent process, and returns 0 in child
 * process. 
 */

/*
 * exec__(version_params)
 * depending on __ suffix, different params are entered for starting
 * a new program and supplying arguments for the given program.
 * If exec__ command works properly, "it should not return"
 */

/*
 * char *getenv(const char *name)
 * int setenv(const char *name, const char *newvalue, int overwrite)
 * void unsetenv(const char *name)
 * getenv searches environment array for a string "name=value"
 * setenv replaces name=value with name=newValue if overwrite is nonzero
 * unsetenv deletes "name=value"
 */

int main() {

  pid_t pid;
  int x = 1;

  pid = fork();

  if (pid == 0) {
    printf("I am just a child : x = %d\n", ++x);
    exit(0);
  }

  printf("I am just a parent: x = %d\n", --x);
  
  return 0;
}

