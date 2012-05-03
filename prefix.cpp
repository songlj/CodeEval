#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stack>
#include <sstream>
using namespace std;

const int maxn=1005;

char s[maxn];
stack <char> op;

void solve() {
	while (!op.empty()) op.pop();
	istringstream sin(s);
	char t[maxn];
	while (sin>>t) {
		if (t[0]=='+' || t[0]=='*' || t[0]=='/')
			op.push(t[0]);
		else
			break;
	}
	bool neg=false;
	int p=0;
	if (t[0]=='-') {
		neg=true;
		p=1;
	}
	int num1=0,num2;
	for (;t[p];p++)
		num1=num1*10+t[p]-'0';
	if (neg) num1=-num1;
	while (sin>>num2) {
		char o=op.top();
		op.pop();
		if (o=='+') num1+=num2;
		if (o=='*') num1*=num2;
		if (o=='/') num1/=num2;
	}
	cout<<num1<<endl;
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
