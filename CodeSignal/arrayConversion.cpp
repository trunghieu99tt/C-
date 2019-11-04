int arrayConversion(std::vector<int> arr) {
    int f = 1;
    while(arr.size()!=1)
    {
        vector<int> temp;
            for(int i = 0;i<arr.size()-1;i+=2)
            {
                if(f)
                temp.push_back(arr[i] + arr[i+1]);
                else temp.push_back(arr[i]*arr[i+1]);
            }
        arr = temp;
        f = !f;
    }
    return arr[0];
}
