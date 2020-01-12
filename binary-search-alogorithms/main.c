#include <stdio.h>
#include <string.h>

void sort(int arr [],int n){
    int i,j;
    int temp;
    for (i=0;i<n;i++){
        for(j=i;j<n;j++){
        if(arr[i]>arr[j]){
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    }

}

int BinarySearch(int arr [],int item,int n){
    sort(arr,n);
    int start=0;
    int end=n-1;
    int middle=(start+end)/2;
    while(item!=arr[middle] && start<=end){
        if (item>arr[middle])
            start=middle+1;
        else
            end=middle-1;
        middle=(start+end)/2;
    }
    if (item==arr[middle]){
        printf("\n%d found at position %d",item,middle+1);
    }
    if (start>end){
        printf("\n%d not found in array",item);
    }
    return 0;
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

    sort(arr,n);

    for(i=0;i<n;i++){
        printf("\n%d",arr[i]);
    }



    BinarySearch(arr,5,n);

    return 0;
}
