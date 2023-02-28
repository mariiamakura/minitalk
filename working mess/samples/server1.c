#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int data = 0;

void handle_signal(int sig) {
    if (sig == SIGUSR1) {
        data = 1;
        printf("Received SIGUSR1 signal\n");
    } else if (sig == SIGUSR2) {
        data = 2;
        printf("Received SIGUSR2 signal\n");
    }
}

int main() {
    pid_t pid = getpid(); // Get current process ID

    printf("Server PID: %d\n", pid);

    // Register signal handlers using sigaction()
    struct sigaction sa;
    sa.sa_handler = handle_signal;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    if (sigaction(SIGUSR1, &sa, NULL) == -1) {
        perror("sigaction error");
        exit(1);
    }
    if (sigaction(SIGUSR2, &sa, NULL) == -1) {
        perror("sigaction error");
        exit(1);
    }

    while (1) {
        if (data > 0) {
            printf("Data received: %d\n", data);
            break;
        }
    }

    return 0;
}