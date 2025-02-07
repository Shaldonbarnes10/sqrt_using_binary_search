# Square Root Calculation in C++

## Overview
This C++ program calculates the square root of a given integer using a combination of **binary search** (to determine the integer part) and **incremental search** (to refine the decimal part up to three decimal places). The algorithm efficiently finds the square root without using built-in functions like `sqrt()`.

## Features
- Uses **binary search** to determine the integer part of the square root.
- Uses an **incremental search** to refine the decimal part up to **three decimal places**.
- Provides an accurate approximation of the square root.

## Algorithm Explanation
### **1. Integer Part Calculation (Binary Search) - `integerpart(int n)`**
- The function finds the largest integer `x` such that `x^2 ≤ n`.
- Uses **binary search** to efficiently determine this value.
- Returns the integer part of the square root.

### **2. Decimal Part Calculation (Incremental Search) - `decimalpart(int n)`**
- Starts with the integer part and increments by **0.1** until `ans^2` exceeds `n`.
- Reduces the increment step (`0.1 -> 0.01 -> 0.001`) for finer precision.
- Returns the approximate square root with up to **three decimal places**.

## Code Breakdown
```cpp
#include<iostream>
using namespace std;

// Function to calculate the integer part of the square root
int integerpart(int n){
    int l = 0, ans;
    int h = n / 2;
    while (l <= h){
        long long int mid = l + (h - l) / 2;
        long long int sqr = mid * mid;
        if (sqr == n){
            return mid;
        } else if (sqr > n){
            h = mid - 1;
        } else {
            ans = mid;
            l = mid + 1;
        }
    }
    return ans;
}

// Function to refine the decimal part up to three places
double decimalpart(int n) {
    double ans = integerpart(n);
    double increment = 0.1;

    for (int i = 0; i < 3; i++) {  // Precision of 3 decimal places
        while ((ans + increment) * (ans + increment) <= n) {
            ans += increment;
        }
        increment /= 10;  // Reduce increment for finer precision
    }
    return ans;
}

int main(){
    int n;
    cout << "Enter the number whose sqrt is to be determined: ";
    cin >> n;
    double answer = decimalpart(n);
    cout << answer;
}
```

## How to Run the Code
### **Step 1: Compile the Code**
Use the following command to compile the program using `g++`:
```sh
g++ sqrt_calculator.cpp -o sqrt_calculator
```

### **Step 2: Run the Program**
Execute the compiled file:
```sh
./sqrt_calculator
```

### **Step 3: Enter an Integer Input**
The program will prompt you to enter a number:
```
Enter the number whose sqrt is to be determined: 10
```

### **Step 4: Get the Output**
The program will output the approximate square root:
```
3.162
```

## Sample Test Cases
| Input | Expected Output |
|-------|----------------|
| 25    | 5.000          |
| 50    | 7.071          |
| 100   | 10.000         |
| 2     | 1.414          |

## Complexity Analysis
- **Integer part calculation** (Binary Search) → `O(log n)`
- **Decimal refinement** → `O(3 * sqrt(n))`
- **Overall Complexity** → `O(log n + 3*sqrt(n))`

## Possible Enhancements
- Add more precision by increasing loop iterations in `decimalpart()`.
- Use `setprecision()` from `<iomanip>` to format output with fixed decimal places.
- Optimize for large numbers by adjusting search ranges.

## License
This project is open-source and free to use under the MIT License.

---

### **Author**: Shaldonbarnes10

