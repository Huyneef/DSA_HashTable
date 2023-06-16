
#include <iostream>
#include <cstring>
#include <string>
#define MAX 1000
using namespace std;
struct Node
{
    int key;
    Node* next;
};

// Khai báo cấu trúc bảng băm
struct Hash
{
    Node* bucket[MAX]; // Mảng danh sách liên kết các phần tử trong bảng băm
    int m; // Số địa chỉ có trên bảng băm
    
};

// Khởi tạo bảng băm
void initHash(Hash& H)
{
    for (int i = 0; i < H.m+1; i++)
    {
        H.bucket[i] = NULL;
    }
}

// Tạo một phần tử mới trên bảng băm
Node* getNode(int key)
{
    Node* p = new Node;
    p->key = key;
    p->next = NULL;
    return p;
}

// Thêm một phần tử vào danh sách liên kết tại địa chỉ tương ứng và đảm bảo danh sách liên kết sắp xếp theo thứ tự tăng dần
void insertHash(Hash& H, int key)
{
    // Tính địa chỉ của phần tử
    int index = key % H.m;

    // Tạo một phần tử mới
    Node* p = getNode(key);

    // Thêm phần tử mới vào danh sách liên kết tại địa chỉ tương ứng và đảm bảo danh sách liên kết sắp xếp theo thứ tự tăng dần
    if (H.bucket[index] == NULL || key <= H.bucket[index]->key)
    {
        p->next = H.bucket[index];
        H.bucket[index] = p;
    }
    else
    {
        Node* curr = H.bucket[index];
        while (curr->next != NULL && curr->next->key < key)
        {
            curr = curr->next;
        }
        p->next = curr->next;
        curr->next = p;
    }
}

// Xuất toàn bộ bảng băm
void traverseAllHash(Hash H)
{
    for (int i = 0; i < H.m; i++)
    {
        cout << "Bucket " << i << ": ";
        Node* curr = H.bucket[i];
        while (curr != NULL)
        {
            cout << curr->key << " ";
            curr = curr->next;
        }
        cout << endl;
    }
}

int main()
{
    Hash H;
    cin>>H.m; // m la so dia chi co trong bang bam
    initHash(H); //khoi tao cac bucket

    int n,x;cin>>n; // n la so luong gia tri can phai luu tru
    for (int i = 1; i<=n;i++)
    {
        cin>>x;
        insertHash(H,x); // them 1 gia tri du lieu vao bang bam
    }
    cout<<"Created Hash:"<<endl;
    traverseAllHash(H); // Xuat toan bo cac bucket cua Bang bam

    return 0;
}

