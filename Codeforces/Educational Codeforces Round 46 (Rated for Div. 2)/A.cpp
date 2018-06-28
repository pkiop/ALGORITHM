#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void) {
	int n;
	cin >> n;
	vector<string> Xst;
	vector<string> XXst;
	vector<string> XXXst;
	vector<string> st;
	string temp;
	for (int i = 0; i < n; ++i) {
		cin >> temp;
		int len = temp.size();
		if (len == 4) {
			XXXst.push_back(temp);
		}
		if (len == 3) {
			XXst.push_back(temp);
		}
		if (len == 2) {
			Xst.push_back(temp);
		}
		if (len == 1) {
			st.push_back(temp);
		}
	}
	vector<string> re;
	for (int i = 0; i < n; ++i) {
		cin >> temp;
		int len = temp.size();
		bool end = false;
		if (len == 4) {
			for (int i = 0; i < XXXst.size(); ++i) {
				if (XXXst[i] == temp) {
					XXXst[i] = "empty";
					end = true;
				}
				if (end) {
					break;
				}
			}
			if (end) {
				continue;
			}
			else {
				re.push_back(temp);
			}
		}
		if (len == 3) {
			for (int i = 0; i < XXst.size(); ++i) {
				if (XXst[i] == temp) {
					XXst[i] = "empty";
					end = true;
				}
				if (end) {
					break;
				}
			}
			if (end) {
				continue;
			}
			else {
				re.push_back(temp);
			}
		}
		if (len == 2) {
			for (int i = 0; i < Xst.size(); ++i) {
				if (Xst[i] == temp) {
					Xst[i] = "empty";
					end = true;
				}
				if (end) {
					break;
				}
			}
			if (end) {
				continue;
			}
			else {
				re.push_back(temp);
			}
		}
		if (len == 1) {
			for (int i = 0; i < st.size(); ++i) {
				if (st[i] == temp) {
					st[i] = "empty";
					end = true;
				}
				if (end) {
					break;
				}
			}
			if (end) {
				continue;
			}
			else {
				re.push_back(temp);
			}
		}
	}
	int len = re.size();
	int ans = 0;
	for (int i = 0; i < len; ++i) {
		temp = re[i];
		int len = temp.size();
		bool end = false;
		if (len == 4) {
			for (int i = 0; i < XXXst.size(); ++i) {
				if (XXXst[i] == temp) {
					XXXst[i] = "empty";
					end = true;
				}
				if (end) {
					break;
				}
			}
			if (end) {
				continue;
			}
			else {
				for (int i = 0; i < XXXst.size(); ++i) {
					if (XXXst[i] != "empty") {
						XXXst[i] = "empty";
						ans++;
					}
				}
			}
		}
		if (len == 3) {
			for (int i = 0; i < XXst.size(); ++i) {
				if (XXst[i] == temp) {
					XXst[i] = "empty";
					end = true;
				}
				if (end) {
					break;
				}
			}
			if (end) {
				continue;
			}
			else {
				for (int i = 0; i < XXst.size(); ++i) {
					if (XXst[i] != "empty") {
						XXst[i] = "empty";
						ans++;
					}
				}
			}

		}
		if (len == 2) {
			for (int i = 0; i < Xst.size(); ++i) {
				if (Xst[i] == temp) {
					Xst[i] = "empty";
					end = true;
				}
				if (end) {
					break;
				}
			}
			if (end) {
				continue;
			}
			else {
				for (int i = 0; i < Xst.size(); ++i) {
					if (Xst[i] != "empty") {
						Xst[i] = "empty";
						ans++;
					}
				}
			}
		}
		if (len == 1) {
			for (int i = 0; i < st.size(); ++i) {
				if (st[i] == temp) {
					st[i] = "empty";
					end = true;
				}
				if (end) {
					break;
				}
			}
			if (end) {
				continue;
			}
			else {
				for (int i = 0; i < st.size(); ++i) {
					if (st[i] != "empty") {
						st[i] = "empty";
						ans++;
					}
				}
			}
		}

	}
	cout << ans << endl;
}