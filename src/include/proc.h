#ifndef __PROC_H__
#define __PROC_H__

#include <param.h>

struct proc
{
    char   p_stat;     // Status :: 
                       // if p_stat === NULL then proc is empty
                       //
    char   p_flag;     // Flag ::
                       // SLOAD => Not swapped out
                       // SSYS  => System Process, Must not to be swapped
                       // SLOCK => Locked to prevent swapping out
                       // SSWAP => Swapped out, user.u_rsav[] disavowed.
                       //          r5, r6 must be restored from user.u_ssav[]
                       // STRC  => Being traced
                       // SWTED => Being used for trace process
    char   p_pri;      // Execution Priority
    char   p_sig;      // Signal received
    char   p_uid;      // User ID
    char   p_time;     // Stay time on memory or swap area
    char   p_cpu;      // Accumulated CPU ticks
    char   p_nice;     // initial value = 0
                       // Correction value to down execution priority 
    int    p_ttyp;     // Terminal that executed the process
    int    p_pid;      // Process ID(PID)
    int    p_ppid;     // Parent Process ID
    int    p_addr;     // Allocated physical memory address (64bit)
    int    p_size;     // Allocated memory size (64bit)
    int    w_chan;     // Reason why to be sleep state
    
    char*  p_textp;    // Using text segment
} proc[NPROC];


/* stat codes, being used for proc.p_stat */
#define SSLEEP 1
#define SWAIT  2
#define SRUN   3
#define SIDL   4
#define SZOMB  5
#define SSTOP  6

/* flag codes, being used for proc.p_flag */
#define SLOAD  01
#define SSYS   02
#define SLOCK  04
#define SSWAP  010
#define STRC   020
#define SWTED  040

#endif
