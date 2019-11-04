#include<iostream>
#include<algorithm>
#include<string.h>
#include<locale>
#include<vector>
using namespace std;
string MKR(string s)
{
	return s.substr(0,s.length()-1);
}
int main()
{
	while(1)
	{
		string s;
		getline(cin,s);
		if(s==".") return 0;
		int i=0;
		vector<int> markup;
		vector <string> sentences;
		vector<int> number;
		while(i<s.length())
		{
				string temp="";
				while(s[i]!=',' && i<s.length())
					{
						temp+=s[i];
						i++;
					}
				if(temp[0]=='-' || isdigit(temp[0]))
					{
						markup.push_back(1);
						number.push_back(stoi(temp,nullptr,10));
					}
				else 
				{
					markup.push_back(0);
					sentences.push_back(temp);
				}
				while((s[i]==' ' || s[i]==',') && i<s.length()) i++;
		}
		sort(number.begin(),number.end());
		sort(sentences.begin(),sentences.end());
		for (auto &k:sentences)
			if(k[k.length()-1]=='.') k=k.substr(0,k.length()-1);
		int runnum=0,runsen=0;
		for (i=0;i<markup.size()-1;i++)
		{
			if(markup[i]==0)
				cout<<sentences[runsen++]<<", ";
			else
				cout<<number[runnum++]<<", ";
		}
		if(markup[markup.size()-1]==0)
			cout<<sentences[sentences.size()-1]<<"."<<endl;
		else cout<<number[number.size()-1]<<"."<<endl;
	}
}