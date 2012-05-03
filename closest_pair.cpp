#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

const int maxn=10005;
const double eps=1e-8;

struct Point {
	double x,y,dis;
} p[maxn];

int n;

bool cmpp(const Point &p1,const Point &p2) {
	return p1.dis<p2.dis;
}

void solve() {
	sort(p,p+n,cmpp);
	double ans=1e18,now;
	for (int i=0;i<n-1;i++)
		for (int j=i+1;j<n;j++) {
			if (p[j].dis-p[i].dis>ans-eps) break;
			now=sqrt((p[i].x-p[j].x)*(p[i].x-p[j].x)+(p[i].y-p[j].y)*(p[i].y-p[j].y));
			if (now+eps<ans) ans=now;
		}
	if (ans<10000) printf("%.4lf\n",ans);
	else printf("INFINITY\n");
}

int main(int argc, char *argv[]) {
	char *fn=argv[1];
	freopen(fn,"r",stdin);
	while (scanf("%d",&n)!=EOF&&n) {
		for (int i=0;i<n;i++) {
			scanf("%lf %lf",&p[i].x,&p[i].y);
			p[i].dis=sqrt(p[i].x*p[i].x+p[i].y*p[i].y);
		}
		solve();
	}
	return 0;
}