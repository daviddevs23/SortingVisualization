#include "Graphics.hpp"
#include "../StepRecorder.hpp"
#include <iostream>
#include <raylib.h>
#include <vector>

Visualizer::Visualizer(std::size_t width, std::size_t height, std::string title,
                       std::size_t fps)
    : width_(width), height_(height), title_(title), fps_(fps) {
  InitWindow(width_, height_, title_.c_str());
}

Visualizer::~Visualizer() { CloseWindow(); }

void Visualizer::visualize(std::vector<SortStep> steps, std::vector<int> data) {
  // SetTargetFPS(fps_);

  int barWidth = width_ / data.size();
  int barHeightInc = height_ / 100;

  std::vector<int> compIndexes{};
  std::vector<int> swapIndexes{};
  std::size_t writeIndex{data.size()};

  for (auto step : steps) {
    switch (step.type) {
    case StepType::Compare:
      compIndexes.push_back(step.a);
      compIndexes.push_back(step.b);
      break;

    case StepType::Swap:
      std::swap(data[step.a], data[step.b]);

      swapIndexes.push_back(step.a);
      swapIndexes.push_back(step.b);
      break;

    case StepType::Write:
      data[step.a] = step.value;
      writeIndex = step.a;
      break;

    case StepType::MarkSorted:
      std::cout << "Sorted!" << std::endl;
      break;

    default:
      std::cout << "Instruction Not Found" << std::endl;
    }

    BeginDrawing();
    ClearBackground(BLACK);

    for (std::size_t i{0}; i < data.size(); i++) {
      int width = barWidth;
      int height = barHeightInc * data[i];
      int posX = barWidth * i;
      int posY = height_ - height;

      Color color = WHITE;

      if (std::find(compIndexes.begin(), compIndexes.end(), i) !=
          compIndexes.end()) {
        color = GREEN;
      }

      if (std::find(swapIndexes.begin(), swapIndexes.end(), i) !=
          swapIndexes.end()) {
        color = ORANGE;
      }

      if (writeIndex == i) {
        color = PINK;
      }

      DrawRectangle(posX, posY, width, height, color);
    }

    compIndexes = {};
    swapIndexes = {};
    writeIndex = -1;

    EndDrawing();
  }
}
