#include "../StepRecorder.hpp"
#include "SortDefinitions.hpp"
#include <vector>

std::vector<SortStep> selectionSort(std::vector<int> values) {
  StepRecorder recorder{};

  std::size_t n = values.size();

  for (std::size_t j{0}; j < n - 1; j++) {
    std::size_t minIndex = j;

    for (std::size_t i{j + 1}; i < n; i++) {
      recorder.compare(i, j);
      if (values[i] < values[minIndex]) {
        minIndex = i;
      }
    }

    if (minIndex != j) {
      recorder.swap(values, j, minIndex);
    }
  }

  recorder.markComplete();
  return recorder.getSteps();
}
