// File: usys.S	Name:Sagi Menahem	ID:208645937
#include "syscall.h"
#include "traps.h"

// All "standard" SYSCALLS are added by this:
#define SYSCALL(name) \
  .globl name; \
  name: \
    movl $SYS_ ## name, %eax; \
    int $T_SYSCALL; \
    ret

// !!!! Adding "new" "SYSCALLfork(fork)" instead of SYSCALL(fork) 
//  without changing syscall.h !!! 1 is SYSCALL number, look in syscall.c
#define SYSCALLFORK(name) \
  .globl name; \
  name: \
    movl $1, %eax; \
    int $T_SYSCALL; \
    ret

// You need to add your new SYSCALL by the same way(here is a good place)

#define SYSCALLCPS137 \
  .globl cps137; \
  cps137: \
    movl $137, %eax; \
    int $T_SYSCALL; \
    ret



SYSCALLFORK(fork) //instead of SYSCALL(fork) !!!
//SYSCALL(fork)

SYSCALLCPS137	// Defines the cps137 system call wrapper for user-space invocation

SYSCALL(exit)
SYSCALL(wait)
SYSCALL(pipe)
SYSCALL(read)
SYSCALL(write)
SYSCALL(close)
SYSCALL(kill)
SYSCALL(exec)
SYSCALL(open)
SYSCALL(mknod)
SYSCALL(unlink)
SYSCALL(fstat)
SYSCALL(link)
SYSCALL(mkdir)
SYSCALL(chdir)
SYSCALL(dup)
SYSCALL(getpid)
SYSCALL(sbrk)
SYSCALL(sleep)
SYSCALL(uptime)
