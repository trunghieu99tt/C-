bool checkPalindrome(std::string s) {
   auto Check=s;
   reverse(Check.begin(),Check.end());
   return (Check==s);
}
