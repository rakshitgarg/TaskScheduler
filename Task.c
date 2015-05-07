#include<stdio.h>
int no;
int tasks[20][2];

int sort()
{
    int i,j;
    //Sort the given inputs in ascending order (start times)
    for(i=0;i<no;i++)
    {
        for(j=i+1;j<no;j++)
        {
            if(tasks[i][0]>tasks[j][0])
            {
                int temp;
                temp=tasks[i][0];
                tasks[i][0]=tasks[j][0];
                tasks[j][0]=temp;

                temp=tasks[i][1];
                tasks[i][1]=tasks[j][1];
                tasks[j][1]=temp;
            }
            if((tasks[i][0]==tasks[j][0])&&(tasks[i][1]>tasks[j][1]))
            {
                int temp;
                temp=tasks[i][0];
                tasks[i][0]=tasks[j][0];
                tasks[j][0]=temp;

                temp=tasks[i][1];
                tasks[i][1]=tasks[j][1];
                tasks[j][1]=temp;
            }
        }
    }

     //second sort algorithm

  for(i=0;i<no;i++)   //select first element
  {
         for(j=i;j<no;j++) //select next element for comparison

          {
                 if((tasks[i+1][0]<=tasks[i][1])&&(tasks[i][1]<=tasks[j][0])&&(tasks[i+1][0]<=tasks[j][0]))
                 //make sure swap area start time is less than end time of first element selected
                 //additionally first element end time needs to be less than second elements start time
                 //swap variables if condition passes
                          {
                            int temp;
                            temp=tasks[i+1][0];
                            tasks[i+1][0]=tasks[j][0];
                            tasks[j][0]=temp;

                            temp=tasks[i+1][1];
                            tasks[i+1][1]=tasks[j][1];
                            tasks[j][1]=temp;
                            int x=i+2;
      for(;x<no;x++)
        {
         for(j=x;j<no;j++)
          {
                 if(tasks[x][0]>tasks[j][0])
                          {
                            int temp;
                            temp=tasks[x][0];
                            tasks[x][0]=tasks[j][0];
                            tasks[j][0]=temp;

                            temp=tasks[x][1];
                            tasks[x][1]=tasks[j][1];
                            tasks[j][1]=temp;
                          }
                  if((tasks[x][0]==tasks[j][0])&&(tasks[x][1]>tasks[j][1]))
                          {
                            int temp;
                            temp=tasks[x][0];
                            tasks[x][0]=tasks[j][0];
                            tasks[j][0]=temp;

                            temp=tasks[x][1];
                            tasks[x][1]=tasks[j][1];
                            tasks[j][1]=temp;


                          }
           }

      }

                            break;
                          }
           }

   }

    return 0;
}

int main()
{
int i;
 printf("Hello Folks\nGreedy Task Scheduler\n");
 printf("Enter Number of Tasks:");

 scanf("%d",&no);
 i=0;
 //input
 do
    {

     printf("\nTask %d Start:",i+1);
     scanf("%d",&tasks[i][0]);
     printf("\nTask %d End :",i+1);
     scanf("%d",&tasks[i][1]);
     i++;
    }while(i<no);

  sort();

  //output
   int mach=1;
   for(i=0;i<no;i++)
    {

     if(i!=0)
      {
        if(tasks[i][0]<tasks[i-1][1])
            {mach++;}
      }

           printf("\n Machine: %d handles task (%d , %d)",mach,tasks[i][0],tasks[i][1]);
     }
         char a;
         scanf("%c",&a);
         return 0;
}
