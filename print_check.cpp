#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
using namespace std;

const char s[10][15]={"","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
const char s2[10][15]={"","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
const char s3[10][15]={"Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};

int n;

void output(int num) {
	int a,b,c;
	c=num%10;
	num/=10;
	b=num%10;
	num/=10;
	a=num;
	if (a) printf("%sHundred",s[a]);
	if (b==1) printf("%s",s3[c]);
	else {
		if (b>=2) printf("%s",s2[b]);
		if (c) printf("%s",s[c]);
	}
}

void solve() {
	int a,b,c;
	c=n%1000;
	n/=1000;
	b=n%1000;
	n/=1000;
	a=n;
	if (a) {
		output(a);
		printf("Million");
	}
	if (b) {
		output(b);
		printf("Thousand");
	}
	output(c);
	printf("Dollars\n");
}

int main(int argc, char *argv[]) {
	char *fn=argv[1];
	freopen(fn,"r",stdin);
	while (cin>>n) {
		solve();
	}
	return 0;
}
