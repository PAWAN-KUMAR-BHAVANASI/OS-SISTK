#include <stdio.h>
#include <conio.h>

int main() {
  // Total memory, memory required by processes, temporary memory
  int ms, mp[10], temp, i, n = 0;
  // User choice
  char ch = 'y';

  // Clear screen
  clrscr();

  // Get total memory available
  printf("\nEnter the total memory available (in Bytes): ");
  scanf("%d", &ms);

  // Set temporary memory equal to total memory
  temp = ms;

  // Loop until user chooses not to continue
  while (ch == 'y') {
    // Get memory required for current process
    printf("\nEnter memory required for process %d (in Bytes) -- ", i + 1);
    scanf("%d", &mp[i]);

    // Check if sufficient memory is available
    if (mp[i] <= temp) {
      // Allocate memory and update temporary memory
      printf("\nMemory is allocated for Process %d ", i + 1);
      temp -= mp[i];
      n++; // Increment process count
    } else {
      // Memory is full, stop allocating
      printf("\nMemory is Full");
      break;
    }

    // Ask user if they want to continue
    printf("\nDo you want to continue(y/n) -- ");
    scanf(" %c", &ch);
  }

  // Print memory statistics
  printf("\n\nTotal Memory Available: %d", ms);
  printf("\n\n\tPROCESS\t\tMEMORY ALLOCATED");
  for (i = 0; i < n; ++i) {
    // Print process information
    printf("\n\t%d\t\t%d", i + 1, mp[i]);
  }

  // Calculate and print total allocated and external fragmentation
  printf("\n\nTotal Memory Allocated: %d", ms - temp);
  printf("\nTotal External Fragmentation: %d", temp);

  getch();

  return 0;
}

/*MVT:
Description: MVT (Multiprogramming with a Variable number of Tasks) is the memory 
management technique in which each job gets just the amount of memory it needs. That is, the 
partitioning of memory is dynamic and changes as jobs enter and leave the system. MVT is a 
more ``efficient'' user of resources. MFT suffers with the problem of internal fragmentation and 
MVT suffers with external fragmentation.*/