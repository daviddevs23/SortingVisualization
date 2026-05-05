#include "src/StepRecorder.hpp"
#include "src/algorithms/SortDefinitions.hpp"
#include "src/graphics/Graphics.hpp"
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::size_t numEntries{500};
  std::vector<int> data(numEntries);

  std::generate(data.begin(), data.end(), []() { return rand() % 100; });

  std::vector<SortStep> steps = insertionSort(data);

  Visualizer visualizer(2000, 1000, "Visualizer", -1);
  visualizer.visualize(steps, data);

  return EXIT_SUCCESS;
}
