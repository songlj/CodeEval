#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
using namespace std;

int n;
int a[10];

void solve() {
	int len=0;
	while (n) {
		a[len++]=n%10;
		n/=10;
	}
	for (int i=0;i<len/2;i++) {
		int temp=a[i];
		a[i]=a[len-i-1];
		a[len-i-1]=temp;
	}
	if (next_permutation(a,a+len)) {
		for (int i=0;i<len;i++)
			cout<<a[i];
		cout<<endl;
	}
	else {
		sort(a,a+len);
		if (a[0]==0) {
			for (int i=1;i<len;i++)
				if (a[i]!=0) {
					int temp=a[0];
					a[0]=a[i];
					a[i]=temp;
					break;
				}
		}
		cout<<a[0];
		cout<<0;
		for (int i=1;i<len;i++)
			cout<<a[i];
		cout<<endl;
	}
}

int main(int argc, char *argv[]) {
	char *fn=argv[1];
	freopen(fn,"r",stdin);
	while (cin>>n) {
		solve();
	}
	return 0;
}
