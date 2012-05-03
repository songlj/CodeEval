#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};

bool flag[4][4];
int n=4;
int ans;

void dfs(int i,int j) {
	if (i==n-1&&j==n-1) {
		ans++;
		return;
	}
	for (int d=0;d<4;d++) {
		int r=i+dy[d];
		int c=j+dx[d];
		if (r>=0&&r<n&&c>=0&&c<n&&!flag[r][c]) {
			flag[r][c]=true;
			dfs(r,c);
			flag[r][c]=false;
		}
	}
}

void solve() {
	ans=0;
	memset(flag,0,sizeof(flag));
	flag[0][0]=true;
	dfs(0,0);
	cout<<ans<<endl;
}

int main(int argc, char *argv[]) {
	solve();
	return 0;
}