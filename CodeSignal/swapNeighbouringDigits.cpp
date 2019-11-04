int swapNeighbouringDigits(int n) {
    string s=to_string(n);
    for (int i=0;i<s.length()-1;i+=2)
        swap(s[i],s[i+1]);
    return stoi(s,nullptr,10);
}
