#include <iostream>
#include <vector>

using namespace std;

void merge(int* ptr, int l, int h) {
    int start = l, end = h;
    int mid = (l+h)/2;
    int arr[h+1];

    int i = l, j = mid+1, k = 0;

    while(i <= mid && j <= h) {
        if(*(ptr+i) < *(ptr+j)) {
            arr[k++] = *(ptr+i);
            ++i;
        }
        else{
            arr[k++] = *(ptr+j);   
            ++j;
        }
    }

    if(i <= mid) {
        while(i <= mid) {
            arr[k++] = *(ptr+i);
            ++i;
        }
    }

    if(j <= h) {
        while(j <= h) {
            arr[k++] = *(ptr+j);   
            ++j;
        }
    }

    j = 0;
    for(int i=start; i<=end; ++i) {
        *(ptr+i) = arr[j++];
    } 
    // ptr = arr;
}

void mergesort(int *ptr, int l, int h) {
    if(l < h) {
        int mid = (l+h)/2;

        mergesort(ptr, l, mid);
        mergesort(ptr, mid+1, h);

        merge(ptr, l, h);
    }
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for(int i=0; i<n; ++i) {
        cin >> arr[i];
    }

    mergesort(arr, 0, n-1);

    for(int i=0; i<n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}