#pragma once

#include <utility>
#include <vector>

enum class StepType { Compare, Swap, Write, MarkSorted };

struct SortStep {
  StepType type;
  std::size_t a;
  std::size_t b;
  int value{};
};

class StepRecorder {
public:
  void compare(std::size_t a, std::size_t b) {
    steps.push_back({StepType::Compare, a, b});
  }

  void swap(std::vector<int> &values, std::size_t a, std::size_t b) {
    steps.push_back({StepType::Swap, a, b});
    std::swap(values[a], values[b]);
  }

  void write(std::vector<int> &values, std::size_t index, int value) {
    steps.push_back({StepType::Write, index, 0, value});
    values[index] = value;
  }

  void markComplete() { steps.push_back({StepType::MarkSorted, 0, 0}); }

  const std::vector<SortStep> &getSteps() const { return steps; }

private:
  std::vector<SortStep> steps;
};
