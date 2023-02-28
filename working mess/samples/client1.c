#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main() {
    pid_t pid = getpid(); // Get current process ID

    printf("Client PID: %d\n", pid);

    // Send SIGUSR1 signal to the server
    if (kill(41503, SIGUSR1) == -1) {
        perror("kill error");
        exit(1);
    }

    sleep(1); // Wait for server to handle the signal

    return 0;
}
