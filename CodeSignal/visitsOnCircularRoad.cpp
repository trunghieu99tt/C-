int visitsOnCircularRoad(int n, std::vector<int> v) {
    int wina = 1,ans=0;
    for(int i=0; i<v.size(); i++){
        ans += min(abs(v[i]-wina),n-abs(v[i]-wina));
        wina = v[i];
    }
    return ans;
}
