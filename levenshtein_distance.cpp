#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <set>
#include <vector>
using namespace std;

const int maxn=30005;

int n;
string s[maxn];
set<string> st;
vector<string> ans;

bool check(string s1,string s2) {
    int d[25][25];
    int l1=s1.length(),l2=s2.length();
	for (int i=0;i<=l1;i++) d[i][0]=i;
	for (int j=0;j<=l2;j++) d[0][j]=j;
	for (int i=1;i<=l1;i++)
		for (int j=1;j<=l2;j++)
			if (s1[i-1]==s2[j-1]) d[i][j]=d[i-1][j-1];
			else {
				d[i][j]=min(d[i-1][j],d[i][j-1]);
				d[i][j]=min(d[i][j],d[i-1][j-1]);
				d[i][j]++;
			}
	return d[l1][l2]<=1;
}

void solve() {
	string t="hello";
	st.clear();
	st.insert(t);
	ans.clear();
	ans.push_back(t);
	for (int i=0;i<ans.size();i++) {
		for (int j=0;j<n;j++)
			if (st.find(s[j])==st.end())
				if (check(ans[i],s[j])) {
					st.insert(s[j]);
					ans.push_back(s[j]);
				}
	}
	cout<<ans.size()-1<<endl;
}


int main(int argc, char *argv[]) {
	char *fn=argv[1];
	freopen(fn,"r",stdin);
	n=0;
	while (cin>>s[n]) n++;
	solve();
	//cout<<4844<<endl;
	return 0;
}