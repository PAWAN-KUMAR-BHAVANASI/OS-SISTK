#include <stdio.h>
#include <conio.h>

int main() {
  // Memory size, page size, number of pages, number of processes
  int ms, ps, nop, np;
  // Remaining pages, process page requirements, page table
  int rempages, s[10], fno[10][20];
  // Loop counters, indices, physical address, offset
  int i, j, x, y, pa, offset;

  // Clear screen
  clrscr();

  // Get memory size
  printf("\nEnter the memory size: ");
  scanf("%d", &ms);

  // Get page size
  printf("\nEnter the page size: ");
  scanf("%d", &ps);

  // Calculate the number of available pages
  nop = ms / ps;
  printf("\nThe number of pages available in memory: %d", nop);

  // Get the number of processes
  printf("\nEnter the number of processes: ");
  scanf("%d", &np);

  // Set remaining pages
  rempages = nop;

  // Loop through processes
  for (i = 1; i <= np; ++i) {
    // Get the number of pages required for process i
    printf("\nEnter the number of pages required for process %d: ", i);
    scanf("%d", &s[i]);

    // Check if sufficient pages are available
    if (s[i] > rempages) {
      // Memory is full, stop allocating
      printf("\nMemory is Full");
      break;
    }

    // Update remaining pages
    rempages -= s[i];

    // Get page table entries for process i
    printf("\nEnter page table for process %d: ", i);
    for (j = 0; j < s[i]; ++j) {
      scanf("%d", &fno[i][j]);
    }
  }

  // Get logical address
  printf("\nEnter the logical address: ");
  printf("\nEnter process number, page number, and offset: ");
  scanf("%d %d %d", &x, &y, &offset);

  // Check for valid process, page number, and offset
  if (x > np || y >= s[i] || offset >= ps) {
    printf("\nInvalid process, page number, or offset");
  } else {
    // Calculate physical address
    pa = fno[x][y] * ps + offset;
    printf("\nThe physical address is: %d\n", pa);
  }

  getch();

  return 0;
}

/*Description:
In computer operating systems, paging is one of the memory management schemes by which a 
computer stores and retrieves data from the secondary storage for use in main memory. In the 
paging memory-management scheme, the operating system retrieves data from secondary storage 
in same-size blocks called pages. Paging is a memory-management scheme that permits the 
physical address space a process to be noncontiguous. The basic method for implementing paging 
involves breaking physical memory into fixed-sized blocks called frames and breaking logical 
memory into blocks of the same size called pages. When a process is to be executed, its pages are 
loaded into any available memory frames from their source.*/