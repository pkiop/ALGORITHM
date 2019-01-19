// [SCC] 백준 2150 Strongly Connected Component
/*
문제해결전략의 scc 코드를 사용
return 되는 sccId는 각 정점이 속해있는 컴포넌트 번호를 가지고 있다. 
그 정점과 컴포넌트 번호를 pair로 묶고 적절히 정렬한다음 출력했다. 

*/
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;
vector<vector<int>> adj;
//각 정점의 컴포넌트 번호, 컴포넌트 번호는 0부터 시작하며,
// 같은 강결합 컴포넌트에 속한 정점들의 컴포넌트 번호가 같다.
vector<int> sccId;
vector<int> discovered;
stack<int> st;
int sccCounter, vertexCounter;
//here를 루트로 하는 서브트리에서 역방향 간선이나 교차간선을
//통해 갈 수 있는 정점 중 최소 발견 순서를 반환한다.
//이미 SCC로 묶인 정점으로 연결된 교차 간선은 무시한다.
int scc(int here) {
	int ret = discovered[here] = vertexCounter++;
	st.push(here);
	for (int i = 0; i < adj[here].size(); ++i) {
		int there = adj[here][i];
		if (discovered[there] == -1)
			ret = min(ret, scc(there));
		//there가 무시해야 하는 교차간선이 아니라면
		else if (sccId[there] == -1)
			ret = min(ret, discovered[there]);
	}
	//here에서 부모로 올라가는 간선을 끊어야 할지 확인한다.
	if (ret == discovered[here]) {
		while (true) {
			int t = st.top();
			st.pop();
			sccId[t] = sccCounter;
			if (t == here) break;
		}
		++sccCounter;
	}
	return ret;
}
vector<int> tarjanSCC() {
	sccId = discovered = vector<int>(adj.size(), -1);
	sccCounter = vertexCounter = 0;
	for (int i = 0; i < adj.size(); i++) if (discovered[i] == -1) scc(i);
	return sccId;
}


int main(void) {
	int n, m;
	cin >> n >> m;
	adj.resize(n + 1);
	int a, b;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		adj[a].push_back(b);
	}
	vector<int> ans = tarjanSCC();
	vector<pair<int, int>> realans;
	int maxnum = 0;
	for (int i = 1; i < ans.size(); ++i) {
		realans.push_back(make_pair(ans[i],i));
		maxnum = max(ans[i], maxnum);
	}
	sort(realans.begin(), realans.end());
	vector<vector<int>> printans;
	printans.resize(maxnum + 1);
	cout << maxnum << '\n';
	for (int i = 0; i < realans.size(); ++i) {
		printans[realans[i].first].push_back(realans[i].second);
	}

	for (int i = 0; i < printans.size(); ++i) {
		for (int j = i + 1; j < printans.size(); ++j) {
			if (printans[i].size() == 0 || printans[j].size() == 0) {
				continue;
			}
			if (printans[i][0] > printans[j][0]) {
				swap(printans[i], printans[j]);
			}
		}
	}

	for (int i = 1; i < printans.size(); ++i) {
		for (int j = 0; j < printans[i].size(); ++j) {
			cout << printans[i][j] << ' ';
		}
		cout << -1 << '\n';
	}

	return 0;
	

}