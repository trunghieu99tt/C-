bool tennisSet(int score1, int score2) {
    return (max(score1,score2)==6 && min(score1,score2)<5 || min(score1,score2)>=5 && min(score1,score2)<7 && max(score1,score2)==7);
}
