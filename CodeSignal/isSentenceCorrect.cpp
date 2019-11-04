bool isSentenceCorrect(std::string sentence) {
  std::regex regex("[?-Z][^.?!]*[.?!]");
  return std::regex_match(sentence, regex);
}
