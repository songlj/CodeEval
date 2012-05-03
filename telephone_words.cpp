#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
using namespace std;

char s[10];
char a[10][5]={"0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
int b[10];
bool first;

void sub(int n) {
	if (n==7) {
		if (!first) printf(",");
		first=false;
		for (int i=0;i<n;i++)
			printf("%c",a[s[i]-'0'][b[i]]);
		return;
	}
	for (int i=0;i<strlen(a[s[n]-'0']);i++) {
		b[n]=i;
		sub(n+1);
	}
}

void solve() {
	first=true;
	sub(0);
	printf("\n");
}

int main(int argc, char *argv[]) {
	char *fn=argv[1];
	freopen(fn,"r",stdin);
	while (scanf("%s",s)!=EOF) {
		solve();
	}
	return 0;
}