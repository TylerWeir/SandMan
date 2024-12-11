#include "include/sandman/execution/manager.hpp"
#include <algorithm>
#include <iostream>
#include <optional>

using namespace std::chrono_literals;

std::chrono::duration<uint64_t, std::milli>
min_dur(std::chrono::duration<uint64_t, std::milli> a,
        std::chrono::duration<uint64_t, std::milli> b) {
  if (a < b)
    return a;
  else
    return b;
}

void ExecutionManager::register_task(
    std::function<void()> task,
    std::chrono::duration<uint32_t, std::milli> period) {

  Job thing = {.task = task,
               .period = period,
               .next_run = std::chrono::steady_clock::now() -
                           100ms}; // dumb way to trigger running now

  jobs.push_back(thing);
}

void ExecutionManager::run_for(
    std::chrono::duration<uint64_t, std::milli> dur) {
  std::chrono::duration<uint64_t, std::milli> time_left = dur;

  while (time_left > 0ms) {

    auto start_time = std::chrono::steady_clock::now();

    // Run everything due to run now
    for (auto &j : jobs) {
      if (j.next_run <= start_time) {
        std::cout << "running!\n";
        j.task();
        j.next_run = start_time + j.period;
      }
    }

    // Find next job to run
    Job next = jobs.front();
    for (const auto &j : jobs) {
      if (j.next_run < next.next_run) {
        next = j;
      }
    }

    // we'll sleep until the end of the alotted time or until the next task
    // TODO: this is repulsive
    std::chrono::duration<uint64_t, std::milli> time_to_sleep = min_dur(
        std::chrono::duration_cast<std::chrono::duration<uint64_t, std::milli>>(
            next.next_run - start_time),
        time_left);

    time_left -= time_to_sleep;
  }

  std::cout << "all done\n";
}
