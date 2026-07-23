#include <bits/stdc++.h>

using namespace std;

#define ff first
#define ss second
#define _ ios_base::sync_with_stdio();cin.tie(0);
typedef long long ll;
typedef unsigned long long ull;

void tiraespaco(string &s) {
	while(s.size() and (s.back()=='\n' or s.back()== ' ' or s.back()=='\t')) s.pop_back();
	if(s[0]!=' ' and s[0]!='\t') return;
	for(int i=0;;i++) if(s[i]!=' ' and s[i]!='\t') {
		s = s.substr(i);
		return;
	}
}

void printar(string &s) {
	s.pop_back();
	for(int i=0;;i++) if(s[i]=='(') {
		s = s.substr(i+1);
		break;
	}
	tiraespaco(s);
	cout << "APRESENTE " << s << '\n';
}

void ler(string &s) {
	s.pop_back();
	cout << "LEIA ";
	for(int i=0;s[i]!=' ';i++) if(s[i]!=' ' and s[i]!='\t') cout << s[i];
	cout << '\n';
}

int main() { _
	string s;

	while(getline(cin,s)) {
		if(s.empty()) break;
		tiraespaco(s);
		if(s[0]=='p' and s[s.size()-2]!='(') printar(s);
		else if(s.back()==')') ler(s);
		else if(s[0]=='w') {
			cout << "ENQUANTO ";
			int i=6;
			for(;s[i]!=':';i++) cout << s[i];
			cout << ' ';
			getline(cin,s);
			tiraespaco(s);
			if(s[0]=='p') printar(s);
			else ler(s);
		} else {
			cout << "SE ";
			int i=3;
			for(;s[i]!=':' or (s[i]==' ' and s[i+1]==':');i++) cout << s[i];
			cout << " ENTAO ";
			getline(cin,s);
			tiraespaco(s);
			if(s[0]=='p') printar(s);
			else ler(s);
		}
		break;
	}

	return 0;
}
