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
signation(_structName_, &_structName_, NULL)

```
