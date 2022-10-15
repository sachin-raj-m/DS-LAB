/* 
	Author:	JEC21AD041 SACHIN RAJ M
	Date : 29/09/2022 Thursday
	Exp No : 1
	Aim : Implementing Linear Search in Array
*/


#include <stdio.h>
void main()
{
  int n,item;
  printf("Enter the size of the Array:");
  scanf("%d",&n);
  int a[n];
  printf("Enter the array elements:");
  for(int i=0;i<n;i++)
  scanf("%d",&a[i]);
  printf("Enter the element to find:");
  scanf("%d",&item);
  for(int i=0;i<n;i++)
  {
    if(item==a[i])
    printf("Element found in Position %d.\n",i+1);
    break;
    if(i==n)
    printf("Element not found. Search Unsuccessfull.\n");
  }
}
  
  

