int makeArrayConsecutive2(std::vector<int> statues) {
    sort(statues.begin(),statues.end());
    return statues[statues.size()-1]-statues[0]-statues.size()+1;
}
