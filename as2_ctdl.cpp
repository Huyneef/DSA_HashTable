#include <bits/stdc++.h>
using namespace std;
/*
void quickSort(int *a, int l, int r, int &c)
{
    int i = l, j = r;
    int x = a[(l + r) / 2];
    while (i <= j)
    {
        while (a[i] > x)
            {i++;}
        while (a[j] < x)
            {j--;}
        if (i <= j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
            c++;
        }
    }
    if (l < j)
        quickSort(a, l, j,c);
    if (r > i)
        quickSort(a, i, r, c);
}
int main () {
    long n;
    cin >> n;
    int *a = new int [n];
    for(int i = 0 ; i < n; i++) {
        cin >> a[i];
    }
    int l = 0, r = n-1;
    int c = 0;
    quickSort(a,l,r,c);
    cout << "Sorted Array: ";
    for(int i = 0 ; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << "\nNumber of times to swap 2 numbers: " << c;
}
*/

// 3
/*
void quickSort(int *c, int l, int r)
{
    int i = l, j = r;
    int x = c[(l + r) / 2];
    while (i <= j)
    {
        while (c[i] < x)
        {
            i++;
        }
        while (c[j] > x)
        {
            j--;
        }
        if (i <= j)
        {
            swap(c[i], c[j]);
            i++;
            j--;
        }
    }
    if (l < j)
        quickSort(c, l, j);
    if (r > i)
        quickSort(c, i, r);
}
int main()
{
    long n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    long m;
    cin >> m;
    int *b = new int[m];
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    int *c = new int[m + n];
    for (int i = 0; i < m + n; i++)
    {
        if (i < n)
            c[i] = a[i];
        else if (i >= n)
            c[i] = b[i - n];
    }
    quickSort(c,0,n+m-1);
    for (int i = 0; i < m + n; i++)
    {
        cout << c[i] << " ";
    }
}
*/

//4
/*
void inputArray(int *&a, int n){
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
}
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
void MergeSort(int a[], int l, int h) {
    if(l < h) {
        int mid = (l+h)/2;
        MergeSort(a,l,mid);
        MergeSort(a,mid + 1,h);
        merge(a,l,mid,h);
    }
}
void outputArray(int *&a, int n){
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}
int binarySearch(int *a, int n, int l, int r, int x) {
    int i;
    while(l <= r) {
        int i = (l+r)/2;
        if(x == a[i]) return i;
        if(a[i] < x) l = i+1;
        else if(a[i] > x) r = i-1;
    }
    return -1;
}
int main()
{
    int n; cin>>n;
    int *a = new int[n];
    inputArray(a,n);
    MergeSort(a,0,n-1);
    cout<<"Sorted Array: ";
    outputArray(a,n);// liet ke cac phan tu cach nhau boi 1 khoang cach

    cout<< "\nFind an element: ";
    int x; cin>>x;
    cout<<x<<endl;
    int result = binarySearch(a,n,0,n-1,x);
    if (result ==-1) cout<<x<<" is not found";
    else cout<<x<<" is found at the position " << result;

	return 0;
}
*/

//7
/*
void evenOddSort(int a[], int n)
{
    
    int cb = 0, cc = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] % 2 == 0) {
            
            cc++;
        }
        else {
            cb++;
            
        }
    }
    int *b = new int [cb] ;
    int *c = new int [cc] ;
    int j = 0, k = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] % 2 == 0) {
            c[j] = a[i] ;
            j++;
        }
        else {
            b[k] = a[i];
            k++;
        }
    }
    sort(b,b+cb); sort(c,c+cc);
    for(int i = 0; i < cc+cb; i ++ ) {
        if(i < cc) cout << c[i] << endl;
        if(i >= cc) cout << b[i-cc] << endl;
    }


}
int main () {
    long n;
    cin >> n;
    int *a = new int [n];
    for(int i = 0 ; i < n; i++) {
        cin >> a[i];
    }
    
    evenOddSort(a,n);
    
}
*/
// 6 7 
/*
void quickSort2(int *a, int l, int r)
{
    int i = l, j = r;
    int x = a[(l + r) / 2];
    while (i <= j)
    {
        while (a[i] > x)
            {i++;}
        while (a[j] < x)
            {j--;}
        if (i <= j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
            
        }
    }
    if (l < j)
        quickSort2(a, l, j);
    if (r > i)
        quickSort2(a, i, r);
}
void quickSort1(int a[], int l, int r)
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
        quickSort1(a, l, j);
    if (r > i)
        quickSort1(a, i, r);
}
void oddEvenSort(int *a, int n)
{
   int cO = 0, cOO = 0;
   for(int i = 0; i < n; i++) {
    if(a[i] % 2 == 0) cO++;
    else cOO++; 
   }
   int *c = new int [cO];
   int *b = new int [cOO];
   int j = 0, k = 0;
   for(int i = 0; i < n; i++) {
    if(a[i] % 2 == 0) {
       c[j++] = a[i];
    }
    else {
        b[k++] = a[i]; 
    }
   }
   sort(c,c+cO);
   sort(b,b+cOO);
   j = 0, k = 0;
   for(int i = 0; i < n; i++) {
    if(a[i] % 2 == 0) {
       a[i] = c[j++];
    }
    else {
        a[i] = b[k++];
    }
   }

}
//5

// void evenSort(int a[], int n)
// {
//     int cO = 0;
//    for(int i = 0; i < n; i++) {
//     if(a[i] % 2 == 0) cO++;
//    }
//    int *c = new int [cO];
//    int j = 0;
//    for(int i = 0; i < n; i++) {
//     if(a[i] % 2 == 0) {
//        c[j++] = a[i];
//     }
//    }
//    sort(c,c+cO);
//    j = 0;
//    for(int i = 0; i < n; i++) {
//     if(a[i] % 2 == 0) {
//        a[i] = c[j++];
//     }
//    }


// }


int main () {
    long n;
    cin >> n;
    int *a = new int [n];
    for(int i = 0 ; i < n; i++) {
        cin >> a[i];
    }
   
    oddEvenSort(a,n);
    cout << "Sorted Array: ";
    for(int i = 0 ; i < n; i++) {
        cout << a[i] << " ";
    }
    
}
*/
