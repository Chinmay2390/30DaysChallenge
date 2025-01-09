
// #include<bits/stdc++.h>
// using namespace std;

// map<vector<string>, string> pattern_to_digit = {
//     {{" _ ", "| |", "|_|"}, "0"},
//     {{"   ", "  |", "  |"}, "1"},
//     {{" _ ", " _|", "|_ "}, "2"},
//     {{" _ ", " _|", " _|"}, "3"},
//     {{"   ", "|_|", "  |"}, "4"},
//     {{" _ ", "|_ ", " _|"}, "5"},
//     {{" _ ", "|_ ", "|_|"}, "6"},
//     {{" _ ", "  |", "  |"}, "7"},
//     {{" _ ", "|_|", "|_|"}, "8"},
//     {{" _ ", "|_|", " _|"}, "9"},
//     {{"   ", "|_ ", "|  "}, "+"},
//     {{"   ", " _ ", "   "}, "-"},
//     {{"   ", "|_|", "| |"}, "*"},
//     {{" _ ", " _ ", " _ "}, "%"},
//     {{"   ", " _ ", " _ "}, "="}
// };

// int main() {
//     int n;
//     cin >> n;

//     vector<string> input(3);
//     cin.ignore(); // To handle the leftover newline after reading 'n'

//     for (int i = 0; i < 3; i++) {
//         getline(cin, input[i]);
//     }

//     // Extract each digit's pattern
//     // int num_digits = input[0].size() / 3; // Each digit takes 3 columns
//     string result;
//     for (int i = 0; i < n; i++) {
//         vector<string> digit_pattern = {
//             input[0].substr(i * 3, 3),
//             input[1].substr(i * 3, 3),
//             input[2].substr(i * 3, 3)
//         };

//         // Check if the pattern matches a digit
//         if (pattern_to_digit.find(digit_pattern) != pattern_to_digit.end()) {
//             result += (pattern_to_digit[digit_pattern]);
//         }
//     }

//     cout << result << endl; // Print the result

//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;

map<vector<string>, string> pattern_to_digit = {
    {{" _ ", "| |", "|_|"}, "0"},
    {{"   ", "  |", "  |"}, "1"},
    {{" _ ", " _|", "|_ "}, "2"},
    {{" _ ", " _|", " _|"}, "3"},
    {{"   ", "|_|", "  |"}, "4"},
    {{" _ ", "|_ ", " _|"}, "5"},
    {{" _ ", "|_ ", "|_|"}, "6"},
    {{" _ ", "  |", "  |"}, "7"},
    {{" _ ", "|_|", "|_|"}, "8"},
    {{" _ ", "|_|", " _|"}, "9"},
    {{"   ", "|_ ", "|  "}, "+"},
    {{"   ", " _ ", "   "}, "-"},
    {{"   ", "|_|", "| |"}, "*"},
    {{" _ ", " _ ", " _ "}, "%"},
    {{"   ", " _ ", " _ "}, "="}
};

int main() {
    int n;
    cin >> n;

    vector<string> input(3);
    cin.ignore(); // To handle the leftover newline after reading 'n'

    for (int i = 0; i < 3; i++) {
        getline(cin, input[i]);
    }

    // Extract the equation from the patterns
    string result;
    vector<string> equation_parts;
    for (int i = 0; i < n; i++) {
        vector<string> digit_pattern = {
            input[0].substr(i * 3, 3),
            input[1].substr(i * 3, 3),
            input[2].substr(i * 3, 3)
        };

        // Check if the pattern matches a digit or symbol
        if (pattern_to_digit.find(digit_pattern) != pattern_to_digit.end()) {
            result += pattern_to_digit[digit_pattern];
            equation_parts.push_back(pattern_to_digit[digit_pattern]);
        }
    }

    // Now equation_parts contains the decoded equation (e.g., "1+2=9")
    cout << "Decoded Equation: " << result << endl;

    // Check if the equation is valid
    stringstream ss(result);
    string left_expr, right_expr;
    getline(ss, left_expr, '=');
    getline(ss, right_expr);

    // Check if the right-hand side is a valid result
    int expected_result = 0;
    if (left_expr.find('+') != string::npos) {
        // Handle addition
        size_t pos = left_expr.find('+');
        int left_operand = stoi(left_expr.substr(0, pos));
        int right_operand = stoi(left_expr.substr(pos + 1));
        expected_result = left_operand + right_operand;
    }

    // Compare the expected result with the actual result
    int actual_result = stoi(right_expr);
    if (expected_result != actual_result) {
        // If the result is incorrect, find which character is wrong
        for (int i = 0; i < equation_parts.size(); i++) {
            // Make a copy of the equation and replace the i-th character with the expected value
            string modified_result = result;
            modified_result[i] = '0' + expected_result; // Replace with the correct expected character

            // Check if the modified result matches
            if (modified_result == result) {
                cout << "The character at position " << i << " is wrong." << endl;
                break;
            }
        }
    } else {
        cout << "The equation is correct!" << endl;
    }

    return 0;
}
