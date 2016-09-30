/*
 * Given a string S of unique lowercase letters, this program will print all
 * subsequences of the given string in lexicographical order.  Since this
 * program runs in exponential time and space, it may be quite slow for input
 * strings longer than 16 characters.
 */

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
	
    string S;
	
	cin >> S;

	const int N = S.length();

	vector<string> vecs[N];

	int idx[26];
	for (int c = 0; c < 26; c++) {
		idx[c] = -1;
	}

	for (int i = N - 1; i >= 0; i--) {
		idx[S[i] - 'a'] = i;
		string curr = string(1, S[i]);
		vecs[i].push_back(curr);
		for (int c = 0; c < 26; c++) {
			if (idx[c] > i) {
				for (string str : vecs[idx[c]]) {
					vecs[i].push_back(curr + str);
				}
			}
		}
	}

	for (int c = 0; c < 26; c++) {
		if (idx[c] >= 0) {
			for (string str : vecs[idx[c]]) {
				cout << str << endl;
			}
		}
	}
    
    return 0;
}
