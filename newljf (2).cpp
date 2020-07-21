#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include <time.h>



int delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;

    // Stroing start time
    clock_t start_time = clock();

    // looping till required time is not acheived
    while (clock() < start_time + milli_seconds)
	;
}

int main()
{
system("Title CPU Scheduling SJF-Non preemptive ");
int i,n,j,min,line[10],line1[10],p[10]={1,2,3,4,5,6,7,8,9,10};
int B_T[1000],A_V_T[1000],W_T[1000],temp[20],temp2,temp1,T_A_T[10];
int bt=0,ta=0,sum=0,k=1;
float AVR_W_T=0,AVR_T_A_T=0,T_A_T_SUM=0,W_T_SUM=0;
system("COLOR 74");
printf("\n\n");
printf("\n=====================================================================================================\n");
delay(1);
printf("\n                                    OPERATING SYSTEM MINIPROJECT                                     \n");
delay(1);
printf("\n======================================================================================================\n");
delay(1);
printf("\n\n\n");
system("cls");
system("COLOR 74");
delay(1);
system("COLOR 74");
printf("\n\n");
printf("\n=============================================================================================================\n");
delay(1);
printf("\n                               LONGEST JOB SCHEDULING ( NON-PREEMPTIVE)                                      \n");
delay(1);
printf("\n=============================================================================================================\n");
delay(1);
printf("\n");
system("COLOR 74");
delay(1);
printf("\t\tEnter the Number of processes : ");
scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\n\t\tEnter The Arrival Time Of Process %d : ",i+1);
        scanf(" %d",&A_V_T[i]);
        printf("\t\tEnter The Burst Time Of Process%d : ",i+1);
        scanf(" %d",&B_T[i]);

    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(A_V_T[i]<A_V_T[j])
            {
                temp2=p[j];
                p[j]=p[i];
                p[i]=temp2;
                temp2=A_V_T[j];
                A_V_T[j]=A_V_T[i];
                A_V_T[i]=temp2;
                temp2=B_T[j];
                B_T[j]=B_T[i];
                B_T[i]=temp2;
            }
        }
    }

    for(j=0;j<n;j++)
    {
        bt=bt+B_T[j];
        min=B_T[k];
    for(i=k;i<n;i++)
    {
        if (bt>=A_V_T[i] && B_T[i]>min)
            {
                temp2=p[k];
                p[k]=p[i];
                p[i]=temp2;
                temp2=A_V_T[k];
                A_V_T[k]=A_V_T[i];
                A_V_T[i]=temp2;
                temp2=B_T[k];
                B_T[k]=B_T[i];
                B_T[i]=temp2;
            }
    }
    k++;
    }

W_T[0]=0;
    for(i=1;i<n;i++)
    {
        sum=sum+B_T[i-1];
        W_T[i]=sum-A_V_T[i];
        line[i]=W_T[i];
        W_T_SUM=W_T_SUM+W_T[i];
    }

AVR_W_T=(W_T_SUM/n);
    for(i=0;i<n;i++)
    {
        ta=ta+B_T[i];
        T_A_T[i]=ta-A_V_T[i];
        line1[i]=T_A_T[i];
        T_A_T_SUM=T_A_T_SUM+T_A_T[i];
    }

AVR_T_A_T=(T_A_T_SUM/n);
system("cls");
delay(1);
printf("\n\n");
printf("\n================================================================================================================\n");
delay(1);
printf("\n                                 EXECUTION OF PROCESSES AND COMPLETION TIME                                     \n");
delay(1);
printf("\n================================================================================================================\n");
delay(1);
printf("\n");
for(i=1;i<n;i++)
for(j=1;j<n;j++)
   if(B_T[j]<B_T[j+1])
   {
     temp1=B_T[j];
     B_T[j]=B_T[j+1];
     B_T[j+1]=temp1;
   } 
temp[0]=0;
    for(i=0;i<n;i++)
    {
        temp[i+1]=temp[i]+B_T[i];
        for(i=0;i<n+1;i++)
        printf("\nProcess P%d is completed at:%d\n",i+1,temp[i]);
        p[i]=i+1;
    
    }

//system("cls");    
delay(1);
printf("\n\n");
printf("\n=============================================================================================================\n");
delay(1);
printf("\n                                            CALCULATED INFORMATION                                           \n");
delay(1);
printf("\n=============================================================================================================\n");
delay(1);
printf("\n");

printf("\nProcess Name\tBurst Time\t Arrival Time\t Waiting Time\t Turn Around Time" );
    for(i=0;i<n;i++)
    {
        
		delay(1);
		printf("\np%d\t\t%d\t\t %d\t\t %d\t\t %d",p[i],B_T[i],A_V_T[i],W_T[i],T_A_T[i]);
    }
printf("\n\nAVERAGE WAITING TIME : %.2f",AVR_W_T);
printf("\nAVERAGE TURN AROUND TIME : %.2f\n",AVR_T_A_T);
printf("\n");
delay(2);

    for(i=0;i<T_A_T_SUM/2;i++)
    {
        printf(" ");
    }

system("cls");
    printf("\n\n");
    printf("\n=============================================================================================================\n");
    printf("\n                                           GANTT CHART                                                       \n");
    printf("\n=============================================================================================================\n");
    printf("\n\n");
    printf("\n--------------------------------------------------------------------\n");
    line[0]=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<(line[i]+line1[i])/2;j++)
        {
            printf(" ");
        }
    printf("|P%d",p[i]);
    }
printf("\n--------------------------------------------------------------------\n");
//printf("");
printf("0");
    for(i=0;i<n; i++)
    {
        for(j=0;j<line1[i];j++)
        {
         printf("-");
        }
        printf("%d",W_T[i]+B_T[i]);
    }
    printf("\n");
getch();
return 0;

}
