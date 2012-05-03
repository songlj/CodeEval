#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
using namespace std;

char s[20];
int n,ans;
int op[20];

bool isUgly(long long num) {
	if (num==0) return true;
	return (num%2==0||num%3==0||num%5==0||num%7==0);
}

long long calc() {
	long long tot=0,sign=1;
	long long num=s[0]-'0';
	for (int i=1;i<n;i++) {
		if (op[i]==0) num=num*10+s[i]-'0';
		else {
			tot+=sign*num;
			if (op[i]==1) sign=1;
			else sign=-1;
			num=s[i]-'0';
		}
	}
	tot+=sign*num;
	return tot;
}

void sub(int now) {
	if (now==n) {
		long long num=calc();
		if (isUgly(num)) ans++;
		return;
	}
	for (int i=0;i<3;i++) {
		op[now]=i;
		sub(now+1);
	}
}

void solve() {
	n=strlen(s);
	ans=0;
	sub(1);
	cout<<ans<<endl;
}

int main(int argc, char *argv[]) {
	char *fn=argv[1];
	freopen(fn,"r",stdin);
	while (cin>>s) {
		solve();
	}
	return 0;
}
