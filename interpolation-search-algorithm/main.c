#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr [],int n){
    int i,j;
    int temp;
    for (i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
        if(arr[j]>arr[j+1]){
            temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
            }
        }
    }

}

void selectionSort(int arr[],int n){
    int i,j;
    int min,temp;
    //min=arr[0];
    for (i=0;i<n-1;i++){
        min=arr[i];
        for(j=i;j<n;j++){
            if(arr[j]<min){
                min=arr[j];
                temp=j;
                //printf("%d %d",min,temp);
            }
        }
        if(temp!=i){
        arr[temp]=arr[i];
        arr[i]=min;
        }

    }
}

void insertionSort(int arr [],int n){
    int i,j,k;
    for(j=1;j<n;j++){
        k=arr[j];
        for(i=j-1;i>=0 && k<arr[i];i--){
            arr[i+1]=arr[i];
        }
        arr[i+1]=k;
    }
}

void interpolationSearch(int arr[],int item,int n){
    //sort(arr,n);
    int mid;
    int high=n-1;
    int low=0;

    mid=low+(((double)(high-low)/(arr[high]-arr[low]))*(item-arr[low]));
    while(item!=arr[mid] && low<=high){
        if(arr[mid]<item)
            low=mid+1;
        else
            high=mid-1;

    mid=low+(((double)(high-low)/(arr[high]-arr[low]))*(item-arr[low]));

    }
    printf("\nthe item  %d is at %d",item,mid+1);
}

int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d",&n);

    int arr[n];
    int i;
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("\n");

    //bubbleSort(arr,n);
    insertionSort(arr,n);
    for(i=0;i<n;i++){
        printf("\n%d",arr[i]);
    }

    //interpolationSearch(arr,4,n);

    return 0;
}
