
# Test cases from the subject

# Test 1: Integer 0
run_test "Integer 0" "0" "\
char: Non displayable
int: 0
float: 0.0f
double: 0.0"

# Test 2: NaN
run_test "NaN" "nan" "\
char: impossible
int: impossible
float: nanf
double: nan"

# Test 3: Float 42.0f
run_test "Float 42.0f" "42.0f" "\
char: '*'
int: 42
float: 42.0f
double: 42.0"

# Additional test cases

# Test 4: Character literal
run_test "Character a" "a" "\
char: 'a'
int: 97
float: 97.0f
double: 97.0"

# Test 5: Negative integer
run_test "Negative integer -42" "-42" "\
char: impossible
int: -42
float: -42.0f
double: -42.0"

# Test 6: Positive integer that maps to printable char
run_test "Integer 65 (maps to 'A')" "65" "\
char: 'A'
int: 65
float: 65.0f
double: 65.0"

# Test 7: Float with decimal
run_test "Float -4.2f" "-4.2f" "\
char: impossible
int: -4
float: -4.2f
double: -4.2"

# Test 8: Double
run_test "Double 4.2" "4.2" "\
char: impossible
int: 4
float: 4.2f
double: 4.2"

# Test 9: Positive infinity float
run_test "Positive infinity float" "+inff" "\
char: impossible
int: impossible
float: +inff
double: +inf"

# Test 10: Negative infinity double
run_test "Negative infinity double" "-inf" "\
char: impossible
int: impossible
float: -inff
double: -inf"

# Test 11: Invalid input
run_test "Invalid input" "invalid" "\
char: impossible
int: impossible
float: impossible
double: impossible"

# Test 12: No arguments
run_test "No arguments" "no_arg" "Usage: ./convert <literal>"

# Test 13: Large integer (overflow test)
run_test "Large integer" "2147483648" "\
char: impossible
int: impossible
float: 2147483648.0f
double: 2147483648.0"

# Additional boundary and error test cases

# Test 14: Character boundary - Space character (ASCII 32)
run_test "Space character" " " "\
char: ' '
int: 32
float: 32.0f
double: 32.0"

# Test 15: Character boundary - DEL character (ASCII 127)
run_test "DEL character (127)" "127" "\
char: Non displayable
int: 127
float: 127.0f
double: 127.0"

# Test 16: Character boundary - Printable boundary (ASCII 126)
run_test "Tilde character (126)" "126" "\
char: '~'
int: 126
float: 126.0f
double: 126.0"

# Test 17: Character boundary - Non-printable control character
run_test "Control character (31)" "31" "\
char: Non displayable
int: 31
float: 31.0f
double: 31.0"

# Test 18: Integer boundary - Maximum int
run_test "Maximum int" "2147483647" "\
char: impossible
int: 2147483647
float: 2147483648.0f
double: 2147483647.0"

# Test 19: Integer boundary - Minimum int
run_test "Minimum int" "-2147483648" "\
char: impossible
int: -2147483648
float: -2147483648.0f
double: -2147483648.0"

# Test 20: Integer boundary - Minimum int - 1 (underflow)
run_test "Integer underflow" "-2147483649" "\
char: impossible
int: impossible
float: -2147483648.0f
double: -2147483649.0"

# Test 21: Float boundary - Zero with decimal
run_test "Float zero" "0.0f" "\
char: Non displayable
int: 0
float: 0.0f
double: 0.0"

# Test 22: Double boundary - Zero with decimal
run_test "Double zero" "0.0" "\
char: Non displayable
int: 0
float: 0.0f
double: 0.0"

# Test 23: Pseudo-literal - nanf
run_test "NaN float" "nanf" "\
char: impossible
int: impossible
float: nanf
double: nan"

# Test 24: Pseudo-literal - inff
run_test "Infinity float" "inff" "\
char: impossible
int: impossible
float: +inff
double: +inf"

# Test 25: Pseudo-literal - +inf (double)
run_test "Positive infinity double" "+inf" "\
char: impossible
int: impossible
float: +inff
double: +inf"

# Test 26: Edge case - Positive integer with +
run_test "Positive integer with +" "+42" "\
char: '*'
int: 42
float: 42.0f
double: 42.0"

# Test 27: Edge case - Positive float with +
run_test "Positive float with +" "+3.14f" "\
char: impossible
int: 3
float: 3.1f
double: 3.1"

# Test 28: Edge case - Positive double with +
run_test "Positive double with +" "+3.14" "\
char: impossible
int: 3
float: 3.1f
double: 3.1"

# Test 29: Error case - Empty quotes
run_test "Empty quotes" "''" "\
char: impossible
int: impossible
float: impossible
double: impossible"

# Test 30: Error case - Single quote only
run_test "Single quote" "'" "\
char: '''
int: 39
float: 39.0f
double: 39.0"

# Test 31: Error case - Multiple characters in quotes
run_test "Multiple chars" "'abc'" "\
char: impossible
int: impossible
float: impossible
double: impossible"

# Test 32: Error case - Float without f
run_test "Float without f" "3.14" "\
char: impossible
int: 3
float: 3.1f
double: 3.1"

# Test 33: Error case - Double f instead of single
run_test "Double f" "3.14ff" "\
char: impossible
int: impossible
float: impossible
double: impossible"

# Test 34: Error case - Only sign
run_test "Only plus sign" "+" "\
char: '+'
int: 43
float: 43.0f
double: 43.0"

# Test 35: Error case - Only minus sign
run_test "Only minus sign" "-" "\
char: '-'
int: 45
float: 45.0f
double: 45.0"

# Test 36: Error case - Multiple dots
run_test "Multiple dots" "3.14.15" "\
char: impossible
int: impossible
float: impossible
double: impossible"

# Test 37: Error case - Multiple dots in float
run_test "Multiple dots float" "3.14.15f" "\
char: impossible
int: impossible
float: impossible
double: impossible"

# Test 38: Error case - Letters in number
run_test "Letters in number" "12a34" "\
char: impossible
int: impossible
float: impossible
double: impossible"

# Test 39: Edge case - Very small decimal
run_test "Small decimal float" "0.1f" "\
char: impossible
int: 0
float: 0.1f
double: 0.1"

# Test 40: Edge case - Very small decimal double
run_test "Small decimal double" "0.1" "\
char: impossible
int: 0
float: 0.1f
double: 0.1"
