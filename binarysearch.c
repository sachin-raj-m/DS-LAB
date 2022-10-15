/* 
	Author:	JEC21AD041 SACHIN RAJ M
	Date : 29/09/2022 Thursday
	Exp No : 2
	Aim : Implementing Binary Search in Array
*/



#include <stdio.h>
void main()
{
  int n,item,temp,mid;
  printf("Enter the size of the Array:");
  scanf("%d",&n);
  int a[n];
  printf("Enter the array elements:");
  for(int i=0;i<n;i++)
  scanf("%d",&a[i]);
  printf("Enter the element to find:");
  scanf("%d",&item);

  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
        if(a[i]>a[j])  //using bubble sort
        {    
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
  }
  int l=0,u=n-1;
  while(l<=u){
    mid = (l+u)/2;
    if(a[mid]==item)
    {
    printf("Search Successful. Element found in Position %d.\n",(mid+1));
    return;
    }
    else if(a[mid]>item)
    u=mid-1;
    else
    l = mid+1;
  }
  if(l>u)
  printf("Search Unsuccessful. ITEM NOT FOUND.");
}
