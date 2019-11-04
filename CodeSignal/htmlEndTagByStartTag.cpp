std::string htmlEndTagByStartTag(std::string startTag) {
    int i = startTag.find(' ');
    if (i == -1) {
        return "</" + startTag.substr(1, startTag.size() - 2) + ">";
    } 
    return "</" + startTag.substr(1, i - 1) + ">";
}
