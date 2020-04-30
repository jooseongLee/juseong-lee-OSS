#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "extras.h"

// Function: defragment()
// Input: record - array of Records; this may contain empty elements in the middle
// - Leave a brief information about the function
void defragment(Record records[]){
	// TODO: Modify this function as you need
	int i=0, j = 999;
	while(i < j)
  {
    if(records[i].number == 0 && records[j].number != 0)
    {
      memcpy(&records[i], &records[j], sizeof(Record));
     records[j].number = 0;
      i++;
      j--;
    }
    if(records[i].number != 0)
      i++;
    if(records[j].number == 0)
      j--;
  }
	printf("\nfinished\n");	

 	
}


// Function: add_a_record()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// - Leave a brief information about the function
void display_stats(Record records[]){
	// TODO: Modify this function as you need
	int club_count = 0;
  for(int i = 0 ; i < 1000; i++)
  {
    if(records[i].inclub == true)
      club_count++;
    

  }
 
  printf("\nNumber of students who joins club  : %d", club_count);
  
}


// TODO: Add more functions to fulfill the optional requirements

void swap(Record* i, Record* j)
{
  Record temp = *i; 
    *i = *j; 
    *j = temp;
}
void sort_record(Record records[])
{
  defragment(records);
  int arr[1000];
  int i, j, min_idx, size=0;
  while(records[size].number != 0)
  {
    size++;
  }
  for(i =0; i < size-1; i++)
  {
    min_idx = i;
    for(j = i +1; j < size; j++)
    {
      if(records[j].number < records[min_idx].number)
        min_idx = j;
    }
    swap(&records[min_idx], &records[i]);
  }

}
