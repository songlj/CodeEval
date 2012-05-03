#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

const int maxn=55;

int array[maxn][maxn];
int prev[maxn][maxn];

char s[maxn*2];
char s1[maxn],s2[maxn];
int l1,l2;
 
void print_LCS(int i, int j) {
	if (i==0||j==0) return;

	if (prev[i][j]==1) {
		print_LCS(i-1,j-1);
		printf("%c",s1[i]);
	}
	else if (prev[i][j]==3) print_LCS(i-1,j);
	else if (prev[i][j]==2) print_LCS(i,j-1);
}

void solve() {
	memset(array,0,sizeof(array));
	memset(prev,0,sizeof(prev));
	for (int i=1;i<=l1;i++)
		for (int j=1;j<=l2;j++)
			if (s1[i]==s2[j]) {
				array[i][j]=array[i-1][j-1]+1;
				prev[i][j]=1;
			}
			else {
				if (array[i-1][j]<array[i][j-1]) {
					array[i][j]=array[i][j-1];
					prev[i][j]=2;
				}
				else {
					array[i][j]=array[i-1][j];
					prev[i][j]=3;
				}
			}

	print_LCS(l1,l2);
}

int main(int argc, char *argv[]) {
	char *fn = argv[1];
	freopen(fn, "r", stdin);
	while (gets(s)) {
		if (strlen(s)==0) continue;
		l1=0;
		l2=0;
		memset(s1,0,sizeof(s1));
		memset(s2,0,sizeof(s2));
		s1[0]='#';
		s2[0]='*';
		int i;
		for (i=0;s[i];i++) {
			if (s[i]==';') break;
			s1[++l1]=s[i];
		}
		for (i++;s[i];i++)
			s2[++l2]=s[i];
		solve();
		printf("\n");
	}
	return 0;
}