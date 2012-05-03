#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

const int maxn=1005;
const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};

int n,m;
char a[maxn][maxn][10];

void solve() {
	bool flag[maxn][maxn];
	memset(flag,0,sizeof(flag));
	printf("%s",a[0][0]);
	flag[0][0]=true;
	int y=0,x=1,d=0;
	if (m==1) {
		y=1;x=0;d=1;
	}
	for (int i=1;i<n*m;i++) {
		printf(" %s",a[y][x]);
		flag[y][x]=true;
		y+=dy[d];x+=dx[d];
		if (x==-1||x==m||y==n||flag[y][x]) {
			y-=dy[d];
			x-=dx[d];
			d=(d+1)%4;
			y+=dy[d];
			x+=dx[d];
		}
	}
	printf("\n");
}

int main(int argc, char *argv[]) {
	char *fn=argv[1];
	freopen(fn,"r",stdin);
	while (scanf("%d;%d;",&n,&m)!=EOF) {
		for (int i=0;i<n;i++)
			for (int j=0;j<m;j++)
				scanf(" %s",a[i][j]);
		solve();
	}
	return 0;
}