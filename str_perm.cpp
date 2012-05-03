#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

const int maxn=1005;

char s[maxn];
int a[maxn];

void solve() {
	int n=strlen(s);
	for (int i=0;i<n;i++)
		a[i]=s[i]-'a';
	sort(a,a+n);
	bool flag=false;
	do {
		if (flag) cout<<",";
		flag=true;
		for (int i=0;i<n;i++) {
			char c='a'+a[i];
			cout<<c;
		}
	} while (next_permutation(a,a+n));
	cout<<endl;
}

int main(int argc, char *argv[]) {
	char *fn = argv[1];
	freopen(fn, "r", stdin);
	while (cin>>s) {
		if (strlen(s)==0) continue;
		solve();
	}
	return 0;
}