int commonCharacterCount(std::string s1, std::string s2) {
  std::map<char, int> map1;
  std::map<char, int> map2;
  int answer = 0;
  for (int i = 0; i < s1.size(); i++) {
    char ch = s1[i];
    map1[ch] = (map1.count(ch) ? map1[ch] + 1 : 1);
  }
  for (int i = 0; i < s2.size(); i++) {
    char ch = s2[i];
    map2[ch] = (map2.count(ch) ? map2[ch] + 1 : 1);
  }
  for (char ch = 'a'; ch <= 'z'; ch++) {
    if (map1[ch]>0 && map2[ch]>0) answer+=(map1[ch]>map2[ch])?(map2[ch]):map1[ch];
  }
  return answer;
}
