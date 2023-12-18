#include<stdio.h>
#include<stdlib.h>
int display(int a[],int n)
{
int i;
for(i=0;i<n;i++)
printf("%d ",a[i]);
return 0;
}
void radixsort(int a[],int n)
{
int m=a[0],exp=1,i=1;
for(i=0;i<n;i++)
if(abs(a[i]>m))
m=a[i];
while(abs(m)/exp>0)
{
int b[n],i;
int box[19]={0};
for(i=0;i<n;i++)
box[(a[i]/exp)%10+9]++;
for(i=1;i<19;i++)
box[i]=box[i]+box[i-1];
for(i=n-1;i>=0;i--)
b[--box[(a[i]/exp)%10+9]]=a[i];
for(i=0;i<n;i++)
a[i]=b[i];
exp*=10;
}
}
void main()
{
int a[100],n,i;
printf("Enter array size : ");
scanf("%d",&n);
printf("Enter %d elements : ",n);
for(i=0;i<n;i++)
scanf("%d",&a[i]);
radixsort(a,n);
printf("After sorting the elements are : ");
display(a,n);
printf("\n");
}