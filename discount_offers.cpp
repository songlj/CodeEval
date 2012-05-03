#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

const int maxn=105;
const int inf=0x3fffffff;

char s[maxn*10];

int n,m;
int cus_len[maxn];
int cus_vol[maxn];
int cus_con[maxn];
int pro_len[maxn];

int w[maxn][maxn];
int lx[maxn],ly[maxn];
bool sx[maxn],sy[maxn];
int match[maxn];

int gcd(int a,int b) {
	if (b==0) return a;
	else return gcd(b,a%b);
}

void init() {
	for (int i=0;s[i];i++)
		if (s[i]>='A'&&s[i]<='Z') s[i]=s[i]-'A'+'a';
	int p=0,len=strlen(s);
	for (;s[p]!=';';p++);
	n=0;m=0;
	int i=0,j=0,vol=0,con=0;
	while (i<=p) {
		if (s[i]==','||s[i]==';') {
			cus_vol[n]=vol;
			cus_con[n]=con;
			cus_len[n++]=j;
			vol=0;con=0;j=0;
		}
		else {
			if (s[i]>='a'&&s[i]<='z') {
				if (s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='y') vol++;
				else con++;
				j++;
			}
		}
		i++;
	}
	j=0;
	while (i<=len) {
		if (s[i]==','||i==len) {
			pro_len[m++]=j;
			j=0;
		}
		else {
			if (s[i]>='a'&&s[i]<='z') j++;
		}
		i++;
	}

	for (int i=0;i<n;i++) {
		for (int j=0;j<m;j++) {
			if (pro_len[j]&1) w[i][j]=cus_con[i]*2;
			else w[i][j]=cus_vol[i]*3;
			if (gcd(cus_len[i],pro_len[j])>1) w[i][j]*=3;
			else w[i][j]*=2;
		}
		for (int j=m;j<n;j++)
			w[i][j]=0;
	}
	m=max(m,n);
}

bool path(int u) {
	sx[u]=true;
	for (int v=0;v<m;v++)
		if (!sy[v]&&lx[u]+ly[v]==w[u][v]) {
			sy[v]=true;
			if (match[v]==-1||path(match[v])) {
				match[v]=u;
				return true;
			}
		}
	return false;
}

int KM() {
	for (int i=0;i<n;i++) {
		lx[i]=-inf;
		for (int j=0;j<m;j++)
			if (lx[i]<w[i][j])
				lx[i]=w[i][j];
	}
	for (int i=0;i<m;i++)
		ly[i]=0;

	memset(match,-1,sizeof(match));
	for (int u=0;u<n;u++) {
		for (;;) {
			memset(sx,0,sizeof(sx));
			memset(sy,0,sizeof(sy));
			if (path(u)) break;
			int dx=inf;
			for (int i=0;i<n;i++) if (sx[i])
				for (int j=0;j<m;j++) if(!sy[j])
					dx=min(lx[i]+ly[j]-w[i][j],dx);
			for (int i=0;i<n;i++)
				if (sx[i]) lx[i]-=dx;
			for (int i=0;i<m;i++)
				if (sy[i]) ly[i]+=dx;
		}
	}
	int sum=0;
	for (int i=0;i<n;i++)
		sum+=w[match[i]][i];
	printf("%.2lf\n",sum*0.25);
}

void solve() {
	KM();
}

int main(int argc, char *argv[]) {
	char *fn = argv[1];
	freopen(fn, "r", stdin);
	while (gets(s)) {
		if (strlen(s)==0) continue;
		init();
		solve();
	}
	return 0;
}