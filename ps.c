// File: ps.c	Name:Sagi Menahem	ID:208645937

#include "types.h"		// Includes definitions for data types used in the program
#include "user.h"		// Includes user-space system call declarations

int main(void) {
    cps137();			// Calls the cps137 system call to list processes
    exit();				// Terminates the program gracefully
}
