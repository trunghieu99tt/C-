std::vector<std::vector<int>> imageTruncation(std::vector<std::vector<int>> image, int threshold) {
    for (auto &i:image)
        for (auto &j:i)
            if(j>threshold) j=threshold;
    return image;
}
