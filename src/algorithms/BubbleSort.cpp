#include "../StepRecorder.hpp"
#include "SortDefinitions.hpp"
#include <vector>

std::vector<SortStep> bubbleSort(std::vector<int> values) {
  StepRecorder recorder{};

  for (std::size_t i{0}; i < values.size() - 1; i++) {
    for (std::size_t j{0}; j < values.size() - i - 1; j++) {
      recorder.compare(j, j + 1);
      if (values[j] > values[j + 1]) {
        recorder.swap(values, j, j + 1);
      }
    }
  }
  recorder.markComplete();

  return recorder.getSteps();
}
