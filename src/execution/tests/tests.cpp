#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"

#include "sandman/execution/manager.hpp"
#include <chrono>

using namespace std::chrono_literals;

TEST_CASE("Single Task Execution") {
  auto mgr = ExecutionManager();

  int value = 0;
  std::function<void()> incrementer = [&value]() { value++; };

  // A full period should call once
  mgr.register_task(incrementer, 10ms);
  mgr.run_for(10ms);
  CHECK(value == 1);

  // This should trigger the next most immediate scheduled task
  mgr.run_for(1ms);
  CHECK(value == 2);

  // No tasks should be triggered
  mgr.run_for(1ms);
  CHECK(value == 2);
}
