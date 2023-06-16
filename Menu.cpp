#include <bits/stdc++.h>
#include "mylib.h"
#define MIN -2000
#define MAX 2000
using namespace std;

int getInteger(string s) {
	int n;
	do {
		cout << "Please choose a number in a range 1 to 100.000.000: ";
		cin >> n;
		if (n < 0 || n > 100000000 || n == 0) {
			cout << "Nhap lai: ";
		}
	} while (n < 0 || n > 100000000 || n == 0);
	return n;
}

void generateArray(int a[], int n) {
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		a[i] = MIN + rand() % (MAX - MIN + 1);
	}
}

void outputArray(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

void Menu() {
	SetColor(11);
	cout << char(218);
	for(int i = 0; i< 32; i++) {
		cout << char(196);
	}
	cout << char(191) <<  endl;
	
	cout << char(179) <<"          " << char(95) << char(95) <<". MENU ." << char(95) << char(95) <<   "          " <<char(179) << endl;
	cout << char(179) <<"                                " <<char(179) << endl;
	cout << char(179) <<"   1.Selection Sort             " <<char(179) << endl;
	cout << char(179) <<"   2.Interchange Sort           " <<char(179) << endl;
	cout << char(179) <<"   3.Insertion Sort             " <<char(179) << endl;
	cout << char(179) <<"   4.BinaryInsertion Sort       " <<char(179) << endl;
	cout << char(179) <<"   5.Bubble Sort                " <<char(179) << endl; 
	cout << char(179) <<"   6.Shake Sort                 " <<char(179) << endl;
	cout << char(179) <<"   7.Counting Sort              " <<char(179) << endl;
	cout << char(179) <<"   8.Quick Sort                 " <<char(179) << endl;
	cout << char(179) <<"   9.Merge Sort                 " <<char(179) << endl;
	cout << char(179) <<"   10.Heap Sort                 " <<char(179) << endl;
	cout << char(179) <<"   11.Shell Sort                " <<char(179) << endl;
	cout << char(179) <<"   12.Radix Sort                " <<char(179) << endl;
	cout << char(179) <<"   13.Quit                      " <<char(179) << endl;
	
	cout << char(192);
	for(int i = 0; i < 32; i++) {
		cout << char(196);
	}
	cout << char(217);
	
    
}
// 1
void SelectionSort(int a[], int n) {
	int i, j, min;
	for (int i = 0; i < n - 1; i++) {
		min = i;
		for (int j = i + 1; j < n; j++) {
			if (a[j] < a[min]) {
				min = j;
			}
		}
		swap(a[i], a[min]);
	}
}
// 2
void InterchangeSort(int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] > a[j]) {
				swap(a[i], a[j]);
			}
		}
	}
}
// 3
void InsertionSort(int a[], int n) {
	for (int i = 1; i < n; i++) {
		int x = a[i];
		int j;
		for (j = i - 1; j >= 0; j--) {
			if (x < a[j])
				a[j + 1] = a[j];
			else
				break;
		}
		a[j + 1] = x;
	}
}
// 4
void BinaryInsertionSort(int a[], int n) {
	for (int i = 1; i < n; i++) {
		int x = a[i];
		int l = 0;
		int r = i - 1;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (x < a[mid]) {
				r = mid - 1;
			}
			else if (x > a[mid]) {
				l = mid + 1;
			}
		}
		for (int j = i - 1; j >= l; j--) {
			a[j + 1] = a[j];
		}
		a[l] = x;
	}
}
// 5
void BubbleSort(int a[], int n) {
	bool swapped;
	for (int i = 0; i < n; i++) {
		swapped = false;
		for (int j = 0; j < n - i - 1; j++) {
			if (a[j] > a[j + 1]) {
				swap(a[j], a[j + 1]);
				swapped = true;
			}
		}
		if (swapped == false)
			break;
	}
}
// 6
void ShakeSort(int a[], int n) {
	int l = 0;
	int r = n - 1;
	int k = 0;
	while (l < r) {
		for (int i = l; i < r; i++) {
			if (a[i] > a[i + 1]) {
				swap(a[i], a[i + 1]);
				k = i;
			}
		}
		r = k;
		for (int i = r; i > l; i--) {
			if (a[i] < a[i - 1]) {
				swap(a[i], a[i - 1]);
				k = i;
			}
		}
		l = k;
	}
}
// 7
void CountingSort(int a[], int n) {
	int* b = new int[n];
	int max = a[0];
	int min = a[0];
	for (int i = 1; i < n; i++)
	{
		if (a[i] > max)
			max = a[i];
		else if (a[i] < min)
			min = a[i];
	}
	int k = max - min + 1;
	int* count_array = new int[k];
	fill_n(count_array, k, 0);
	for (int i = 0; i < n; i++)
		count_array[a[i] - min]++;
	for (int i = 1; i < k; i++)
		count_array[i] += count_array[i - 1];
	for (int i = 0; i < n; i++)
	{
		b[count_array[a[i] - min] - 1] = a[i];
		count_array[a[i] - min]--;
	}
	for (int i = 0; i < n; i++)
		a[i] = b[i];
}
// 8
void quicksort(int a[], int l, int r) {
	int i = l, j = r;
	int x = a[(l + r) / 2];
	int dem = 0;
	while (i <= j) {
		while (a[i] < x) {
			i++;
		}
		while (a[j] > x) {
			j--;
		}
		if (i <= j) {
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}
	if (l < j)
		quicksort(a, l, j);
	if (i < r)
		quicksort(a, i, r);
}
// 9
void Merge(int a[], int l, int m, int r) {
	int n1 = m - l + 1;
	int n2 = r - m;

	int* L = new int[n1];
	int* R = new int[n2];

	for (int i = 0; i < n1; i++)
		L[i] = a[l + i];
	for (int j = 0; j < n2; j++)
		R[j] = a[m + 1 + j];

	int i = 0, j = 0; int k = l;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			a[k++] = L[i];
			i++;
		}
		else
		{
			a[k++] = R[j];
			j++;
		}

	}
	while (i < n1)
	{
		a[k++] = L[i++];
	}
	while (j < n2)
	{
		a[k++] = R[j++];
	}
}

void MergeSort(int a[], int l, int r) {
	if (l < r) {
		int m = l + (r - l) / 2;
		MergeSort(a, l, m);
		MergeSort(a, m + 1, r);
		Merge(a, l, m, r);
	}
}
// 10
void heapify(int a[], int N, int i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if (l < N && a[l] > a[largest])
		largest = l;
	if (r < N && a[r] > a[largest])
		largest = r;
	if (largest != i) {
		swap(a[i], a[largest]);
		heapify(a, N, largest);
	}
}

void HeapSort(int a[], int N)
{
	for (int i = N / 2 - 1; i >= 0; i--)
		heapify(a, N, i);
	for (int i = N - 1; i > 0; i--) {
		swap(a[0], a[i]);
		heapify(a, i, 0);
	}
}
// 11
int ShellSort(int a[], int n) {
	for (int k = n / 2; k > 0; k /= 2) {
		for (int i = k; i < n; i++) {
			int temp = a[i];
			int j;
			for (j = i; j >= k && a[j - k] > temp; j -= k) {
				a[j] = a[j - k];
			}
			a[j] = temp;
		}
	}
	return 0;
}
// 12
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
	

int main() 
{
	
	SetColor(11);
	int n = getInteger("Please choose a number in a range 1 to 100.000.000");
	int* a = new int[n];
	generateArray(a, n);
	outputArray(a, n);
	char c;
	do 
	{   cout << endl;
		Menu();
		cout << "\nPlease choose an algorithm: ";
		int choose;
		cin >> choose;
		switch (choose) 
		{
		case 1: 
		{
			clock_t start = clock();
			SelectionSort(a, n);
			clock_t finish = clock();
			cout << "Sorted Array: ";
			outputArray(a, n);
			cout << "Time: " << (double)(finish - start) / CLOCKS_PER_SEC << "s" << endl;
			break;
		}
		case 2: 
		{
			clock_t start = clock();
			InterchangeSort(a, n);
			clock_t finish = clock();
			cout << "Sorted Array: ";
			outputArray(a, n);
			cout << "Time: " << (double)(finish - start) / CLOCKS_PER_SEC << "s" << endl;
			break;
		}
		case 3: 
		{
			clock_t start = clock();
			InsertionSort(a, n);
			clock_t finish = clock();
			cout << "Sorted Array: ";
			outputArray(a, n);
			cout << "Time: " << (double)(finish - start) / CLOCKS_PER_SEC << "s" << endl;
			break;
		}
		case 4: 
		{
			clock_t start = clock();
			BinaryInsertionSort(a, n);
			clock_t finish = clock();
			cout << "Sorted Array: ";
			outputArray(a, n);
			cout << "Time: " << (double)(finish - start) / CLOCKS_PER_SEC << "s" << endl;
			break;
		}
		case 5: 
		{
			clock_t start = clock();
			BubbleSort(a, n);
			clock_t finish = clock();
			cout << "Sorted Array: ";
			outputArray(a, n);
			cout << "Time: " << (double)(finish - start) / CLOCKS_PER_SEC << "s" << endl;
			break;
		}
		case 6: 
		{
			clock_t start = clock();
			ShakeSort(a, n);
			clock_t finish = clock();
			cout << "Sorted Array: ";
			outputArray(a, n);
			cout << "Time: " << (double)(finish - start) / CLOCKS_PER_SEC << "s" << endl;
			break;
		}
		case 7: 
		{
			clock_t start = clock();
			CountingSort(a, n);
			clock_t finish = clock();
			cout << "Sorted Array: ";
			outputArray(a, n);
			cout << "Time: " << (double)(finish - start) / CLOCKS_PER_SEC << "s" << endl;
			break;
		}
		case 8: 
		{
			clock_t start = clock();
			quicksort(a, 0, n - 1);
			clock_t finish = clock();
			cout << "Sorted Array: ";
			outputArray(a, n);
			cout << "Time: " << (double)(finish - start) / CLOCKS_PER_SEC << "s" << endl;
			break;
		}
		case 9: 
		{
			clock_t start = clock();
			MergeSort(a, 0, n - 1);
			clock_t finish = clock();
			cout << "Sorted Array: ";
			outputArray(a, n);
			cout << "Time: " << (double)(finish - start) / CLOCKS_PER_SEC << "s" << endl;
			break;
		}
		case 10: 
		{
			clock_t start = clock();
			HeapSort(a, n);
			clock_t finish = clock();
			cout << "Sorted Array: ";
			outputArray(a, n);
			cout << "Time: " << (double)(finish - start) / CLOCKS_PER_SEC << "s" << endl;
			break;
		}
		case 11: 
		{
			clock_t start = clock();
			ShellSort(a, n);
			clock_t finish = clock();
			cout << "Sorted Array: ";
			outputArray(a, n);
			cout << "Time: " << (double)(finish - start) / CLOCKS_PER_SEC << "s" << endl;
			break;
		}
		case 12: 
		{
			clock_t start = clock();
			radixSort(a, n);
			clock_t finish = clock();
			cout << "Sorted Array: ";
			outputArray(a, n);
			cout << "Time: " << (double)(finish - start) / CLOCKS_PER_SEC << "s" << endl;
			break;
		}
		case 13: 
		{
			break;
		}
		default: 
		{
			cout << "Nhap sai!" << endl;
			break;
		}
		}
		if (choose == 13) 
		{
			break;
		}
		cout << "Do you want to continue ? Yes / No\n";
		cin >> c;
		if (c != 'Y' && c != 'y') 
		{
			if (c == 'N' || c == 'n') 
			{
				cout << "See you again!";
			}
			else 
			{
				cout << "Error !!" << endl;
				cout << "You entered the wrong syntax :((" << endl;
			}
		}
	} while (c == 'Y' || c ==  'y');
	return 0;
}
	