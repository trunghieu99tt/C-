std::string decipher(std::string cipher) {

  std::string result = "";
  for (int i = 0; i < cipher.size(); ) {
    int len;
    if (cipher[i] == '1') {
      len = 3;
    } else {
      len = 2;
    }
    int code = std::stoi(cipher.substr(i, len));
    result += (char) code;
    i += len;
  }

  return result;
}
