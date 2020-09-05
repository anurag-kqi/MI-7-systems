#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<pair<int,int,int>>d;
    d.push_back(make_pair(1,2,3));
    d.push_back(make_pair(10,20,30));
    d.push_back(make_pair(30,60,90));
    d.push_back(make_pair(10,20,10));

int n= 4;

stable_sort(d.begin(),d.middle(),d.end());
for(int i=0; i<n; i++)
cout<<"["<<d[i].first <<"," <<d[i].second <<"," <<d[i].third <<"]";

return 0;
}



