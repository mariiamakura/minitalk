# minitalk

## materials to read/watch
[Unix Processes in C](https://www.youtube.com/playlist?list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY)

## how to use sigaction()

The sigaction() system call is used to change the action taken by a process on receipt of a specific signal.
```
#include <signal.h>

int sigaction(int signum, const struct sigaction *restrict act,
struct sigaction *restrict oldact);
```
                     
First, we need to declare a struct:
```
struct signation _structName_

_structName_.sa_flags = SA_SIGINFO //  If SA_SIGINFO is specified in sa_flags, then sa_sigaction (instead of sa_handler) specifies the signal-handling function for signum.  This function receives three arguments, as described below.
_structName_.sa_signation = _your_ft_name // sa_handler specifies the action to be associated with signum and
       is be one of the following. Everytime when a signal will go through this struct it will be redirected to another your function _your_ft_name
signation(_structName_, &_structName_, NULL) - sends the context of your signal info to the next function below

```

So once we redirected a signal, we can "customize" it using our function which we declared as _your_ft_name
```
void _your_ft_name (int signal, siginfo_t *siginfo, void *context) 
// int signal - signal itself, in our case it's SIGUSR1 or SIGUSR2
// siginfo_t *siginfo - struct that contains info about our signal, [more details](https://www.mkssoftware.com/docs/man5/siginfo_t.5.asp). Pay attention to pid_t si_pid, which holds the process id. 
// void *context - basically we don't need it in this project so it can be set to NULL

```

## how to send characters
Bit by bit ;) 
Use function int kill(pid_t pid, int sig) - don't worry we won't kill anyone. 

The kill() system call can be used to send any signal to any process group or process. [More](https://man7.org/linux/man-pages/man2/kill.2.html)

To send characters in bit you sould know few binary operations:
1. AND  & : 1 is only possible when there are two of them
```
10001100
11010101
10000100 - result of & operation
```
2. OR  | : 0 is only possible when there are two of them
```
10001100
11010101
11011101 - result of | operation
```
3. XOR A^B : only one of a pair can be 1
```
10001100
11010101
01011001 - result of ^ operation
```
4. NOT ~ : giving back reverse bits
```
10001100
01110011 -result of ~ operation
```
5. '<<n' or '>>n' : move bits in the direction specified on n bites and adds 0 in the end
```
10100110
10011000-result of <<2 operation
```
