
#include <bits/stdc++.h>
using namespace std;


int N;

int count_distinct(const vector<string>& ids){

	map<string,int> Hash; 
    int count = 0;
    unordered_map<string, int> freq; // bảng băm lưu trữ số lượng xuất hiện của từng mã hàng

    for (const auto& id : ids) {
        freq[id]++; // tăng số lượng xuất hiện của mã hàng lên 1
    }

    for (const auto& [id, f] : freq) {
        if (f > 0) { // nếu mã hàng xuất hiện ít nhất một lần
            count++; // tăng biến đếm số lượng các mã hàng khác nhau lên 1
        }
    }

    return count;
	
}

int main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	cin >> N;
	vector<string> ids(N);
	
	for (int i = 0; i < N; i++) cin >> ids[i];
		
	cout << count_distinct(ids);

	return 0;
}

