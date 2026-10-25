#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, k;
	if (!(cin >> N >> k)) {
		return 0;
	}

	vector<int> cost(N, 0);
	vector<char> seen(1001, 0);
	vector<int> coins;
	coins.reserve(1000);

	for (int city = 1; city < N; ++city) {
		int c;
		cin >> c;
		cost[city] = c;
		if (!seen[c]) {
			seen[c] = 1;
			int doubled = c * 2;
			if (doubled <= k) {
				coins.push_back(doubled);
			}
		}
	}

	vector<char> reachable(k + 1, 0);
	reachable[0] = 1;
	for (int coin : coins) {
		for (int value = coin; value <= k; ++value) {
			if (reachable[value - coin]) {
				reachable[value] = 1;
			}
		}
	}

	int Q;
	cin >> Q;
	string answer;
	answer.reserve(static_cast<size_t>(Q) * 4);

	while (Q--) {
		int A, B;
		cin >> A >> B;

		int base = 0;
		if (A != 0) {
			base += cost[A];
		}
		if (B != 0) {
			base += cost[B];
		}

		if (base > k) {
			answer += "No\n";
			continue;
		}

		int remaining = k - base;
		if (reachable[remaining]) {
			answer += "Yes\n";
		} else {
			answer += "No\n";
		}
	}

	cout << answer;
	return 0;
}
