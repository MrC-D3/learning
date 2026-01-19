# AI Coding Agent Instructions

## Project Overview
This is a C++ design patterns and algorithms learning repository with two main components:
- **patterns/**: Implementation of Gang of Four (GoF) and Game Programming patterns
- **algorithms/**: Data structures, algorithms, and LeetCode challenge solutions

## Architecture & Organization

### Pattern Implementation Structure
Each pattern follows a consistent library-based structure:
```
<pattern_name>/
  ├── client_main.cpp          # Demonstrates pattern usage
  ├── CMakeLists.txt            # Executable that links to library
  └── library/
      ├── CMakeLists.txt        # Library definition
      ├── include/<pattern>/    # Public headers (namespaced)
      ├── source/               # Implementation files
      └── unit_test/            # GTest-based tests
          ├── CMakeLists.txt
          └── *_ut.cpp
```

**Key conventions:**
- Headers use include guards: `#ifndef PATTERN_NAME_HPP`
- Each pattern has its own namespace (e.g., `namespace Command`, `namespace DoubleBufferNS`)
- Libraries install to `lib/` with headers to `include/<pattern>/`
- Pattern names match directory names (e.g., `01_command` → `#include "01_command/receiver.hpp"`)

### Algorithm Challenges Organization
Located in `algorithms/challenges/`:
- **Naming**: `<problem_number>_<category>.cpp` (e.g., `1_array.cpp`, `206_llist.cpp`)
- **`_OUT` suffix**: Incomplete/outstanding problems (visible in filenames like `278_bsearch_OUT.cpp`)
- **challenges.json**: Master list of LeetCode problem numbers by difficulty
- **template.cpp**: Boilerplate with common includes and data structure definitions (ListNode, TreeNode)
- **random_challenge.cpp**: Tool to select random problem from challenges.json

Each solution includes:
- Time complexity comment at the top
- Problem description and constraints
- Multiple solution versions when applicable (e.g., `Solution` and `Solution_v1`)

## Build System (CMake)

### Building Patterns
```bash
cd patterns/<category>/<pattern>/library/
mkdir -p build && cd build
cmake ..
cmake --build .
```

### Running Tests
Unit tests use GTest/GMock. After building:
```bash
# From library/build/
ctest --test-dir . --output-on-failure

# CTest options (see patterns/GoF/behavioral/01_command/README.md):
# -L "^label$"               - Filter by label
# --no-compress-output       - Full output
# --output-junit file.xml    - JUnit XML export
# --timeout 60               - Per-test timeout
```

### Building Algorithms
Simple single-file compilation (no CMake):
```bash
cd algorithms/challenges/
g++ -std=c++20 <file>.cpp -o a.out
./a.out
```

## Development Practices

### CMake Patterns
- Libraries: Use `add_library()` with `PUBLIC` include directories via `$<BUILD_INTERFACE>` and `$<INSTALL_INTERFACE>`
- Executables: Link to pattern libraries with `target_link_libraries(PRIVATE <lib>)`
- Tests: Link to `GTest::gtest_main` and `GTest::gmock`, named `<lib>_ut`
- Min version: `cmake_minimum_required(VERSION 3.15)`

### Testing Conventions
From unit test files:
- Test fixtures: Inherit from `::testing::Test`, use `protected:` members
- Test naming: `TEST_F(SuiteName, test_name)`
- Assertions: Use `ASSERT_EQ`, `EXPECT_CALL()`, etc.
- Mock setup: `::testing::AtLeast` for call expectations

### Code Style
- Standard data structures defined in template.cpp: `ListNode`, `TreeNode` with standard constructors
- Use `using namespace std;` in challenge solutions
- Include common headers: `<vector>`, `<unordered_map>`, `<queue>`, `<algorithm>`, etc.
- Comments explain approach optimizations (see `1_array.cpp` for hash map optimization example)

## Performance Analysis
For patterns with performance concerns (see `patterns/game_programming/09_data_locality/README.md`):
```bash
# Build with debug and optimization flags
valgrind --tool=cachegrind <program>
valgrind --tool=cachegrind --cache-sim=yes <program>  # For L1 cache analysis
cg_annotate cachegrind.out.<pid>

# Metrics: Ir (instructions read), D1mr (L1 cache miss read), D1mw (L1 cache miss write)
```

## CI/CD (GitHub Actions)
Workflow in `.github/workflows/basic_workflow.yml`:
- **Dynamic matrix**: Uses `find` + `jq` to discover all `library/` directories and build in parallel
- **Manual trigger**: `workflow_dispatch` event
- **GTest installation**: Builds from source in CI (see workflow steps)
- **Runs on**: `ubuntu-latest` (avoid version-specific images)

## Docker Development Environment
From README.md - recommended setup:
```dockerfile
# Base: ubuntu:20.04 or 22.04
apt-get install: g++-10, gcc-10, python3, git, vim, gdb, cmake, wget
pip install: cmake==3.25.2, conan==1.59.0
From source: GTest, Boost, Valgrind
```

## Quick Reference
- **New pattern**: Copy structure from existing pattern, update namespaces and include guards
- **New challenge**: Use `template.cpp` as starting point, follow `<num>_<category>.cpp` naming
- **Build everything**: Navigate to each `library/build/` and run `cmake .. && cmake --build .`
- **Random practice**: Compile and run `random_challenge.cpp` to get random problem from challenges.json
