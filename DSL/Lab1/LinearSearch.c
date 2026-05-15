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
for(i = 0; i < n; i++){
    if(arr[i]==find){
        printf("Number found in position %d",i+1);
        break;
    }
}
return 0;
}
