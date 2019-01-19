#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
vector<pair<int,int>> tree(10010);
int for_root[10010];
int n;
int minarr[10010];
int maxarr[10010];
int levelmax[10010];
int levelmin[10010];
int pos = 1;
int depth = 1;
int find_root(void) {
       for (int i = 1; i <= n; ++i) {
               if (for_root[i] == 1) {
                      return i;
               }
       }
       return -9999;
}
void cal(int root,int level) {
       if (level > depth) {
               depth = level;
       }
       int nextnode = tree[root].first;
       if (nextnode != -1) {
               cal(nextnode,level+1);
       }
       //cout << root << ' ' << level << endl;
       levelmax[level] = max(levelmax[level], pos);
       levelmin[level] = min(levelmin[level], pos);
       pos++;
       
       nextnode = tree[root].second;
       if (nextnode != -1) {
               cal(nextnode, level + 1);
       }
       
}
int main(void) {
       for (int i = 0; i < 10010; ++i) {
               levelmax[i] = -1;
               levelmin[i] = 99999999;
       }
       cin >> n;
       for (int i = 0; i < n; ++i) {
               int a, b, c;
               cin >> a >> b >> c;
               tree[a] = make_pair(b,c);
               for_root[a]++;
               if (b != -1) {
                      for_root[b]++;
               }
               if (c != -1) {
                      for_root[c]++;
               }
       }
       int root = find_root();
       cal(root, 1);
       int ans = 0;
       int ansidx = 0;
       for (int i = 1; i <= depth; ++i) {
               int temp = levelmax[i] - levelmin[i] + 1;
               if (ans < temp) {
                      ansidx = i;
                      ans = temp;
               }
       }
       cout << ansidx << ' ' << ans << endl;
       /*for (int i = 1; i <= depth; ++i) {
               cout << "level : " << i << " max : " << levelmax[i];
               cout << " min : " << levelmin[i] << endl;
       }
*/
       return 0;
}