#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int Get_char()
{
	char ch;
	ch=getch();
	if(ch==-32)
	 ch=getch();
	 return ch;
}
int win(int matrix[][4])
{
	int i,j,k=1;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		 {
		    if(i==3&&j==3)
		      k=0;
		 	if(matrix[i][j]==k)
		 	  k++;
		 	else
		 	 return 1;
		 }
	}
	if(i==4)
	  return 0;
}
void swap(int *a,int *b)
{
	*a=*a+*b;
	*b=*a-*b;
	*a=*a-*b;
}
int right_shift(int matrix[][4])
{
	int i,j;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		 	if(matrix[i][j]==0)
		 	    break;
		if(j!=4)
		break;
	}
	if(j==0)
	   return 0;
    else
      {
      	swap(&matrix[i][j],&matrix[i][j-1]);
        return 1;
	  }
}
int left_shift(int matrix[][4])
{
	int i,j;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		 	if(matrix[i][j]==0)
		 	    break;
		if(j!=4)
		break;
	}
	if(j==3)
	   return 0;
    else
      {
      	 swap(&matrix[i][j],&matrix[i][j+1]);
         return 1;
	  }
}
int shift_down(int matrix[][4])
{
	int i,j;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		 	if(matrix[i][j]==0)
		 	    break;
		if(j!=4)
		break;
	}
	if(i==0)
	   return 0;
    else
      {
      	swap(&matrix[i][j],&matrix[i-1][j]);
        return 1;
	  }
}
int shift_up(int matrix[][4])
{
	int i,j;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		 	if(matrix[i][j]==0)
		 	    break;
		if(j!=4)
		break;
	}
    if(i==3)
	   return 0;
	else
     {
     	swap(&matrix[i][j],&matrix[i+1][j]);
        return 1;
	 }
}
void show_matrix(int matrix[][4])
{
	 int i,j;
	 printf("---------------------\n");
	 for(i=0;i<4;i++)
	 {	
	    printf("|");
	 	for(j=0;j<4;j++)
	 	{  
	 		  if(matrix[i][j]!=0)
	 		    printf(" %2d |",matrix[i][j]);
	 		  else
	 		      printf("    |");
		}
		printf("\n");
	 }
	 printf("---------------------\n");
}
void creatematrix(int matrix[][4])
{
	system("cls");
	int i,j,k,l,min=1,num,flag;
	srand(time(NULL));
	for(i=0;i<4;i++)
	 {
	 	for(j=0;j<4;j++)
	 	{
	 		if(i==3&&j==3)
	 		  {
	 		  	matrix[3][3]=0;
	 		  	break;
			  }
	 		flag=0;
	 	   num=rand()%15+min;
	 	   for(k=0;k<=i;k++)
	 	    {
	 	    	for(l=0;l<4;l++) 
	 	    	 {
	 	    	     if(num==matrix[k][l])
	 	    		  {
	 	    		   flag=1;
					   break;	
					  }	
				 }
			}
			if(flag==1)
			  j--;
			else
		     matrix[i][j]=num;
		}
	 }
}
void gamerule(int matrix[][4])
{
	system("cls");
	int i,j,k=0;
	printf("\t\t\t\tRULE OF THIS GAME\n");
	printf("1.You can move only 1 step at a time by arrow key\n");
	printf("Move Up   :  by Up arrow key\n");
	printf("Move Dowm :  by Down arrow key\n");
	printf("Move Left :  by Left arrow key\n");
	printf("Move Right:  by Right arrow key\n");
	printf("2.You can move number at empty position only\n\n");
	printf("3.For each valid move : your total number of move will decreased by 1\n");
	printf("4.Winning situation : number in a 4x4 matrix should be in order from 1 to 15\n\n");
	printf("\t\twinning situation:\n");
	for(i=0;i<4;i++)
	 {
	 	for(j=0;j<4;j++)
	 	{
	 		matrix[i][j]=k+1;
	 		k++;
		}
	 }
	 matrix[3][3]=0;
	 printf("---------------------\n");
	 for(i=0;i<4;i++)
	 {	
	    printf("|");
	 	for(j=0;j<4;j++)
	 	{
	 		  if(i==3&&j==3)
	 		     printf("    |");
	 		  else
	 		     printf(" %2d |",matrix[i][j]); 
		}
		printf("\n");
	 }
	 printf("---------------------\n\n");
	 printf("5.You can exit the game at any time by pressing 'E' or 'e'\n");
	 printf("So try to win in minimum number of moves\n\n\t\tHappy gaming, Good Luck\n\n");
	 printf("Enter any key to start....");
	 getch();
}
int main()
{
	int matrix[4][4],move=4,c;
	char name[20],ch;
	printf("\n\n\n");
	printf("Player name:");
	scanf("%s",name);
    while(1)
    {
      gamerule(matrix);
      creatematrix(matrix);
      while(win(matrix))
       {
       	 system("cls");
       	 printf("\n\n\t\tPlayer Name: %s,\tMove remaining : %d\n\n",name,move);
       	 show_matrix(matrix);
       	  ch=Get_char();
         switch(ch)
          {
     	    case 72: 
     	      if(shift_up(matrix))
     	      move--;
     	      break;
     	    case 80: 
     	      if(shift_down(matrix))
     	      move--;
     	      break;
     	    case 77: 
     	      if(right_shift(matrix))
     	      move--;
     	      break;
     	    case 75: 
     	      if(left_shift(matrix))
     	      move--;
     	      break;
     	   case 101:
     	   case 69:
     	   	  exit(0);
	      }
	      	if(move<0)
     	      {
     	      	system("cls");
     	      	printf("\n\tYou Lose !\n\n");
     	      	printf("Want to play again ?\nEnetr 'y' or 'Y' to play again:");
     	        c=getch();
     	      	if(c=='y'||c=='Y')
     	      	  {
     	      	  	 gamerule(matrix);
                     creatematrix(matrix);
     	      	     move=4;
				  }
				 else
				  exit(0);
     	      }
     	    if(!win(matrix))
     	     {
     	     	system("cls");
     	     	printf("\tCongratulation %s you have won\n",name);
     	     	printf("Want to play again ?\nEnetr 'y' or 'Y' to play again:");
     	        c=getch();
     	      	if(c=='y'||c=='Y')
     	      	  {
     	      	  	 gamerule(matrix);
                     creatematrix(matrix);
     	      	     move=4;
				  }
				 else
				  exit(0);
			 }

		}
			   
	}
	return 0;		  
}
