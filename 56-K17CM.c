#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
int max[25][3];
int n[25][3];
int R[3]; int temp[3];
int temp2[25][3];
int l=0;
int tempP[25][3];
int tempR[3];
bool flag = false;
void check(int P[25][3]);
//function 1 begning....................................................................................................................
 void check(int P[l][3])
     { 
 int i; int j; int k=0; int a,b; int cc;
      for(j=0;j<3;j++)    //assigning temps.....................................................
          temp[j]=R[j];
       for(a=0;a<l;a++)
            {
            for(b=0;b<3;b++)
                {
                   temp2[a][b]=P[a][b];
                 }
            } 
       
      for(i=0;i<l;i++)    
        {
			for(j=0;j<3;j++)
            n[i][j]=max[i][j]-P[i][j];
			}
      for(k=0;k<l;k++)          //main logic  OUTER MOST LOOP .........................................
      {
         for(i=0;i<l;i++)        //  2nd Outermost loop ...................................
         {
            for(a=0;a<3;a++)
               temp[a]=R[a];
            for(a=0;a<l;a++)
            {
            for(b=0;b<3;b++)
                {
                   temp2[a][b]=P[a][b];
                 }
            }    
              for(j=0;j<3;j++)            //inner loop ...........................................            
                { 
                 if(R[j]>=n[i][j])
                  {  
                     R[j]=R[j]+P[i][j];
                     P[i][j]=0;
                     flag=true;
                   }  
                 else                    // correction if the values don't match......................
                  {
                  for(a=0;a<l;a++)
            {
            for(b=0;b<3;b++)
                {
                   P[a][b]=temp2[a][b];
                 }
            }
                  for(k=0;k<3;k++)
                    R[k]=temp[k];
                  flag=false;
                  cc=cc+1;
                  
                  }
                if(cc>=1)                  // checking if values don't macth then roll back to previous ..........................
                {
                	for(a=0;a<l;a++)
            {
            for(b=0;b<3;b++)
                {
                   P[a][b]=temp2[a][b];
                 }
            }
                  for(k=0;k<3;k++)
                    R[k]=temp[k];
				}
         }
        cc=0;
         
         }     
       }                    //end of logic...............................................
        if(flag==false)
        { 
		
		printf("Deadlock is present in the system Aborting\n");
          printf("*****************************************************************************************\n");
         exit(0);}
   } //function 1 end.......................................................................................................

// main.....................................................................................................................
  int main()
   {
     int c;
     int i; int j; int k=0; int P[3][3];
     
     printf("..........................................OS 3RD CA .....................................................\n");
     printf("..........................................REG 11709931 .....................................................\n");
     printf("..........................................Roll No 56 .....................................................\n");
     printf("..........................................Aditya Sarkar .....................................................\n");
     printf("Enter the number of process: \n");
     scanf("%d",&l);
     if(l<=0)
     {
     	printf("Invalid value provided Aborting !!!!");
     	exit(0);
	 }
	 else
	 {
	 
     
     printf("Enter the intances currently occupied by the processes:\n ");
       for(i=0;i<l;i++)
         {
         	printf("Enter the instances of Process %d :\n",i+1);
            for(j=0;j<3;j++)
                {
                   
                   scanf("%d",&P[i][j]);
                 }
          }
       printf("Enter the max instances that each process can hold :\n");
        for(i=0;i<l;i++)
         {
         	printf("Enter the maximum instance of Process %d :\n",i+1);
            for(j=0;j<3;j++)
                {
                   
                   scanf("%d",&max[i][j]);
                 }
          }   

      printf("Enter the resources available of A B C :\n");
      for(i=0;i<3;i++)
      scanf("%d",&R[i]);
      
      //assigning the temps ...................................................
     
      for(i=0;i<l;i++)
         {
            for(j=0;j<3;j++)
                {
                   temp2[i][j]=P[i][j];
                 }
          } 

      for(i=0;i<l;i++)
         {
            for(j=0;j<3;j++)
                {
                   tempP[i][j]=P[i][j];
                 }
          } 
    for(j=0;j<3;j++)
          tempR[j]=R[j];
          
    // Deadlock Check ................................................................................
          
      
      check(P);
      if(flag==true)
      printf("The system is in SAFE STATE The original values are NOT in deadlock\n");
      printf("****************");
      
      //1st Process insertion beg.................................................................
      
 	  printf(" \nEnter the independent request Process 1 which has resources in A B C :\n");
      
       	for(j=0;j<3;j++)
       	 {
			scanf("%d",&i);
			if(i>max[0][j])
			{
			printf("Error the value given exceeds the max value of the process!!!! Aborting");
			exit(0); }
			else
			{
				P[0][j]+=i;
			}
	}
        
        check(P);
        
        if(flag==true)                 //checking of 1st new value.........................................
      printf("The system is in SAFE STATE for the 1st request value\n");
      printf("**********************");
         
         for(i=0;i<l;i++)
         {
            for(j=0;j<3;j++)
                {
                   P[i][j]=tempP[i][j];
                 }
          } 
          
    for(i=0;i<3;i++)
    R[i]=tempR[i];
        //1st process insertion end...................................................................
        
        
        //2nd process insertion beg....................................................................
        
        
 	  printf(" \nEnter the independent request Process 2nd which has resources in A B C :\n");
      
       	for(j=0;j<3;j++)
       	 {
			scanf("%d",&i);
			if(i>max[1][j])
			{
			printf("Error the value given exceeds the max value of the process!!!! Aborting");
			exit(0); }
			else
			{
				P[1][j]+=i;
			}
	}
        
        check(P);
        
        if(flag==true)                 //checking of 2nd new value.........................................
      printf("The system is in SAFE STATE for the 2nd request value\n");
      printf("**********************");
         
         for(i=0;i<l;i++)
         {
            for(j=0;j<3;j++)
                {
                   P[i][j]=tempP[i][j];
                 }
          } 
          
    for(i=0;i<3;i++)
    R[i]=tempR[i];
        //2nd process insertion end..............................................................
     } //end of else
      
return 0;
}
      
        
    
                  
         
       
