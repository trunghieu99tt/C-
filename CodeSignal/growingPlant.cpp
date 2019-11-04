int growingPlant(int upSpeed, int downSpeed, int desiredHeight) {
    int height = 0 ;
    int k = 0 ;
    while(height < desiredHeight) {
        k++ ;
        height += upSpeed ;
        if(height >= desiredHeight) {
            return k ;
        }
        height -= downSpeed ;
    }
}
