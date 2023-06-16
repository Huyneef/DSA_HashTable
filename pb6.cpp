
#include <iostream>
#include <cstring>
#include <string>
#define M 10		// M là số nút có trên bảng băm, đủ để chứa các nút nhập vào bảng băm
#define NULLKEY -1
using namespace std;

struct Node {
    int key;
    int value;
};

struct Hash {
    int m;
    Node* hash_Table;
    int N;
};

void initHash(Hash& H) {
    H.m = M;
    H.hash_Table = new Node[M]; 
    H.N = 0;
    for (int i = 0; i < M; i++) {
        H.hash_Table[i].key = NULLKEY;
        H.hash_Table[i].value = NULLKEY;
    }
}

bool isFull(const Hash& H) {
    return H.N == H.m;
}

int hashfunc(int key) {
    if(key<0) key = -key;
    return key % M;
}

void insertHash(Hash& H, int k) {
    if (isFull(H)) {
        cout << "\nBang bam bi day, khong them duoc"; 
        return;
    }
    int i = hashfunc(k);
    int j = 0;
    while (H.hash_Table[i].key != NULLKEY) {
        i = (i + 1) % M;
    }
    H.hash_Table[i].key = k;
    H.hash_Table[i].value = k;
    H.N++;
}

void traverseAllHash(const Hash& H) {
    for (int i = 0; i < M; i++) {
        if (H.hash_Table[i].key != NULLKEY) {
            cout << H.hash_Table[i].key << " ";
        }
        else cout << "-1 ";
    }
    cout << endl;
}

int main()
{
    Hash H;
    initHash(H);

    int n,x;cin>>n; // n la so luong gia tri can phai luu tru
    for (int i = 1; i<=n;i++)
    {
        cin>>x;
        cout<<"\nInsert "<<x;
        insertHash(H,x); // them 1 gia tri du lieu vao bang bam
    }
    cout<<"\nCreated Hash:"<<endl;
    traverseAllHash(H);

    return 0;
}

