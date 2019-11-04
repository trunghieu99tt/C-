bool areEquallyStrong(int yourLeft, int yourRight, int friendsLeft, int friendsRight) {
    int s1=max(yourLeft,yourRight),s2=max(friendsLeft,friendsRight),w1=min(yourLeft,yourRight),
    w2=min(friendsLeft,friendsRight);
    return (s1==s2 && w1==w2);
}
