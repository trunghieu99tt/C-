std::vector<double> fareEstimator(int ride_time, int ride_distance, std::vector<double> cost_per_minute, std::vector<double> cost_per_mile) {
    vector<double> res;
    for (int i=0;i<cost_per_minute.size();i++)
        res.push_back(cost_per_minute[i]*ride_time + cost_per_mile[i]*ride_distance);
    return res;
}
