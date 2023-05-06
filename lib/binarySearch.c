int binarySearch(int target, int booksLen, int *sparIndex) {
  int left = 0;
  int right = booksLen;
  int middle;

  while (left <= right) {
    middle = (left + right)/2;
    if (sparIndex[middle] == target) {
      return middle;  
    } else if (sparIndex[middle] < target) {
      left = middle + 1;
    } else {
      right = middle - 1;
    }
  }
  return -1;
}