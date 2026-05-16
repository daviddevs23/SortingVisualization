#pragma once

#include <vector>

#include "../StepRecorder.hpp"

std::vector<SortStep> bubbleSort(std::vector<int> values);
std::vector<SortStep> insertionSort(std::vector<int> values);
std::vector<SortStep> selectionSort(std::vector<int> values);
std::vector<SortStep> mergeSort(std::vector<int> values);
