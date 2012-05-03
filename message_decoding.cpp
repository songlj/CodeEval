#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

const int maxn=1005;

char s[maxn];
char header[maxn];
int len,code,p;

int Bit() {
	return s[p++]-'0';
}

int Len() {
	int len;
	len=4*Bit();
	len+=2*Bit();
	len+=Bit();
	return len;
}

int Code(int len) {
	int val=0,i,pow2=2,base=0;
	for (i=0;i<len;i++)
		val=val*2+Bit();
	for (i=0;i<len-1;i++) {
		base+=pow2-1;
		pow2*=2;
	}
	if (val==pow2-1)
		return -1;
	else
		return val + base;
}

void solve() {
	memset(header,0,sizeof(header));
	p=strlen(s)-1;
	while (s[p]=='0'||s[p]=='1') p--;
	for (int i=0;i<=p;i++)
		header[i]=s[i];
	p++;

	while (len=Len(),len) {
		while (code=Code(len),code!=-1) {
			putchar(header[code]);
		}
	}
	putchar('\n');
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