#include <stdio.h>
#include <conio.h>

int main() {
  // Memory size, block size, number of blocks, external fragmentation
  int ms, bs, nob, ef;
  // Number of processes, memory required per process, total internal fragmentation
  int n, mp[10], tif = 0;
  // Loop variables and allocated flag
  int i, p = 0;

  // Clear screen
  clrscr();

  // Get total memory available
  printf("Enter the total memory available (in Bytes): ");
  scanf("%d", &ms);

  // Get block size
  printf("Enter the block size (in Bytes): ");
  scanf("%d", &bs);

  // Calculate number of blocks and external fragmentation
  nob = ms / bs;
  ef = ms - nob * bs;

  // Get number of processes
  printf("\nEnter the number of processes: ");
  scanf("%d", &n);

  // Get memory required for each process
  for (i = 0; i < n; ++i) {
    printf("Enter memory required for process %d (in Bytes): ", i + 1);
    scanf("%d", &mp[i]);
  }

  // Print available blocks
  printf("\nNo. of Blocks available in memory: %d", nob);

  // Print header for process information
  printf("\n\nPROCESS\tMEMORY REQUIRED\tALLOCATED\tINTERNAL FRAGMENTATION");

  // Loop through processes
  for (i = 0; i < n && p < nob; ++i) {
    // Print process information
    printf("\n %d\t\t%d", i + 1, mp[i]);

    // Check if process can be allocated
    if (mp[i] > bs) {
      printf("\t\tNO\t\t---");
    } else {
      // Allocate memory and calculate internal fragmentation
      printf("\t\tYES\t%d", bs - mp[i]);
      tif += bs - mp[i];
      p++;
    }
  }

  // Check if remaining processes cannot be accommodated
  if (i < n) {
    printf("\nMemory is Full, Remaining Processes cannot be accommodated");
  }

  // Print total internal and external fragmentation
  printf("\n\nTotal Internal Fragmentation is %d", tif);
  printf("\nTotal External Fragmentation is %d", ef);

  getch();

  return 0;
}

/*MFT:
Description: MFT (Multiprogramming with a Fixed number of Tasks) is one of the old memory 
management techniques in which the memory is partitioned into fixed size partitions and each job 
is assigned to a partition. The memory assigned to a partition does not change.*/