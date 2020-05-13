#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "base.h"

int idx = -1;

// Function: print_all_records()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// - Leave a brief information about the function
void print_all_records(Record records[]){
	// TODO: Modify this function as you need
	for(int i = 0; i < idx + 1; i++)
  {
    //if(records[i].number == 0)
   // continue;
		//else if (records[i].name == NULL) break;
    //else
    //{
      printf("\n Student name : %s. Student number : %d", records[i].name,records[i].number);
      printf("\n joined club : %s",records[i].inclub ? "yes" : "no");
      printf("\n club : %s",records[i].club);
      printf("\n club department : %s ",records[i].clubdepart);
      printf("\n index : %d\n",i);
    //}
  }
}


// Function: add_a_record()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// - Leave a brief information about the function
void add_a_record(Record records[]) {
    // TODO: Modify this function as you need
    char name[20];
    int num;
    char inclub[20];
    char club[20];
    char clubdepart[20];

    for (int i = 0; i < 10; i++)
        records[i].number = 0;

    printf("Student name : ");
    scanf("%s", name);
    printf("Student number : ");
    scanf("%d", &num);
    printf("Does a new student join club? (y/n) :");
    scanf("%s", inclub);
		if(!strcmp(inclub, "y")) {
    	printf("what is club name : ");
    	scanf("%s", club);
			printf("What is club department : ");
	    scanf("%s", clubdepart);
		}
		fflush(stdin);

    for (int i = 0; i < 10; i++) {
        if (records[i].number == 0)
        {
            idx = i;
            break;
        }
    }
    if(idx == -1) printf("\nRecord is full please delete any record.\n");
    else
    {
        strcpy(records[idx].name, name);
        records[idx].number = num;
        if(!strcmp(inclub, "y")) records[idx].inclub = true;
        else if(!strcmp(inclub, "n")) records[idx].inclub = false;
        strcpy(records[idx].club,club);
        strcpy(records[idx].clubdepart,clubdepart);
    }
}

void load_datafile(Record records[])
{
    char str_tmp[1024];
    FILE *pFile = NULL;
    char *p;
    char filename[20];
    char temp[20];
    int idx = 0;
    printf("Please write the filename : ");
    scanf("%s", filename);
    pFile = fopen(filename, "r");
    if( pFile != NULL)
    {
      while(!feof(pFile))
      {
        fgets(str_tmp, 1024, pFile);
        int count = 0;
        p = strtok(str_tmp, ",");
        while(p != NULL)
        {
          switch(count){
              case 0 :
              strcpy(records[idx].name, p);
              break;
              case 1 :
              records[idx].number = atoi(p);
              break;
              case 2 :
              if(!strcmp(p, "yes"))
                records[idx].inclub = true;
              else
                records[idx].inclub = false;
              case 3 :
              strcpy(records[idx].club, p);
              case 4 :
              strcpy(records[idx].clubdepart, p);
          }
          count++;
          p = strtok(NULL, ",");
        }
        idx++;
      }
    }
    fclose(pFile);
    for(int i = idx ; i < 1000; i++)
    {
      strcpy(records[i].name, "");
      records[i].number = 0;
      strcpy(records[i].club, "");
      strcpy(records[i].clubdepart, "");
    }
    printf("\nload complete!\n");
}


void search(Record records[])
{
  int n;
  printf("\n This shows who joined specific club");
  printf("\nIf you want to see students who is joined performance club put 1");
  ;
  printf("\n put number : ");
  scanf("%d", &n);
  if(n == 1)
  {
    for(int i = 0; i < 1000; i++)
  {
    if(records[i].number == 0)
      continue;
    else if(records[i].inclub == true)
    {
      printf("\nStudent name : %s, Student num : %d", records[i].name, records[i].number);
      printf("\njoined club : %s", records[i].inclub ? "yes" : "no");
      printf("\nclub department %s", records[i].clubdepart);
    }
   }
  }
}

void export_datafile(Record records[])
{
  FILE *fp = fopen("data.txt", "w");
  char number[10];
  for(int i = 0; i < 1000; i++)
  {
    if(records[i].number == 0)
      continue;
    else
    {
      fputs(records[i].name, fp);
      fputs(",", fp);
      sprintf(number, "%d", records[i].number);
      fputs(number, fp);
      fputs(",", fp);
      if(records[i].inclub == true)
        fputs("yes", fp);
      else
        fputs("no", fp);
      fputs(records[i].club, fp);
      fputs(",", fp);
      fputs(records[i].clubdepart, fp);
      fputs("\n", fp);
    }
  }

    fclose(fp);
}

void export_reportfile(Record records[])
{
  FILE *fp = fopen("report.txt", "w");
  char number[10];
  int count = 1;
  char total[5];
  fputs("Student List\n", fp);
  for(int i = 0; i < 1000; i++)
  {
    if(records[i].number == 0)
      continue;
    else
    {

      sprintf(total, "%d", count);
      fputs(total, fp);
      fputs("\n", fp);
      fputs("Name : ", fp);
      fputs(records[i].name, fp);
      fputs("\n", fp);
      fputs("Student number : ", fp);
      sprintf(number, "%d", records[i].number);
      fputs(number, fp);
      fputs("\n", fp);
      fputs("Is he/she joined club? : ", fp);
      if(records[i].inclub == true)
        fputs("yes", fp);
      else
        fputs("no", fp);
      fputs("\n", fp);
      fputs("club name : ", fp);
      fputs(records[i].club, fp);
      fputs("\n", fp);
      fputs("club department: ", fp);
      fputs(records[i].clubdepart, fp);
      fputs("\n", fp);
      count++;
    }
  }

    fclose(fp);
}

void update_detail(Record records[])
{
  int key, index, update_num, new_num;
  int i;
  char info [20];
  print_all_records(records);
  printf("\nplease enter student number you want to update : ");
  scanf("%d", &key);
  for(i = 0 ; i < 1000; i++)
  {
    if(records[i].number == key)
    {
      printf("\nselect to what information you want to change");
      printf("\n 1. name, 2. student number, 3. in club 4. clubname 5. club department : ");
      scanf("%d",&update_num);
      switch (update_num)
      {
        case 1:
        printf("\nplease enter new name : ");
        scanf("%s", info);
        strcpy(records[i].name, info);
        printf("\nupdated!\n");
        break;
        case 2:
        printf("\nplease enter new number : ");
        scanf("%d", &new_num);
        records[i].number = new_num;
        printf("\nupdated!\n");
        break;
        case 3:
        printf("\nDoes he or she join the club?\n");
        records[i].inclub = !records[i].inclub;
        break;
        case 4:
        printf("\nplease enter club name : ");
        scanf("%s", info);
        strcpy(records[i].club, info);
        printf("\nupdated!\n");
        break;
        case 5:
        printf("\nplease enter club department : ");
        scanf("%s", info);
        strcpy(records[i].clubdepart, info);
        printf("\nupdated!\n");
      }
    }
  }

}

void delete_student(Record records[])
{
  int key;
  print_all_records(records);
  printf("\nput the student num you want to delete : ");
  scanf("%d", &key);
  for(int i= 0 ; i < 1000; i++)
  {
    if(records[i].number == key)
      records[i].number = 0;
  }
  printf("\nstudent deleted\n");

}

