// File: sysproc.c	Name:Sagi Menahem	ID:208645937
#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"
#include "spinlock.h"			// Includes the spinlock header for managing concurrent access to shared resources

extern struct {					// Spinlock to protect the process table from concurrent access
    struct spinlock lock;
    struct proc proc[NPROC];	// Array of process structures representing all processes in the system
} ptable;						// Declares the global process table used by the kernel

int sys_cps137(void) {
    struct proc *p; // Pointer to iterate over the processes in the process table
    char *state; // String to represent the state of each process

    // Print the title according to the instructions
    cprintf("name \t pid \t state \t \t ppid \n");

    for (p = ptable.proc; p < &ptable.proc[NPROC]; p++) {
        if (p->state == UNUSED) continue; // Skip unused process slots

        // Determining the process status
        state = (p->state == SLEEPING) ? "SLEEPING" : "RUNNING";

        // Determine the PPID (use 0 if parent is NULL)
        int ppid = (p->parent) ? p->parent->pid : 0;

        // Print the details for each process
        cprintf("%s \t %d \t %s \t %d \n", p->name, p->pid, state, ppid);
    }
    return 0; // Return 0 to indicate successful execution
}


int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}
