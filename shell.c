#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void runcmd(const char* command) {
    pid_t pid;
    pid = fork();
    if ( pid < 0 ) {
        printf("fork error\n");
        exit(0);
    }
    if ( pid == 0 ) {
        printf("parent: \n");
        pid = wait(NULL);
        printf("parent: child process %d done\n", pid);
        return;
    } else {
        printf("child: \n");
        execl("/bin/bash", "bash", "-c", command, (char*)NULL);
    }
}

int main() {
    pid_t pid;
    pid = fork();
    char buffer[256];
    int res;
    while (1) {
        printf(">");
        fgets(buffer, 256, stdin);
        printf("%s\n", buffer);
        runcmd(buffer);
        /*
        if (pid > 0) { 
            printf("parent: child=%d\n", pid);
            pid = wait(0);
            printf("child %d is done\n", pid);
        } else if (pid == 0) {
            printf("child: exiting\n");
            exit(0);
        } else {
            printf("fork error\n");
        }
        */
    }

    return 0;
}
