#include <bits/stdc++.h>
#include <math.h>
using namespace std;

// 1 vi tri so am
/*

void  nhapMang(int a[], int n) {
    for(int i =0; i < n ;i++) {
        cin >> a[i];
    }
}
void xuatMang(int a[],int n) {
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}
void viTriSoAm(int a[], int n) {
    int c = 0, k = 0;
    int min = a[0];
    for(int i = 0; i < n; i ++) {
        if(a[i] < 0) {
            c++; k = i;
            if(c == 1) cout << "Vi tri so am dau tien: " << i << endl;
            if(min > a[i]) min = a[i];
        }

    }
    if(c > 0) {
        cout << "Vi tri so am cuoi cung: " << k << endl;
        cout << "So am nho nhat: " << min << endl;
    }
    else cout << "Mang khong co so am";
}

int main()
{
    int n, a[10000];
    cin>>n;
    nhapMang(a,n);
    cout<<"Mang vua nhap:"<<endl;
    xuatMang(a,n);
    cout<<endl;
    viTriSoAm(a,n);

    return 0;
}
*/

// 2 mang so giai thua
/*
//Goi y: SV co the viet cac ham sau

long long Factorial (int n); // tinh n!
int isFactorial (int n); // kiem tra n co phai la 1 so giai thua hay khong,
// nghia la co 1 con so i sao cho i!=n
int isTotalFactorial(int a[], int n); //kiem tra mang co phai chua toan so giai thua hay khong

void inputArray(int a[], int &n) {
    cin >> n;
    for(int i = 0; i < n; i++) {cin >> a[i];}
}
void outputArray(int a[], int n) {
    for(int i = 0; i < n;i++) {
        cout << a[i] << " ";
    }
}
long long Factorial(int n) {
    int s = 1;
    for(int i = 1; i <= n; i++) {
        s *= i;
        if(s == n) break;
        if(s > n) break;
    }
    return s;
}
int isFactorial(int n) {
    if(n == 0 || n == 1) return 1;
    else if(Factorial(n) == n) return 1;
    else return 0;
}
int isTotalFactorial(int a[], int n) {
    for(int i = 0; i < n; i++) {
        if(!isFactorial(a[i])) {return 0;}
    }
    return 1;
}
long maxFactorial(int a[], int n) {
    int max = a[0];
    for(int i = 0; i < n; i++) {
        if(max < a[i]) max = a[i];
    }
    return max;
}

int main()
{
    int n, a[100];
    inputArray(a,n);
    cout<<"Array:"<<endl;
    outputArray(a,n);
    cout<<endl;

    if (isTotalFactorial (a,n)==1)
    {
        cout <<"Mang toan so giai thua"<<endl;
        cout << "So giai thua lon nhat: "<<maxFactorial (a,n);
    }
    else cout<<"Mang khong phai chua toan cac so giai thua";

    return 0;
}
*/

// 3 create prime number array, find y
/*
#define MAX 100
bool snt(int n){
    if(n<2) return 0;
    for(int i = 2; i <= sqrt(n); i++) {
        if(n % i == 0) return 0;
    }
    return 1;
}
void NhapmangSNT(int a[], int &n) {
    cin >> n;
    if(n >= 1 && n <= 100) {
        int j = 0;
    for(int i = 2; ; i++) {
        if(snt(i)) {
        a[j] = i;
        j++;
        }
        if(j == n) break;
    }
    }
}
void Xuatmang(int a[], int n) {
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

}
int SoPhanTuChuaY(int a[], int n, int y) {
    int c = 0, cu = 0, l;
    for(int i = 0 ; i < n; i ++) {
        c = 0;
        while(a[i]) {
            l = a[i] % 10;
            if(l == y) c++;
            a[i] /= 10;
        }
        if(c > 0) cu++;
    }
    return cu;
}
int main()
{
    int a[MAX], n, y;
    cin >>y;
    NhapmangSNT(a,n);
    cout<<"Mang a gom " <<n<<" so nguyen to tang dan, bao gom: \n";
    Xuatmang(a,n);
    cout<<"\nSo phan tu chua chu so "<<y<<": "<<SoPhanTuChuaY(a, n, y);

    return 0;
}
*/

// 4 special reverse array
/*
void inputArray(int a[], int &n)
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}
void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void reverseArray(int a[], int n)
{
    int cdj = (n / 2) - 0.5;
    int temp = a[cdj];
    int l = 0, r = n - 1;
    while (l <= r)
    {
        while (a[l] < temp)
        {
            l++;
        }
        while (a[r] > temp)
        {
            r--;
        }
        if(l <= r) {
            swap(a[l], a[r]) ;
            l++;
            r--;
        }
    }
}
int main()
{
    int a[100], n;
    inputArray(a, n);

    // In mang ban dau
    printArray(a, n);

    // Dao mang
    reverseArray(a, n);

    // In mang sau khi dao
    cout << "Reversed array is" << endl;
    printArray(a, n);

    return 0;
}
*/


// 6 Thêm vào trước số nguyên tố 1 số dương
/*
void inputArray(int a[], int &n)
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}
void oArray(int a[], int &n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
bool snt(int n)
{
    if (n < 2)
        return 0;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}
void insertIntoArray(int a[], int &n)
{
    int b[100] = {};
    for (int i = 0; i < n; i++)
    {
        if (snt(a[i]))
        {

            for (int j = n; j > i; j--)
            {
                a[j] = a[j - 1];
            }
            b[i] = 1;
            a[i] = a[i] + 1;
            n++;
            i++;

        }
    }
    oArray(a,n);
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        if(b[i] == 1)
        cout << i << " ";
    }

}
int main()
{
    int a[100], n;
    inputArray(a, n);
    insertIntoArray(a, n);

    return 0;
}
*/
// 7 Nhập ma trận theo từng cột
/*
void nhapMaTran(int a[][100],int &n,int &m) {
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n;j++) {
            cin >> a[i][j];
        }
    }
}
void xuatMaTran(int a[][100],int n,int m) {
    cout << "Ma tran A(" << n << "x" << m << ") da nhap:\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m;j++) {
            cout << a[j][i] << " ";
        }
        cout << endl;
    }
}
int main()
{
    int a[100][100], n, m;
    cin >> n >> m; //n: so dong, m: so cot
    nhapMaTran(a,n,m); //nhap theo thu tu tung cot: nhap cot 0 truoc, roi den cot 1, 2, ...
    xuatMaTran(a,n,m);
    return 0;
}

*/

// 5 Xóa m số chẵn trong mảng kiểu nhiều test case vl
/*
void oArray(int a[], int c)
{
    cout << "After:";
    for (int i = 0; i < c; i++)
    {
        cout << a[i] << " ";
    }
}

int main()
{
    int a[200];
    int n = 0;
    {
        int i = 0;
        do
        {

            cin >> n;
            a[i] = n;
            i++;

        } while (n != -1);
    }
    int m, ce = 0;
    cin >> m;
    int c = 0;
    cout << "Before:";
    for (int i = 0;; i++)
    {
        if (a[i] == -1)
            break;
        cout << a[i] << " ";
        c++;
    }
    cout << endl;
    for (int i = 0; i < c; i++)
    {
        if (a[i] % 2 == 0)
            ce++;
    }

    // vo guong
    if (m == 0)
    {
        cout << "No deletion required";
    }
    else {
    if (ce == 0)
    {
        cout << "There are no even numbers in the array";
    }
    else
    {

        if (ce == c)
        {
            if (ce < m)
            {
                cout << "Not enough " << m << " even numbers but still delete\n";
                cout << "After:Empty";
            }
            else if (ce == m)
            {
                cout << "After:Empty";
            }
            else
            {
                for (int i = 0; i < c; i++)
                {
                    if (a[i] % 2 == 0)
                    {
                        for (int j = i; j < c - 1; j++)
                        {
                            a[j] = a[j + 1];
                        }
                        c--;
                        m--;
                        i--;
                    }
                    if (m == 0)
                        break;
                }
                oArray(a, c);
            }
        }
        else
        {
            if (ce < m)
            {
                cout << "Not enough " << m << " even numbers but still delete\n";

                for (int i = 0; i < c; i++)
                {
                    if (a[i] % 2 == 0)
                    {
                        for (int j = i; j < c - 1; j++)
                        {
                            a[j] = a[j + 1];
                        }
                        c--;
                        ce--;
                        i--;
                    }
                    if (ce == 0)
                        break;
                }
                oArray(a, c);
            }
            else
            {
                for (int i = 0; i < c; i++)
                {
                    if (a[i] % 2 == 0)
                    {
                        for (int j = i; j < c - 1; j++)
                        {
                            a[j] = a[j + 1];
                        }
                        c--;
                        m--;
                        i--;
                    }
                    if (m == 0)
                        break;
                }
                oArray(a, c);
            }
        }
    }
}
}
*/

// 8
/*
void inputMatrix(int a[][50], int &n) {
    cin >> n;
    for(int i =0 ; i < n; i++) {
        for(int j = 0;j < n; j++) {
            cin >> a[i][j];
        }
    }
}
void outputMatrix(int a[][50] ,int n) {
    for(int i = 0; i < n;i++ ) {
        for(int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
int sum(int a[][50],int n) {
    int sum = 0, m =n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j<m-1; j++) {
            sum += a[i][j];
        }
        m--;
    }
    return sum;
}
int main()
{
    int n,a[50][50];
    inputMatrix(a,n);
    cout<<"Matrix:\n";
    outputMatrix(a,n);
    cout<<"Sum = "<<sum(a,n);
    return 0;
}
*/

// 9 horizontal invert array
/*
void inputArray(int a[][100],int n , int m) {
    for(int i =0 ; i < n; i++) {
        for(int j =0 ; j < m ; j++) {
            cin >> a[i][j];
        }
    }
}
void horizontal_invert(int a[][100], int n, int m) {
    for(int i = 0; i < m; i++) {
        int t = 0, b = n-1;
        while(t < b) {
            swap(a[t][i], a[b][i]) ;
            t++;
            b--;
        }
    }
}
void outputArray(int a[][100], int n, int m) {
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m ; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    int n, m;
    cin >> n >> m;


    int a[100][100];

    inputArray(a, n, m);

    horizontal_invert(a, n, m);

    outputArray(a, n, m);

    return 0;
}
*/

// 10
/*
void inputMatrix(int a[][100], int &n) {
    cin >> n;
    for(int i =0 ; i < n; i++) {
        for(int j = 0;j < n; j++) {
            cin >> a[i][j];
        }
    }
}
void outputMatrix(int a[][100] ,int n) {
    for(int i = 0; i < n;i++ ) {
        for(int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
int indexC(int a[][100], int n, int i, int max) {
    for(int j = 0; j < n; j++) {
        if(a[i][j] == max) return j;
    }
}
void maxElementOfEachRow(int a[][100], int n) {
    int max;
    for(int i = 0; i < n ; i++) {
        max = a[i][0];
        for(int j =0; j < n; j ++) {
            if(max < a[i][j]) max = a[i][j];
        }
        int  c = indexC(a,n,i,max);
        cout << "a[" << i << "][" << c << "]=" << max << endl;
    }
}
int main()
{
    int a[100][100];
    int n;
    inputMatrix(a,n);
    cout<<"Matrix: "<<endl;
    outputMatrix(a,n);

    cout<<"Maximum element of each row in the matrix: "<<endl;
    maxElementOfEachRow(a,n); // Tim phan tu lon nhat cua moi dong, xuat vi tri cua phan tu do va gia tri lon nhat.VD: a[0][1]=12

    return 0;
}
*/

// 11
/*
void inputMatrix(int a[][50], int &n,int &m) {

    cin >> n >> m;
    for(int i =0 ; i < n; i++) {
        for(int j = 0;j < m; j++) {

            cin >> a[i][j];
        }
    }
}
void outputMatrix(int a[][50] ,int n,int m ) {
    for(int i = 0; i < n;i++ ) {
        for(int j = 0; j < m; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
int check(int a[][50], int n, int m, int map ) {
    int c = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i][j] == map) {c++;}
        }
    }
    if(c == 1) {
    return 1;
    }
    else return 0;
}
void outDi(int b[], int map) {
    if(!map) b[0] = 1;
    b[map] = map;
}
void uniqueElements(int a[][50], int n, int m) {
    int map, cc =0;
    int b[2500] = {};

    for(int i = 0; i < n;i++ ) {
        for(int j = 0; j < m; j++) {
          map = a[i][j];
          if(check(a, n, m, map)==1) {
          cc++;
          outDi(b,map);
          }
        }
    }

    if(cc == 0) {
        cout << "No unique element in the matrix";
    }
    else {
        cout << "Unique elements in the matrix:" << endl;
        for(int i = 0; i < 2500; i++) {
            if(b[i] != 0) cout << i << " ";
        }
    }
}
int main()
{
    int m,n,a[50][50];
    inputMatrix(a,n,m);
    cout<<"Matrix:\n";
    outputMatrix(a,n,m);
    uniqueElements(a,n,m);
    return 0;
}
*/

//12
int main () {
    string s;
    getline(cin, s) ;
    
    int cP = 0, cN = 0;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] >= 'A' && s[i] <= 'Z' || s[i] >= 'a' && s[i] <= 'z') {
            if(s[i] == 'a' || s[i] == 'u' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'A' || s[i] == 'U' || s[i] == 'I' || s[i] == 'E' || s[i] == 'O')
            cN++;
            else cP++; 
        }
    }
    cout << s.length() << endl << cN << endl << cP;

    
}


