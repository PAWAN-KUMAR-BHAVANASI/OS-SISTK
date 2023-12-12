#include <stdio.h>
#include <conio.h>

int main() {
  // Reference string length, reference string, number of frames
  int n, rs[25], f;
  // Page frame array, page faults, count
  int m[10], pf = 0, count = 0;
  // Loop counters and flag
  int i, j, k;

  // Clear screen
  clrscr();

  // Get reference string length
  printf("\nEnter the length of reference string: ");
  scanf("%d", &n);

  // Get reference string
  printf("\nEnter the reference string: ");
  for (i = 0; i < n; ++i) {
    scanf("%d", &rs[i]);
  }

  // Get number of frames
  printf("\nEnter the number of frames: ");
  scanf("%d", &f);

  // Initialize page frame array
  for (i = 0; i < f; ++i) {
    m[i] = -1;
  }

  // Print page replacement process header
  printf("\nThe Page Replacement Process is --\n");

  // Loop through the reference string
  for (i = 0; i < n; ++i) {
    // Check if page is already in memory
    for (k = 0; k < f; ++k) {
      if (m[k] == rs[i]) {
        break; // Page already in memory, skip to next iteration
      }
    }

    // Page fault occurs if not already in memory
    if (k == f) {
      // Replace least recently used page (FIFO)
      m[count++] = rs[i];
      pf++;
    }

    // Print page frame contents and page fault number (if applicable)
    for (j = 0; j < f; ++j) {
      printf("\t%d", m[j]);
    }
    if (k == f) {
      printf("\tPF No. %d", pf);
    }
    printf("\n");

    // Reset count if it reaches frame limit
    if (count == f) {
      count = 0;
    }
  }

  // Print total page faults
  printf("\nThe number of Page Faults using FIFO are %d", pf);

  getch();

  return 0;
}

/*Description:
Page replacement is basic to demand paging. It completes the separation between logical memory and 
physical memory. With this mechanism, an enormous virtual memory can be provided for programmers 
on a smaller physical memory. There are many different page-replacement algorithms. Every operating 
system probably has its own replacement scheme. A FIFO replacement algorithm associates with each 
page the time when that page was brought into memory. When a page must be replaced, the oldest page 
is chosen. If the recent past is used as an approximation of the near future, then the page that has not 
been used for the longest period of time can be replaced. This approach is the Least Recently Used (LRU) 
algorithm. LRU replacement associates with each page the time of that page's last use. When a page 
must be replaced, LRU chooses the page that has not been used for the longest period of time. Least 
frequently used (LFU) page-replacement algorithm requires that the page with the smallest count be 
replaced. The reason for this selection is that an actively used page should have a large reference count.
*/