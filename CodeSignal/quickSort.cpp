void quickSortWithReference(std::vector<int>& a, int l, int r) {
  if (l >= r) {
    return;
  }

  int x = a[l];
  int i = l;
  int j = r;

  while (i <= j) {
    while (a[i] < x) {
      i++;
    }
    while (a[j] > x) {
      j--;
    }
    if (i <= j) {
      swap(a[i],a[j]);
      i++;
      j--;
    }
  }

  quickSortWithReference(a, l, j);
  quickSortWithReference(a, i, r);
}

std::vector<int> quickSort(std::vector<int> a, int l, int r) {
  quickSortWithReference(a, l, r);
  return a;
}