std::vector<int> tasksTypes(std::vector<int> deadlines, int day) {
    int to=0,up=0,la=0;
    for (auto i: deadlines)
    {
        if(i<=day) to++;
        else if(i>=day+1 && i<=day+7) up++;
        else la++;
    }
    return {to,up,la};
}
