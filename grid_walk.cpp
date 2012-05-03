#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <set>
#include <vector>
using namespace std;

const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};

int n;
set<pair<int,int> > st;
vector<pair<int,int> > ans;

bool check(int x,int y) {
	int sum=0;
	x=abs(x);y=abs(y);
	while (x) {
		sum+=x%10;
		x/=10;
	}
	while (y) {
		sum+=y%10;
		y/=10;
	}
	return sum<=19;
}

void solve() {
	st.clear();
	st.insert(make_pair(0,0));
	ans.clear();
	ans.push_back(make_pair(0,0));
	for (int i=0;i<ans.size();i++) {
		int x=ans[i].first;
		int y=ans[i].second;
		for (int d=0;d<4;d++) {
			if (check(x+dx[d],y+dy[d])) {
				if (st.find(make_pair(x+dx[d],y+dy[d]))==st.end()) {
					st.insert(make_pair(x+dx[d],y+dy[d]));
					ans.push_back(make_pair(x+dx[d],y+dy[d]));
				}
			}
		}
	}
	cout<<ans.size()<<endl;
}

int main(int argc, char *argv[]) {
	char *fn=argv[1];
	freopen(fn,"r",stdin);
	solve();
	return 0;
}