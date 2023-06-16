#include <bits/stdc++.h>
#include <math.h>
using namespace std;
// int main () {
//     int *a = new int [1000000];

//     int m; cin >> m;
//     while(m) {
//         int c = 0;
//         int x; cin >> x;
//         for(int i = 0; i < n; i++) {
//             if(a[i] == x) {cout << i << endl;
//             break;}
//             c++;
//         }
//         if(c == n) cout << "-1" << endl;
//         m--;
//     }
// }
// int* inputArray(int *&a, int &n) {
//     a = new int[1000000];
//     cin >> n;
//     for(int i = 0; i < n; i++ )
//     {
//         cin >> a[i];
//     }
//     return a;
// }
// void findElements(int a[],int n, int m) {
//     cin >> m;
//     while(m) {
//         int c = 0;
//         int x; cin >> x;
//         for(int i = 0; i < n; i++) {
//             if(a[i] == x) {cout << i << endl;
//             break;}
//             c++;
//         }
//         if(c == n) cout << "-1" << endl;
//         m--;
//     }
// }

// int main()
// {
//     int n,m;
//     int *a=NULL;
//     inputArray(a,n);
//     findElements(a,n,m);

//     return 0;
// }

//4
// int* inputArray(int *&a, int &n) {
//     a = new int[1000000];
//     cin >> n;
//     for(int i = 0; i < n; i++ )
//     {
//         cin >> a[i];
//     }
//     return a;
// }

// int binarySearch2(int *a, int n, int x) {
//     int c = -1;
//     int k = n/2-0.5;
//     if(x < a[k]) {
//     for(int i = k; i >= 0; i--) {
//         if(x == a[i]) return i;
//     }
//     return c;
//     }
//     else if(a[k] < x) {
//     for(int i = n -1; i >= k; i--) {
//         if(x == a[i]) return i;
//     }
//     return c;
//     }
//     else {
//     for(int i = n-1; i >= k; i--) {
//         if(x == a[i]) return i;
//     }
//     return c;
//     }
// }
// int main()
// {
//     int n, *a = NULL;
//     inputArray(a,n); //Luu y van de tham chieu cho con tro a va n

//     // nhap cac gia tri can tim, neu nhap -1 thi ket thuc viec tim kiem
//     int x;
//     while(1)
//     {
//         cin>>x;
//         if(x==-1)break;
//         cout<<binarySearch2(a,n,x)<<endl;

//     }

//     return 0;
// }


// // 3
int* inputArray(int *&a, int &n) {
    a = new int[1000000];
    cin >> n;
    for(int i = 0; i < n; i++ )
    {
        cin >> a[i];
    }
    return a;
}
int check(int *a, int n, int x) {
    int i;
    int l = 0, r = n-1;
    while(l <= r) {
        i = (l+r)/2;
        if(a[i] == x) return i;
        if(a[i] < x) l = i+1;
        else if(a[i] > x) r = i -1;
    }
    return -1;

}
void findElements(int *a, int n, int m) 
{

    cin >> m;
    while (m)
    {
        int x;
        cin >> x;
        cout << check(a,n,x) << endl;
        m--;
    }
}

int main()
{
    int n,m;
    int *a=NULL;
    inputArray(a,n);
    findElements(a,n,m);

    return 0;
}
