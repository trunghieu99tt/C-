std::string concatenationProcess(std::vector<std::string> init) {

  while (init.size() > 1) {
    int minInd1 = 0,
        minInd2 = init.size() - 1;

    for (int i = 1; i < init.size(); i++) {
      if (init[i].size() < init[minInd1].size()) {
        minInd1 = i;
      }
    }

    if (minInd2 == minInd1) {
      minInd2--;
    }

    for (int i = init.size() - 2; i >= 0; i--) {
      if (init[i].size() < init[minInd2].size()
       && i != minInd1) {
        minInd2 = i;
      }
    }

    init.push_back(init[minInd1] + init[minInd1]);
    init.erase(init.begin() + std::max(minInd1, minInd2));
    init.erase(init.begin() + std::min(minInd1, minInd2));
  }

  return init[0];
}
