#!/bin/bash

# Colors
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'

TOTAL_TESTS=0
PASSED_TESTS=0

# Test function
run_test() {
    if [ "$2" = "no_arg" ]; then
        result=$($EXECUTABLE 2>&1)
    else
        result=$($EXECUTABLE "$2" 2>&1)
    fi

    if [ "$result" = "$3" ]; then
        echo -e "${GREEN}✓${NC} $1     $2"
        ((PASSED_TESTS++))
    else
        echo -e "${RED}✗${NC} $1       $2"
        echo "  Expected: $3"
        echo "  Got: $result"
    fi
    ((TOTAL_TESTS++))
}

# Build
echo "Building..."

if [ -f "./convert" ]; then
    EXECUTABLE="./convert"
    make > /dev/null 2>&1
elif [ -f "../convert" ]; then
    EXECUTABLE="../convert"
    make -C .. > /dev/null 2>&1
fi

echo "Running tests..."
echo "===================="

# Run tests
source "$(dirname "$0")/test_list.sh"

# Summary
echo "===================="
echo -e "Tests: $TOTAL_TESTS, Passed: ${GREEN}$PASSED_TESTS${NC}"

if [ $PASSED_TESTS -eq $TOTAL_TESTS ]; then
    echo -e "${GREEN}All tests passed!${NC}"
    exit 0
else
    echo -e "${RED}Some tests failed!${NC}"
    exit 1
fi
