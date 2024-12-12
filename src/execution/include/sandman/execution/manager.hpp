#include <chrono>
#include <functional>
#include <ratio>
#include <unordered_map>
#include <vector>

struct Job {
  std::function<void()> task;
  std::chrono::duration<uint32_t, std::milli> period;
  std::chrono::steady_clock::time_point next_run;
};

class ExecutionManager {

public:
  void register_task(std::function<void()> task,
                     std::chrono::duration<uint32_t, std::milli> period);

  void run_for(std::chrono::duration<uint64_t, std::milli> dur);

private:
  std::vector<Job> jobs;
};
