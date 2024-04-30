#!/bin/bash

# Define environment variables
LIBS="pure/base/build/prod/libecs-pure-base.a,pure/cuda/build/prod/libecs-pure-cuda.a,pure/simd/build/prod/libecs-pure-simd.a,world/base/build/prod/libecs-world-base.a,world/plane/build/prod/libecs-world-plane.a,world/space/build/prod/libecs-world-space.a"

# Function to check coding style
check_coding_style() {
  echo "Checking coding style..."
  make fclean && cstyle
  while IFS= read -r line; do
    file=$(echo "$line" | awk -F ':' '{print $1}')
    line_number=$(echo "$line" | awk -F ':' '{print $2}')
    severity=$(echo "$line" | awk -F ':' '{print $3}')
    message=$(echo "$line" | awk -F ':' '{print $4}')
    echo "Error in $file at line $line_number: $severity $message"
  done < coding-style-reports.log

  line_count=$(wc -l < coding-style-reports.log)
  if [ "$line_count" -gt 6 ]; then
    echo "Too many style errors"
    return 1
  fi
  return 0
}

# Function to compile and run tests
compile_and_run_tests() {
  echo "Compiling and running tests..."

  make || exit 1

  IFS=',' read -ra LIBS_ARR <<< "$LIBS"
  for lib in "${LIBS_ARR[@]}"; do
    if [ ! -f "$lib" ]; then
      echo "Missing library: $lib"
      exit 1
    fi
  done

  echo "## Binary Testing"
  make binary_tests_run

  make fclean

  echo "## Unit Tests"
  make tests_run 2>&1

  echo "## Coverage"
  echo "### Lines"
  gcovr --txt --exclude tests/ --exclude src/main.c

  echo "### Branches"
  gcovr --txt --exclude tests/ --exclude src/main.c --branches
}

# Main script execution flow
if check_coding_style; then
  compile_and_run_tests
else
  echo "Failed coding style check."
  exit 1
fi
