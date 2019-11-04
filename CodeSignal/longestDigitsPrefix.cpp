std::string longestDigitsPrefix(std::string inputString) {
	int i=0;
    while(isdigit(inputString[i])) i++;
    return inputString.substr(0,i);
}
