/*----------------marathonTaskScore-----------------*/
int marathonTaskScore(int marathonLength, int maxScore, int submissions, int successfulSubmissionTime) {
    if(successfulSubmissionTime==-1) return 0;
    int unsuccessful=(submissions-1)*10;
    double pen=successfulSubmissionTime*(double(maxScore)/2)*(1.0/marathonLength);
    int p=int(pen);
    int score=maxScore-unsuccessful-p;
    if(score< maxScore/2) return maxScore/2;
    return score;
}
