bool chessBoardCellColor(std::string cell1, std::string cell2) {
    return (abs(cell1[0]-cell2[0])+abs(cell1[1]-cell2[1]) )%2 == 0;
}
