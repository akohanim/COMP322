LAB 3 - Catcher 
I commemted when appropriate, so it should be fairly easy to read. 
Essentially this program processes the command line argument for thefollowing signals: 

SIGHUP SIGINT SIGQUIT SIGILL SIGTRAP SIGABRT SIGIOT SIGBUS
SIGFPE SIGUSR1 SIGSEGV SIGUSR2 SIGPIPE SIGALRM SIGTERM SIGSTKFLT SIGCHLD SIGCONT
SIGTSTP SIGTTIN SIGTTOU SIGURG SIGXCPU SIGXFSZ SIGVTALRM SIGPROF SIGWINCH

using 3 helper functions. This program catches the signals above and prints its status info on stdout.