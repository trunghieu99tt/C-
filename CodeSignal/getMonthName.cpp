std::string getMonthName(int mo) {
    vector<string> ans{"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
    return mo >= 1 && mo <= 12 ? ans[mo-1] : "invalid month";
}
