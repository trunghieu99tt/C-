std::vector<std::string> countAPI(std::vector<std::string> calls) {
    for(auto &i:calls)
        i = i.substr(1);
    vector<vector<string>> split;
    for(auto i:calls)
    {
        stringstream ss(i);
        vector<string> temp;
        string token;
        while(getline(ss,token,'/'))
            temp.push_back(token);
        split.push_back(temp);
    }
    vector<string> project;
    map<string,vector<vector<string>>> allProject;
    map<string,int> countProject;
    for(auto i:split)
    {
        if(find(project.begin(),project.end(),i[0]) == project.end())
            project.push_back(i[0]);
        countProject[i[0]]++;
        allProject[i[0]].push_back(i);
    }
    vector<string> ans;
    for(auto i:project)
    {
        ans.push_back("--" + i + " (" + to_string(countProject[i]) + ')');
        vector<string> subProject;
        map<string,int> countSubProject;
        map<string,vector<vector<string>>> allSubProject;
        for(auto j:allProject[i])
        {
            if(find(subProject.begin(),subProject.end(),j[1]) == subProject.end())
                subProject.push_back(j[1]);
            countSubProject[j[1]]++;
            allSubProject[j[1]].push_back({j[1],j[2]});
        }
        for(auto j:subProject)
        {
            ans.push_back("----" + j + " (" + to_string(countSubProject[j]) + ')');
            vector<string> method;
            map<string,int> countMethod;
            for(auto k:allSubProject[j])
            {
                if(find(method.begin(),method.end(),k[1]) == method.end())
                    method.push_back(k[1]);
                countMethod[k[1]]++;
            }
            for(auto k:method)
            {
                ans.push_back("------" + k + " (" + to_string(countMethod[k]) + ')');
            }
        }
        
    }
    return ans;
}
