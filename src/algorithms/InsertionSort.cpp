#include "SortDefinitions.hpp"

std::vector<SortStep> insertionSort(std::vector<int> values) {
  StepRecorder recorder{};

  for (std::size_t i{1}; i < values.size(); i++) {
    int j = i;
    while (j > 0) {
      recorder.compare(j - 1, j);

      if (values[j - 1] <= values[j]) {
        break;
      }

      recorder.swap(values, j - 1, j);
      --j;
    }
  }

  recorder.markComplete();

  return recorder.getSteps();
}
