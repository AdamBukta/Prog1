#include "std_lib_facilities.h"

template <typename m1, typename m2>
void print(const map<m1,m2>& map)
{
    for(const auto& p : map)
        cout<<p.first<<" "<<p.second <<'\n';
}

void read(map<string,int>& map)
{
    string text;
    int number;
    cin>>text>>number;
    map.insert(pair<string,int>(text,number));
}

int main()
{
    map<string, int> msi;

    msi["i"]=10;
    msi["have"]=20;
    msi["to"]=30;
    msi["define"]=40;
    msi["ten"]=50;
    msi["pairs"]=60;
    msi["of"]=70;
    msi["strings"]=80;
    msi["and"]=90;
    msi["intgers"]=100;

    print(msi);

    msi.erase(msi.begin(),msi.end());
    cout<<"Ereasing done. \n";
    print(msi);

    cout<<"Please enter 5 pairs: \n";
    while(msi.size()!=5)
    {
        read(msi);
    }

    print(msi);

    int sum = accumulate(msi.begin(),msi.end(),0, [](auto prev_sum, auto &msi_entry){return prev_sum+msi_entry.second;});
    cout<<"Map intigers' sum: "<<sum<<"\n";

    map<int,string> mis;

    for(auto& mapentry: msi)
        mis[mapentry.second] = mapentry.first;
    
    print(mis);

    return 0;
}