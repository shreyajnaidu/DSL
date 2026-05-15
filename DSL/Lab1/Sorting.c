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
printf("1. Bubble Sort  2.Selection Sort  3.Insertion Sort \n");
scanf("%d",&find);
int temp,j;
if(find==1){
for(i = 0; i < n; i++){
    for(j=0;j<n-1;j++){
            if (arr[j]>arr[j+1]){
            temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;}
        }
        printf("\n");
        for( int k=0;k<n;k++){
    printf("%d ",arr[k]);
}
}
printf("Bubble Sorted Array: ");
for( i=0;i<n;i++){
    printf("%d ",arr[i]);
}
}
if(find==2){
        int min;
        for(j=0;j<n-1;j++){
                min=j;
            for(i=j+1;i<n;i++){
                if(arr[i]<arr[min]){
                    min=i;
                }
            }
        temp=arr[j];
        arr[j]=arr[min];
        arr[min]=temp;
         printf("\n");
        for( int k=0;k<n;k++){

    printf("%d ",arr[k]);
        }
        }
        printf("Selection Sorted Array:\n ");
        for( i=0;i<n;i++){
    printf("%d ",arr[i]);
        }
}

if(find==3){
for (int i = 1; i < n; i++) {
        int key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
            printf("\n");
        for( int k=0;k<n;k++){
    printf("%d ",arr[k]);}
        }
        arr[j + 1] = key;
    }
    printf("Insertion Sorted Array:\n ");
        for( i=0;i<n;i++){
    printf("%d ",arr[i]);
        }
}

return 0;
}
