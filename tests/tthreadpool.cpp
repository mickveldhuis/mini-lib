#include <catch2/catch_test_macros.hpp>

#include <mini-lib/threadpool.hpp>

TEST_CASE("Test ThreadPool", "[threadpool]") {
  using namespace std::chrono_literals;

  const int n_tasks = 16;

  std::vector<int> squares(n_tasks);

  ThreadPool pool(4);

  for (int i = 0; i < n_tasks; ++i) {
    pool.PushTask([i, &squares]() {
      squares[i] = i * i;
      std::this_thread::sleep_for(100ms);
    });
  }

  pool.WaitUntilFinished();

  for (int i = 0; i < n_tasks; ++i) {
    CHECK(squares[i] == i * i);
  }
}
