#include<bits/stdc++.h>
using namespace std;

int Floor(vector<int>& arr, int n, int x) {
	int low = 0, high = n - 1;
	int ans = -1;

	while (low <= high) {
		int mid = (low + high) / 2;
		
		if (arr[mid] <= x) {
			ans = arr[mid];
			
			low = mid + 1;
		}
		else {
			high = mid - 1; 
		}
	}
	return ans;
}

int Ceil( vector<int>& arr,int n, int x) {
	int low = 0, high = n - 1;
	int ans = -1;

	while (low <= high) {
		int mid = (low + high) / 2;
		
		if (arr[mid] >= x) {
			ans = arr[mid];
			
			high = mid - 1;
		}
		else {
			low = mid + 1; 
		}
	}
	return ans;
}

pair<int, int> getFloorAndCeil( vector<int>& arr,int n, int x) {
	int f = Floor(arr, n, x);
	int c = Ceil(arr, n, x);
	return make_pair(f, c);
}

int main() {
vector<int>v ={33,39,46,51,55,69,72,84};
	int n =v.size(), x = 50;
	pair<int, int> ans = getFloorAndCeil(v, n, x);
	cout << "The floor and ceil are: " << ans.first
	     << " " << ans.second << endl;
	return 0;
}