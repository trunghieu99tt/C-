std::string whoseMove(std::string lastPlayer, bool win) {
    if(lastPlayer=="black" && win==0 || lastPlayer=="white" && win==1) return "white";
    if(lastPlayer=="black" && win==1 || lastPlayer=="white" && win==0) return "black";
}
