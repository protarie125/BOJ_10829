#include <algorithm>
#include <bit>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;
using vs = vector<string>;

string n;
vi ns;
ostringstream oss;

bool posi(const vi& v) {
	for (auto i = 0; i < v.size(); ++i) {
		if (0 < v[i]) {
			return true;
		}
	}

	return false;
}

bool odd(const vi& v) {
	return 1 == v[0] % 2;
}

void half(vi& v) {
	auto ret = vi{};

	for (auto i = v.size() - 1; 0 < i; --i) {
		if (1 == v[i] % 2) {
			v[i - 1] += 10;
		}

		v[i] /= 2;
	}

	v[0] /= 2;
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	string n;
	cin >> n;

	reverse(n.begin(), n.end());

	ns = vi(n.length());
	for (auto i = 0; i < n.length(); ++i) {
		ns[i] = n[i] - '0';
	}

	oss = ostringstream{};

	while (posi(ns)) {
		if (odd(ns)) {
			oss << 1;
		}
		else {
			oss << 0;
		}

		half(ns);
	}

	auto ans = oss.str();
	reverse(ans.begin(), ans.end());

	cout << ans;

	return 0;
}