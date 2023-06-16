#include <bits/stdc++.h>
using namespace std;

int N, Q;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> Q;
    unordered_map<string , string> data;
    string username, pass;
    for(int i = 0; i < N; i++) {
        cin >> username >> pass;
        data[username] = pass;
    } 
    for(int i = 0; i < Q; i++) {
        cin >> username;
        if(data.find(username) != data.end()) {
            cout << data[username] << endl;
        }
        else {
            cout << "M chua dang ky!" << endl;
        }
    }
    // cin >> N >> Q;

    // unordered_map<string, string> database; // lưu trữ các cặp (tài khoản, mật khẩu) trong database

    // for (int i = 0; i < N; i++) {
    //     string username, password;
    //     cin >> username >> password;
    //     database[username] = password; // lưu trữ cặp (tài khoản, mật khẩu) vào database
    // }

    // for (int i = 0; i < Q; i++) {
    //     string username;
    //     cin >> username;

    //     if (database.find(username) != database.end()) { // nếu tài khoản có trong database
    //         cout << database[username] << endl; // in ra mật khẩu tương ứng
    //     } else {
    //         cout << "Chua Dang Ky!\n"; // thông báo "Chua Dang Ky!" nếu tài khoản không có trong database
    //     }
    // }

    return 0;
}