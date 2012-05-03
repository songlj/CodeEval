#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <sstream>
using namespace std;

const int maxn=105;

int n;
string s;
string f[maxn],r[maxn];

void solve() {
	for (int i=0;i<n;i++) {
		for (;;) {
			size_t pos=s.find(f[i]);
			if (pos==string::npos) break;
			s.replace((int)pos,f[i].length(),r[i]);
		}
	}
	for (int i=0;s[i];i++)
		if (s[i]=='2') s[i]='0';
		else if (s[i]=='3') s[i]='1';
	cout<<s<<endl;
}

int main(int argc, char *argv[]) {
	char *fn=argv[1];
	freopen(fn,"r",stdin);
	string str;
	while (cin>>str) {
		for (int i=0;str[i];i++)
			if (str[i]==';'||str[i]==',') str[i]=' ';
		istringstream sin(str);
		sin>>s;
		n=0;
		while (sin>>f[n]>>r[n]) {
			for (int i=0;r[n][i];i++)
				r[n][i]+=2;
			n++;
		}
		solve();
	}
	return 0;
}