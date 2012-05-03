#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

const int maxn=10005;

char str[maxn];
int sa[maxn],rank[maxn];
int lrank[maxn],h[maxn],height[maxn];
int k;

bool cmpchar(const int &a,const int &b) {
	return str[a]<str[b];
}

bool cmprank(const int &a,const int &b) {
	return rank[a]<rank[b]||(rank[a]==rank[b]&&rank[a+k]<rank[b+k]);
}

bool equ(const int &a,const int &b) {
	return lrank[a]==lrank[b]&&lrank[a+k]==lrank[b+k];
}

void createSA(int len) {
	int i=0;
	for (i=0;i<len;i++)
		sa[i]=i;
	sort(sa,sa+len,cmpchar);
	for (rank[sa[0]]=0,i=1;i<len;i++) {
		rank[sa[i]]=rank[sa[i-1]];
		if (str[sa[i]]!=str[sa[i-1]])
			rank[sa[i]]++;
	}
	for (k=1;k<len;k*=2) {
		sort(sa,sa+len,cmprank);
		for (i=0;i<len;i++)
			lrank[i]=rank[i];
		for (rank[sa[0]]=0,i=1;i<len;i++) {
			rank[sa[i]]=rank[sa[i-1]];
			if (!equ(sa[i],sa[i-1]))
				rank[sa[i]]++;
		}
	}
}

void calcHeight(int len) {
	int p1,p2,l;
	memset(h,0,sizeof(h));
	for (int i=0;i<len;i++) {
		if (rank[i]==0) {
			h[i]=0;
			continue;
		}
		p1=rank[i]-1;
		p2=rank[i];
		if (i==0||h[i-1]<=1)
			l=0;
		else
			l=h[i-1]-1;
		for (;sa[p1]+l<len&&sa[p2]+l<len;l++)
			if (str[sa[p1]+l]!=str[sa[p2]+l]) break;
		h[i]=l;
	}
	for (int i=0;i<len;i++)
		height[i]=h[sa[i]];
}


void solve() {
	int len=strlen(str);
	str[len++]='#';
	str[len]=0;
	createSA(len);
	calcHeight(len);
	int k,ans=len;
	for (k=(len-1)/2;k>0;k--) {
		int st=2;
		while (st<len) {
			while (st<len&&height[st]<k) st++;
			if (st==len) continue;
			int ed=st;
			while (ed<len&&height[ed]>=k) ed++;
			int sa_max=sa[st-1];
			int sa_min=sa[st-1];
			for (int i=st;i<ed;i++) {
				sa_max=max(sa_max,sa[i]);
				sa_min=min(sa_min,sa[i]);
			}
			if (sa_max-sa_min>=k) ans=min(ans,sa_min);
			st++;
		}
		if (ans!=len) break;
	}

	if (k==0) printf("NONE\n");
	else {
		for (int i=0;i<k;i++)
			printf("%c",str[ans+i]);
		printf("\n");
	}
}

int main(int argc, char *argv[]) {
	char *fn=argv[1];
	freopen(fn,"r",stdin);
	while (gets(str)) {
		if (strlen(str)==0) continue;
		solve();
	}
	return 0;
}