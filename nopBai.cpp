#include <bits/stdc++.h>
using namespace std;
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
int getInteger(string s) {
    int n; 
    do{
        cin >> n;
    }while(n < 1 || n > 1000000);
    return n;
}
void generateArray(int *&a, int n) {
    srand(time(NULL));
    for(int i = 0; i < n; i++) {
        a[i] = -2000 + rand()% 2000+2000-1;
    }
}
void outputArray(int *a, int n) {
    for(int i = 0;i < n; i++) {
        cout << a[i] << " ";
    }
} 
void box(int x, int y, int w, int h, int t_color,string nd) {
	SetColor(3);
	gotoXY(x+1, y+1) ;
	cout << nd;
	SetColor(t_color);
	if(h<= 1 || w <= 1) return ;
	for(int ix = x; ix <= x + w; ix++) {
		gotoXY(ix, y) ;
		cout << char(196);
		gotoXY(ix,y+h);
		cout << char(196);
	}
	for(int iy = y; iy <= y + h; iy++) {
		gotoXY(x,iy);
		cout << char(179);
		gotoXY(x+w,iy);
		cout << char(179);
	}
	gotoXY(x,y); cout << char(218);
	gotoXY(x+w,y); cout << char(191);
	gotoXY(x, y+h); cout << char(192);
	gotoXY(x+w, y+h); cout << char (217);
}
int Menu () {
    cout << " __________________________ " << endl;
	cout << "| ********* MENU ********* |" << endl;
	cout << "| 1.Selection Sort         |" << endl;
	cout << "| 2.Interchange Sort       |" << endl;
	cout << "| 3.Insertion Sort         |" << endl;
	cout << "| 4.BinaryInsertion Sort   |" << endl;
	cout << "| 5.Bubble Sort            |" << endl; 
	cout << "| 6.Shake Sort             |" << endl;
	cout << "| 7.Counting Sort          |" << endl;
	cout << "| 8.Quick Sort             |" << endl;
	cout << "| 9.Merge Sort             |" << endl;
	cout << "| 10.Heap Sort             |" << endl;
	cout << "| 11.Shell Sort            |" << endl;
	cout << "| 12.Radix Sort            |" << endl;
	cout << "| 13.Quit                  |" << endl;
	cout << "|__________________________|" << endl;
	cout << endl;
    cout << "\nPlease choose an algorithm: \n";
    // cout << "           __.MENU.__           ";
	// box(1,1,32,2,11,"1.Selection Sort");
	// box(1,1+2,32,2,11,"2.Interchange Sort");
	// box(1,1+4,32,2,11,"3.Insertion Sort");
	// box(1,1+6,32,2,11,"4.BinaryInsertion Sort");
	// box(1,1+8,32,2,11,"5.Bubble Sort");
	// box(1,1+10,32,2,11,"6.Shake Sort");
	// box(1,1+12,32,2,11, "7.Counting Sort");
	// box(1,1+14,32,2,11, "8.Quick Sort");
	// box(1,1+16,32,2,11,"9.Merge Sort");
	// box(1,1+18,32,2,11,"10.Heap Sort");
	// box(1,1+20,32,2,11,"11.Shell Sort");
	// box(1,1+22,32,2,11,"12.Radix Sort");
	// box(1,1+24,32,2,11,"13.Quit");
	// for(int i = 1; i < 13; i++) {
	// 	gotoXY(1,1 + (i*2)) ; cout << char(195);
	// 	gotoXY(1+32,1 +(i*2)); cout << char(180);
	// }
	
}
int main () {
    int n = getInteger("Please enter a number in a range 1...1000000");
    int *a = new int [n];
    generateArray(a,n);
    outputArray(a,n);
    char x ;
    do {
    Menu();
    int choose;
    cin >> choose;
    switch(choose) {
        case 1: { 
            clock_t start = clock() ;
            quickSort(a,0, n-1);
            clock_t finish = clock();
            cout << "\nTime: " << (double)(finish-start)/CLOCKS_PER_SEC << "s";
            break; 
            }
        case 2: {
            clock_t start = clock() ;
            mergeSort(a,0,n-1); 
            clock_t finish = clock();
            cout << "\nTime: " << (double)(finish-start)/CLOCKS_PER_SEC << "s";
            break; 
        }
        case 3:
        {
            clock_t start = clock();
            radixSort(a,n);
            clock_t finish = clock() ;
            cout << "\nTime: " << (double)(finish-start)/CLOCKS_PER_SEC << "s";
            break;

        } 
        case 4: case 5: case 6: case 7: case 8: case 9: case 10 : case 11 : case 12 : break;
        
    }
    if(choose == 13) {
        cout << "See you again !!";
        break;
    }
    cout << "\nDo you want to continue, bae ??\n";
    cin >> x;
    if(x != 'y' && x != 'Y') {
        if(x == 'n' || x == 'N') {
            cout << "\nSee you again !!";
        }
        else {
            cout << "\nNhap cai gi vay ban";
        }
    }
    else continue;
    }while(x == 'y' || x == 'Y');
}