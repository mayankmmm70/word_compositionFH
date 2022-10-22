
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

unordered_map<string, int> mp;
int fun_dfs(string s)
{
    if (!s.size())
        return 0;

    int res = 0;
    for (int i = 0; i < s.size(); i++)
    {
        string x = s.substr(0, i + 1); 
        // take string of ith position
        if (mp.find(x) != mp.end())                     
            res = max(res, 1 + fun_dfs(s.substr(i + 1))); //check for max of res , 1+fun_dfs() 
    }

    
    return res == 0 ? INT_MIN : res; //will return INT_MIN if res is 0 otherwise res;
}
vector<string> findAllConcatenatedWordsInADict(vector<string> &words)
{

    for (int i=0; i<words.size(); i++) // seacrhing in map in constant time
        mp[words[i]]++;

    vector<string> res;
    for (int i=0; i<words.size(); i++)
    {   string s=words[i];
        if (fun_dfs(s) >= 2)      
            res.push_back(s); 
    }
    return res;
}


int main()
{
    auto start = high_resolution_clock::now();
    ifstream file("inp.txt");
    string word;
    
    vector<string> res;
    while (file >>word) 
    {
        
        res.push_back(word);
    }
    
    file.close();
    auto stop = high_resolution_clock::now();

    // vector<string> res;
    // taken a vector of string

    res = findAllConcatenatedWordsInADict(res);

    sort(res.begin(), res.end(),greater<string>());

    // first largest word
    cout << res[0]<<endl;
    // this is the secong largest word that is founded
    if (res.size()>1)
    cout<<res[1]<<endl;

    auto duration = duration_cast<microseconds>(stop - start);
    
    cout << duration.count() << endl;
    // for (auto x:res)
    // {
    //     cout<<x<<endl;
    // }

    return 0;
}
