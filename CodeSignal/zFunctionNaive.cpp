std::vector<int> zFunctionNaive(std::string s) {
    vector<int> answer(s.size(), 0);
    for (int i = 0; i < s.size(); ++i) {
        for (int k = 0; k < s.size() - i; ++k) {
            if (s[k] == s[i + k]) {
                ++answer[i];
            } else {
                break;
            }
        }
    }
    return answer;
}
