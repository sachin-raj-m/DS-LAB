/* 
	Author:	JEC21AD041 SACHIN RAJ M
	Date : 13/10/2022 Thursday
	Exp No : 3
	Aim : Implementing Selection Sort in Array

*/


#include <stdio.h>
void main()
{
  int n,temp,min;
  printf("Enter the size of the Array:");
  scanf("%d",&n);
  int a[n];
  printf("Enter the array elements:");
  for(int i=0;i<n;i++)
  scanf("%d",&a[i]);
  
  for(int i=0;i<n-1;i++)
  {
    min = i;		//setting min as first element
    for(int j=i+1;j<n;j++)
    {
    	if(a[min]>a[j])   //Ascending Order
    	min = j;
    	
    	temp = a[i];		//swapping values
    	a[i] = a[min];
    	a[min] = temp;
    }
  }
  printf("Array after performing Selection Sort:\n");
  for(int i=0;i<n;i++)
  printf("%d\t",a[i]);
 }
