int howManySundays(int n, std::string startDay) {
    string Days[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    int i;
    for(i = 0; i < 7 && Days[i] != startDay; i++);
    int cont = 0;
    while(n--){
        i = (i + 1) % 7;
        if(Days[i] == "Sunday")
            cont++;
    }
    return cont;
}
