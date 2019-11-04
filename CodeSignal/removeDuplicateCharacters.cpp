std::string removeDuplicateCharacters(std::string str) {
  vector<int> a(122, 0);
  for (auto i : str)
    a[i]++;
  string res = "";
  for (auto i : str)
    if (a[i]==1)
      res+=i;
  return res;
}
