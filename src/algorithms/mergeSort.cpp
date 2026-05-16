#include "../StepRecorder.hpp"
#include "SortDefinitions.hpp"
#include <vector>

static void merge(std::vector<int> &values, StepRecorder &recorder, int left,
                  int mid, int right) {
  std::vector<int> temp{};

  int i = left;
  int j = mid + 1;

  while (i <= mid && j <= right) {
    recorder.compare(i, j);

    if (values[i] <= values[j]) {
      temp.push_back(values[i]);
      ++i;
    } else {
      temp.push_back(values[j]);
      ++j;
    }
  }

  while (i <= mid) {
    temp.push_back(values[i]);
    ++i;
  }

  while (j <= right) {
    temp.push_back(values[j]);
    ++j;
  }

  for (std::size_t k = 0; k < temp.size(); k++) {
    values[left + k] = temp[k];

    recorder.write(values, left + k, temp[k]);
  }
}

static void mergeSortRecursive(std::vector<int> &values, StepRecorder &recorder,
                               int left, int right) {
  if (left >= right) {
    return;
  }

  int mid = left + (right - left) / 2;

  mergeSortRecursive(values, recorder, left, mid);
  mergeSortRecursive(values, recorder, mid + 1, right);

  merge(values, recorder, left, mid, right);
}

std::vector<SortStep> mergeSort(std::vector<int> values) {
  StepRecorder recorder{};

  mergeSortRecursive(values, recorder, 0, static_cast<int>(values.size()) - 1);

  recorder.markComplete();

  return recorder.getSteps();
}
