#include <stdio.h>
#include <iostream>
#include <string.h>
#include <sstream>
#include <map>
using namespace std;

const int maxn=1000;

int n;
int a,b;
char t[maxn][20];
char tt[maxn][20];

void init() {
	char s[maxn];
	strcpy(s,"Mary had a little lamb its fleece was white as snow ");
	strcat(s,"And everywhere that Mary went the lamb was sure to go ");
	strcat(s,"It followed her to school one day which was against the rule ");
	strcat(s,"It made the children laugh and play to see a lamb at school ");
	strcat(s,"And so the teacher turned it out but still it lingered near ");
	strcat(s,"And waited patiently about till Mary did appear ");
	strcat(s,"Why does the lamb love Mary so the eager children cry Why Mary ");
	strcat(s,"loves the lamb you know the teacher did reply");
	
	istringstream sin(s);
	a=0;
	while (sin>>t[a]) a++;
}

void solve() {
	if (b+1<n) {
		cout<<endl;
		return;
	}
	int p=b+1-n;
	int tot=0;

	map<string,int> MSI;
	MSI.clear();
	int num[maxn];
	char word[maxn][20];
	int ans=0;
	memset(num,0,sizeof(num));
	for (int i=0;i<=a-n;i++) {
		bool flag=true;
		for (int j=p;j<b;j++)
			if (strcmp(t[i+j-p],tt[j])!=0) {
				flag=false;
				break;
			}
		if (flag) {
			tot++;
			if (MSI[t[i+n-1]]==0) {
				MSI[t[i+n-1]]=++ans;
				strcpy(word[ans],t[i+n-1]);
			}
			num[MSI[t[i+n-1]]]++;
		}
	}
	for (int i=1;i<ans;i++)
		for (int j=i+1;j<=ans;j++)
			if (num[j]>num[i]||(num[j]==num[i]&&strcmp(word[j],word[i])<0)) {
				int temp=num[i];num[i]=num[j];num[j]=temp;
				char ttemp[20];
				strcpy(ttemp,word[i]);
				strcpy(word[i],word[j]);
				strcpy(word[j],ttemp);
			}
	for (int i=1;i<ans;i++)
		printf("%s,%.3lf;",word[i],((double)num[i])/tot);
	printf("%s,%.3lf\n",word[ans],((double)num[ans])/tot);
}

int main(int argc, char *argv[]) {
	init();
	char *fn=argv[1];
	freopen(fn,"r",stdin);
	char str[maxn];
	while (gets(str)) {
		if (strlen(str)==0) continue;
		for (int i=0;str[i];i++)
			if (str[i]==',') str[i]=' ';
		istringstream sin(str);
		sin>>n;
		b=0;
		while (sin>>tt[b]) b++;
		solve();
	}
	return 0;
}