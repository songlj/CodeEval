#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

const int maxn=2000;

int n;
map <string,int> MSI;
bool g[maxn][maxn];
string name[maxn];
vector <string> ans;

void BronKerbosch(set<int> R,set<int> P,set<int> X) {
	if (P.size()==0&&X.size()==0) {
		vector <string> now;
		now.clear();
		for (set<int>::iterator it=R.begin();it!=R.end();it++)
			now.push_back(name[*it]);
		if (now.size()>=3) {
			sort(now.begin(),now.end());
			string s=now[0];
			for (int i=1;i<now.size();i++)
				s=s+", "+now[i];
			ans.push_back(s);
		}
		return;
	}
	for (int u=1;u<=n;u++) {
		if (P.find(u)==P.end()&&X.find(u)==X.end()) continue;
		for (int v=1;v<=n;v++)
			if (P.find(v)!=P.end()&&!g[u][v]) {
				set<int> RR=R;
				RR.insert(v);
				set<int> Nv;
				Nv.clear();
				for (int w=1;w<=n;w++)
					if (g[v][w]) Nv.insert(w);
				set<int> PP;
				PP.clear();
				for (int w=1;w<=n;w++)
					if (P.find(w)!=P.end()&&Nv.find(w)!=Nv.end())
						PP.insert(w);
				set<int> XX;
				XX.clear();
				for (int w=1;w<=n;w++)
					if (X.find(w)!=X.end()&&Nv.find(w)!=Nv.end())
						XX.insert(w);
				BronKerbosch(RR,PP,XX);
				P.erase(v);
				X.insert(v);
			}
	}
}

void solve() {
	for (int i=1;i<n;i++)
		for (int j=i+1;j<=n;j++)
			if (!g[i][j]||!g[j][i]) {
				g[i][j]=false;
				g[j][i]=false;
			}
	ans.clear();

	set<int> R,P,X;
	R.clear();
	P.clear();
	for (int i=1;i<=n;i++)
		P.insert(i);
	X.clear();
	BronKerbosch(R,P,X);
	sort(ans.begin(),ans.end());
	for (int i=0;i<ans.size();i++)
		cout<<ans[i]<<endl;
}

int main(int argc, char *argv[]) {
	char *fn=argv[1];
	freopen(fn,"r",stdin);
	char s[1000],s1[1000],s2[1000];
	MSI.clear();
	memset(g,0,sizeof(g));
	n=0;
	while (gets(s)) {
		sscanf(s,"%*[^\t]\t%s\t%s",s1,s2);
		if (MSI[s1]==0) {
			MSI[s1]=++n;
			name[n]=s1;
		}
		if (MSI[s2]==0) {
			MSI[s2]=++n;
			name[n]=s2;
		}
		g[MSI[s1]][MSI[s2]]=true;
	}
	solve();
	return 0;
}

