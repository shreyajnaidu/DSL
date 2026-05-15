#include <stdio.h>
int main() {
int arr[100], n, i, find;
printf("Enter number of elements: ");
scanf("%d", &n);
printf("Enter %d integers:\n", n);
for(i = 0; i < n; i++)
{
scanf("%d", &arr[i]);
}
printf("Number to be found: ");
scanf("%d",&find);
int high,low,mid;
low=0;
high=n-1;
int x=1;
while(high>=low){
    mid=(high+low)/2;
    if(arr[mid]==find){
        printf("Value found at position %d",mid+1);
        x=0;
        break;
    }
    if(find>mid){
        low=mid;
        continue;
    }
    if(find<mid){
        high=mid;
        continue;
    }
}
if(x==1){
    printf("Number not found in array.");
}

return 0;
}
