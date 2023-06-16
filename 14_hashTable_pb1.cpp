
#include <iostream>
#include <math.h>

using namespace std;

void inputArray(int a[], int& n) {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
}
void printArray(int a[], int n) {
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}
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

void removeDups(int a[], int n) {
    
    quickSort(a,0,n-1);
    
    int m = a[n-1];
    
    int b[m+1] = {};


    for(int i = 0 ; i < n; i++) {
        b[a[i]] = 1;
    }
    
    for(int i = 0 ; i < m+1; i++) {
        if(b[i] == 1) {
            cout << i << " ";
        }
    }
}
int main()
{
    int a[100],n;
    inputArray(a,n);

    // In mang ban dau
    printArray(a, n);

    /* Goi ham thuc hien xuat mang nhung chi xuat nhung gia tri xuat hien lan dau tien,
    *  khong xuat nhung gia tri bi lap lai/bi trung
    */


    cout << "After removing the duplicate elements:" << endl;

    removeDups(a, n);

    return 0;
}
