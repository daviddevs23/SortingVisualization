#include "../StepRecorder.hpp"
#include <string>
#include <vector>

class Visualizer {
public:
  Visualizer(std::size_t width, std::size_t height, std::string title,
             std::size_t fps);
  ~Visualizer();

  void visualize(std::vector<SortStep> steps, std::vector<int> data);

private:
  int width_{};
  int height_{};
  std::string title_{};
  std::size_t fps_{};
};
