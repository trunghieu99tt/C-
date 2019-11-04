bool isGeometricProgression(std::vector<int> sequence) {
    float x=float(sequence[1])/sequence[0];
    for (int i=2;i<sequence.size();i++)
        if(float(sequence[i])/sequence[i-1]!=x) return 0;
    return 1;
}
