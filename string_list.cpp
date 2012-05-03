#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <vector>
using namespace std;

int n;
char s[100];
bool flag[256];
vector <char> chars;
bool first;

void sub(int now) {
	if (now==n) {
		if (!first) printf(",");
		first=false;
		printf("%s",s);
		return;
	}
	for (int i=0;i<chars.size();i++) {
		s[now]=chars[i];
		sub(now+1);
	}
}

void solve() {
	memset(flag,0,sizeof(flag));
	chars.clear();
	for (int i=0;s[i];i++)
		if (!flag[s[i]]) {
			flag[s[i]]=true;
			chars.push_back(s[i]);
		}
	sort(chars.begin(),chars.end());
	memset(s,0,sizeof(s));
	first=true;
	sub(0);
	printf("\n");
}

int main(int argc, char *argv[]) {
	char *fn=argv[1];
	freopen(fn,"r",stdin);
	while (scanf("%d,%s",&n,s)!=EOF) {
		solve();
	}
	return 0;
}

