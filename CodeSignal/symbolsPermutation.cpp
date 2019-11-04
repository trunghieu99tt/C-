bool symbolsPermutation(std::string word1, std::string word2) 
{
    sort(word1.begin(), word1.end());
    sort(word2.begin(), word2.end());
    return (word1 == word2);
}
