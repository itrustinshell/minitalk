This project explores basics of signals between a basic communication betweem server and client.

You will explore basics of library <signal.h>
with some of its features.
You will use:

int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact);

Signum specifies the signal and can be one of SIGUSR1 or SIGUSR2

Here, the struct sigaction:

             struct sigaction {
               void     (*sa_handler)(int);
               void     (*sa_sigaction)(int, siginfo_t *, void *);
               sigset_t   sa_mask;
               int        sa_flags;
               void     (*sa_restorer)(void);
           };
  You will understand when using sa_handler and sa_sigaction,
  how to set sa_mask with sigemptyset(), how set the sa_flags.
           
  In particular: 
  - sa_flags specifies a set of flags which modify the behavior of the 
    signal. In the server you will yuse the flag SA_SIGINFO.
    When you set this flag, then you should use sa_sigaction instead
    of sa_hanler. This allows you to have one of the filed of sigiinfo_t,
    that is si_pid (specified below).
    
  - sa_mask specifies a mask of signals  which  should  be  blocked.
    If you apply sigemptyset() function to the mask, then you will not
    block any signal.
            
           
Here, the struct siginfo_t:

            siginfo_t {
                           int      si_signo;     /* Signal number */
                           int      si_errno;     /* An errno value */
                           int      si_code;      /* Signal code */
                           int      si_trapno;    /* Trap number that caused
                                                     hardware-generated signal
                                                     (unused on most architectures) */
                           pid_t    si_pid;       /* Sending process ID */
                           uid_t    si_uid;       /* Real user ID of sending process */
                           int      si_status;    /* Exit value or signal */
                           clock_t  si_utime;     /* User time consumed */
                           clock_t  si_stime;     /* System time consumed */
                           union sigval si_value; /* Signal value */
                           int      si_int;       /* POSIX.1b signal */
                           void    *si_ptr;       /* POSIX.1b signal */
                           int      si_overrun;   /* Timer overrun count;
                                                     POSIX.1b timers */
                           int      si_timerid;   /* Timer ID; POSIX.1b timers */
                           void    *si_addr;      /* Memory location which caused fault */
                           long     si_band;      /* Band event (was int in
                                                     glibc 2.3.2 and earlier) */
                           int      si_fd;        /* File descriptor */
                           short    si_addr_lsb;  /* Least significant bit of address
                                                     (since Linux 2.6.32) */
                           void    *si_lower;     /* Lower bound when address violation
                                                     occurred (since Linux 3.19) */
                           void    *si_upper;     /* Upper bound when address violation
                                                     occurred (since Linux 3.19) */
                           int      si_pkey;      /* Protection key on PTE that caused
                                                     fault (since Linux 4.6) */
                           void    *si_call_addr; /* Address of system call instruction
                                                     (since Linux 3.5) */
                           int      si_syscall;   /* Number of attempted system call
                                                     (since Linux 3.5) */
                           unsigned int si_arch;  /* Architecture of attempted system call
                                                     (since Linux 3.5) */
                       }
  For the purpose of minitalk you need to use the filed si_pid which refers 
  to the pid of sending process, that is the client.
