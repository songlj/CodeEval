#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
using namespace std;

const int maxn=105;

int l,r;

bool check(int num) {
	char s[20];
	sprintf(s,"%d",num);
	int len=strlen(s);
	for (int i=0;i<len/2;i++)
		if (s[i]!=s[len-1-i]) return false;
	return true;
}

void solve() {
	int ans=0;
	for (int i=l;i<=r;i++) {
		int num=0;
		for (int j=i;j<=r;j++) {
			if (check(j)) num++;
			if ((num&1)==0) ans++;
		}
	}
	cout<<ans<<endl;
}

int main(int argc, char *argv[]) {
	char *fn=argv[1];
	freopen(fn,"r",stdin);
	while (cin>>l>>r) {
		solve();
	}
	return 0;
}
