#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

const int maxn=1005;

char s[maxn];
char s1[maxn],s2[maxn];
int l1,l2;

bool check(int i,int j) {
    if (j==l2) return true;
	if (i==l1&&(s2[j]!='#'||l2-j>1)) return false;
	if (s1[i]==s2[j]) return check(i+1,j+1);
	if (s2[j]=='#') {
		bool ret=false;
		for (int k=0;i+k<=l1;k++)
			ret|=check(i+k,j+1);
		return ret;
	}
	return false;
}

void solve() {
	memset(s1,0,sizeof(s1));
	memset(s2,0,sizeof(s2));
	l1=0;l2=0;
	int i=0;
	for (;s[i];i++) {
		if (s[i]==',') break;
		if (s[i]=='*') s1[l1++]='#';
		else if (s[i]=='\\') {
			s1[l1++]='*';
			i++;
		}
		else s1[l1++]=s[i];
	}
	for (i++;s[i];i++) {
		if (s[i]=='*') s2[l2++]='#';
		else if (s[i]=='\\') {
			s2[l2++]='*';
			i++;
		}
		else s2[l2++]=s[i];
	}
	bool ans=false;
	for (int i=0;i<l1;i++) ans|=check(i,0);
	if (ans) cout<<"true"<<endl;
	else cout<<"false"<<endl;
}

int main(int argc, char *argv[]) {
	char *fn = argv[1];
	freopen(fn, "r", stdin);
	while (gets(s)) {
		if (strlen(s)==0) continue;
		solve();
	}
	return 0;
}