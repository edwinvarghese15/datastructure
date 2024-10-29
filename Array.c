#include<stdio.h>
int main()
{
int a[10],b[10],c[25],l1,l2,i,j,temp,k;
printf("Enter the limit of A:");
scanf("%d",&l1);
printf("Enter the elements:");
for(i=0;i<l1;i++)
{
scanf("%d",&a[i]);
}


printf("Enter the limit of B:");
scanf("%d",&l2);
printf("Enter the elements:");
for(j=0;j<l2;j++)
{
scanf("%d",&b[j]);
}


printf("\nThe elements of A:");
for(i=0;i<l1;i++)
{
printf("%d\t",a[i]);
}

printf("\nThe elements of B:");
for(j=0;j<l2;j++)
{
printf("%d\t",b[j]);
}
// sorting
for(i=0;i<l1;i++)
{
for(j=i+1;j<l1;j++)
{
if(a[i]>a[j])
{
temp=a[i];
a[i]=a[j];
a[j]=temp;
}
}
}

printf("\nThe sorted elements of A:");
for(i=0;i<l1;i++)
{
printf("%d\t",a[i]);
}


for(i=0;i<l2;i++)
{
for(j=i+1;j<l2;j++)
{
if(b[i]>b[j])
{
temp=b[i];
b[i]=b[j];
b[j]=temp;
}
}
}

printf("\nThe elements of B:");
for(i=0;i<l2;i++)
{
printf("%d\t",b[i]);
}

// merging

k=0;
for(i=0;i<l1;i++)
{
c[k++]=a[i];
}
for(j=0;j<l2;j++)
{
c[k++]=b[j];
}


for(k=0;k<l1+l2;k++)
{
for(i=k+1;i<(l1+l2);i++)
{
if(c[k]>c[i])
{
temp=c[k];
c[k]=c[i];
c[i]=temp;
}
}
}
printf("\nmerged elements are:");
for(k=0;k<(l2+l1);k++)
{
printf("%d\t",c[k]);
}

}

