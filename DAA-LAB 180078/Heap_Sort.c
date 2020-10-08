#include<stdio.h>
#include<conio.h>
void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void heapify(int arr[], int n, int i){
	int max = i;
	int leftChild = 2 * i + 1;
	int rightChild = 2 * i + 2;
    if (leftChild < n && arr[leftChild] > arr[max])
		max = leftChild;
    if (rightChild < n && arr[rightChild] > arr[max])
		max = rightChild;
    if (max != i) {
		swap(&arr[i], &arr[max]);
		heapify(arr, n, max);
    }
}
void heapSort(int arr[], int n){
	int i;
	for (i = n / 2 - 1; i >= 0; i--)
    	heapify(arr, n, i);
    for ( i = n - 1; i >= 0; i--) {
    	swap(&arr[0], &arr[i]);
    	heapify(arr, i, 0);
    }
}
void display(int arr[], int n){
	int i;
    for (i = 0; i < n; ++i)
	    printf("%d\t", arr[i]);
}
void main() {
    int i,arr[15],n;
    printf("Enter the number  of elements: ");
    scanf("%d",&n);
    printf("Enter the elements od array:\n");
    for(i=0;i<n;i++){
    	scanf("%d",&arr[i]);
	}
    heapSort(arr, n);
    printf("Sorted array:\n");
    display(arr, n);
}
