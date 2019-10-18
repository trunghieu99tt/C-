#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
 
void Try(vector <int> a, vector < vector<int> > &res){
    if(a.size() == 1) return;
    vector <int> temp;
    for(int i = 0;i<a.size();i++){
        temp.push_back(a[i]);
    }
    res.push_back(temp);
    vector <int> b, c;
    for(int i = 0;i<a.size();i++){
        if(i % 2 == 0)  b.push_back(a[i]);
        else c.push_back(a[i]);
    }
    Try(b, res);
    Try(c, res);
}
 
 
int main(){
    int N;
    cin>>N;
    int m = log(N)/log(2);
    cout<<"M = "<<m<<endl;
    vector <int> a;
    vector <vector <int> > res;
    for(int i = 0; i<N; i++){
        a.push_back(i);
    }
    Try(a, res);
    for(int i = m;i > 0;i--){
        cout<<"{";
        for(int j = 0;j < res.size(); j++){
            if(res[j].size() == pow(2,i)){
                for(int k = 0; k < res[j].size(); k++){
                    if(k == 0) cout<<" ("<<res[j][k]<<", ";
                    else if(k == res[j].size() - 1){
                        if(res[j][k] != N-1) cout<<res[j][k]<<"),"; 
                        else cout<<res[j][k]<<") ";
                    }
                    else cout<<res[j][k]<<", ";
                }
            }
        }
        cout<<"}";
        cout<<endl;
    }
    return 0;
}