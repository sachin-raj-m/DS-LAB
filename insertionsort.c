/* 
	Author:	JEC21AD041 SACHIN RAJ M
	Date : 13/10/2022 Thursday
	Exp No : 4
	Aim : Implementing Insertion Sort in Array
*/


#include <stdio.h>
void main()
{
  int n,temp,j;
  printf("Enter the size of the Array:");
  scanf("%d",&n);
  int a[n];
  printf("Enter the array elements:");
  for(int i=0;i<n;i++)
  scanf("%d",&a[i]); 
  for(int i=0;i<n;i++)
  {
    j=i;
    while(j>0 && a[j-1]>a[j])
     {
    	 temp = a[j];		//swapping values
      	 a[j] = a[j-1];
         a[j-1] = temp;
         j--;
     }
    }
  
  printf("Array after performing Insertion Sort:\n");
  for(int i=0;i<n;i++)
  printf("%d\t",a[i]);
  printf("\n");
}
