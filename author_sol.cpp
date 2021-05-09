#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int x;
		cin >> x;
		vector<int> ans;
		int sum = 0;
		// start the 'last' variable from 9 and continue decreasing it until we form 'x'
		int last = 9;
		// create a while-loop that runs if 'sum' is STRICLY less than 'x', and the
		// 'last' variable is STRICTLY greater than 0, because the digit 0 is useless
		// in getting the sum
		while (sum < x && last > 0) {
			// pick the smaller digit, between the remaining digit that needs to be added
			// to get the value of 'x' (min(x - sum)) and the last digit from where we start
			// to subtract the value of 'x'
			ans.push_back(min(x - sum, last));
			// add the 'last' variable to the 'sum'
			sum += last;
			// decrement the value of 'last' to make the numbers all distinct
			last--;
		}
		if (sum < x) {
			// if 'sum' is not equal to 'x', the print -1
			cout << -1;
		} else {
			// otherwise, print the contents of the vector in reverse order to
			// get the minimum number possible which its digits will add up to 'x'
			reverse(ans.begin(), ans.end());
			for (int i : ans) {
				cout << i;
			}
		}
		cout << '\n';
	}
	return 0;
}
