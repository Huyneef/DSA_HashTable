#include <bits/stdc++.h>
using namespace std;
// Quick Sort
void quickSort(int a[], int l, int r)
{
    int i = l, j = r;
    int x = a[(l + r) / 2];
    while (i <= j)
    {
        while (a[i] < x)
            {i++;}
        while (a[j] > x)
            {j--;}
        if (i <= j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    if (l < j)
        quickSort(a, l, j);
    if (r > i)
        quickSort(a, i, r);
}

// Merge Sort
void merge(int a[], int low, int mid, int high) {
    int N = high - low + 1; // cần số phần tử mảng sắp xếp
    int b[N];
    int l = low , r = mid + 1, bI = 0;
    while(l <= mid && r <= high) 
    b[bI++] = (a[l] <= a[r]) ? a[l++]:a[r++];
    while(l <= mid) 
    b[bI++] = a[l++];
    while(r <= high) 
    b[bI++] = a[r++];
    for(int k = 0; k < N; ++k) {
        a[low+k] = b[k];
    }
}
void mergeSort(int a[], int l, int h) {
    if(l < h) {
        int mid = (l+h)/2;
        mergeSort(a,l,mid);
        mergeSort(a,mid + 1,h);
        merge(a,l,mid,h);
    }
}

// Insertion Sort
void insertionSort1(int a[], int n, int l, int r) {
    for(int i = 0; i < n; i++) {
        int x = a[i];
        int j = i -1;
        for(; j>= 0 && x < a[j]; j--) {
            a[j+1] = a[j];  
        }
        a[j+1] = x;
    }
}
void insertionSort2(int a[], int n) {
    for(int i = 1; i < n; i++) {
        int x = a[i];
        int l = 0, r = n-1;
        while(l <= r) {
            int mid = (l+r)/2;
            if(a[mid] < x) l = mid+1;
            else if(a[mid] > x) r = mid -1;
        }
        for(int j = i-1; j >= l; j--) {
            a[j+1] = a[j];
        }
        a[l] = x;

    }
}

//Radix Sort
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Hàm sắp xếp mảng theo từng chữ số
void countSort(int arr[], int n, int exp) {
    int output[n];
    int i, count[10] = {0};

    // Đếm số lần xuất hiện của từng chữ số
    for (i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // Tính tổng số lần xuất hiện
    for (i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Đưa các phần tử vào mảng output
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Sao chép mảng output vào mảng arr
    for (i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Hàm sắp xếp radix sort
void radix_Sort(int arr[], int n) {
    int m = getMax(arr, n);

    // Sắp xếp theo từng chữ số từ thấp đến cao
    for (int exp = 1; m / exp > 0; exp *= 10) {
        countSort(arr, n, exp);
    }
}
void radixSort(int arr[], int n) {
    int cD = 0, cA = 0;
    for(int i = 0; i< n; i++) {
        if(arr[i] < 0) cA++;
        else cD++;
    }
    int *b = new int [cD];
    int *c = new int [cA];
    int icD = 0, icA = 0;
    for(int i = 0; i< n; i++) {
        if(arr[i] < 0) c[icA++] = arr[i];
        else b[icD++] = arr[i];
    }
    radix_Sort(b,cD);
    radix_Sort(c,cA);
    for(int i = 0; i< n; i++) {
        if(i<cA) arr[i] = c[i];
        else arr[i] = b[i-cA];
    }
}
// Selection Sort


void selectionSort(int a[], int n) {
    for(int i = 0; i < n; i++) {
        int min = i;
        for(int j = i+1; j <  n; j++)
        {
            if(a[j] < a[min]) min = j;
            
        }
        if(min != i)
        swap(a[min], a[i]); 
    }
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int &x : a) {cin >> x;}
    int l = 0, r = n-1;
    radixSort(a,n);
    for(int i = 0; i<n; ) {
        cout << a[i++] << " ";
    }
    
    
}