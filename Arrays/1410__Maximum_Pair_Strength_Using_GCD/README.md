# LeetCode 4010 - Maximum Pair Strength
         Weekly Contest:- 513

## Problem Overview

Given an array `nums`, find the maximum pair strength among all possible pairs.

Strength of a pair `(a, b)` is defined as:

```text
(a * b) / (gcd(a, b)²)
```

where `gcd(a, b)` is the Greatest Common Divisor of `a` and `b`.

---

# Approach 1: Brute Force + Manual GCD

## Idea

For every pair:

1. Find the GCD by checking all numbers from `min(a, b)` down to `1`.
2. Compute the strength.
3. Keep track of the maximum strength.

## Complexity

* Time Complexity: `O(n² × min(a,b))`
* Space Complexity: `O(1)`

## Learning

Although this approach works, finding GCD manually is very expensive and leads to unnecessary computations.

---

# Approach 2: Brute Force + Euclid's GCD Algorithm (Optimized)

## Idea

Instead of manually finding the GCD, use the built-in Euclidean Algorithm:

```cpp
gcd(a, b)
```

This computes GCD in logarithmic time.

## Algorithm

1. Generate all possible pairs.
2. Find GCD using `gcd()`.
3. Calculate:

```text
(a * b) / (gcd(a,b)²)
```

4. Update the maximum answer.

## Code

```cpp
class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {

        long long maximum = LLONG_MIN;

        for(int i = 0; i < nums.size(); i++) {
            for(int j = i + 1; j < nums.size(); j++) {

                long long g = gcd(nums[i], nums[j]);

                long long strength =
                    (1LL * nums[i] * nums[j]) /
                    (g * g);

                maximum = max(maximum, strength);
            }
        }

        return maximum;
    }
};
```

---

# Mathematical Observation

Let:

```text
a = g × x
b = g × y
```

where:

```text
g = gcd(a,b)
```

Then:

```text
(a × b) / g²

= (g × x)(g × y) / g²

= x × y
```

Therefore:

```text
Strength = (a / gcd(a,b)) × (b / gcd(a,b))
```

This observation simplifies understanding of the formula.

---

# Complexity Analysis

For every pair:

```cpp
gcd(a,b)
```

takes:

```text
O(log(min(a,b)))
```

Total complexity:

```text
O(n² log M)
```

where:

```text
M = maximum element in nums
```

Space complexity:

```text
O(1)
```

---

# Mistakes I Made

## Mistake 1: Manual GCD Search

Initially, I used:

```cpp
for(int k = min(a,b); k >= 1; k--){
    if(a % k == 0 && b % k == 0){
        gcd = k;
        break;
    }
}
```

### Problem

This increases complexity significantly.

### Fix

Use:

```cpp
gcd(a,b)
```

which uses Euclid's Algorithm.

---

## Mistake 2: Integer Overflow

Initially:

```cpp
(nums[i] * nums[j])
```

was calculated using `int`.

### Problem

Large values may overflow.

### Fix

Use:

```cpp
1LL * nums[i] * nums[j]
```

to force `long long` multiplication.

---

## Mistake 3: Using int for Answer

Initially:

```cpp
int maximum = INT_MIN;
```

### Problem

Answer may exceed integer range.

### Fix

Use:

```cpp
long long maximum = LLONG_MIN;
```

---

# Contest Observation

Constraint:

```text
n ≤ 2000
```

Number of pairs:

```text
n(n-1)/2
≈ 2,000,000
```

This indicates that an `O(n²)` pair enumeration solution is intended.

Therefore:

```text
O(n² log M)
```

is efficient enough and likely the expected contest solution.

---

# Key Takeaways

1. Always replace manual GCD computation with Euclid's Algorithm.
2. Watch for integer overflow in multiplication problems.
3. Constraints often reveal the intended solution.
4. For `n ≤ 2000`, an `O(n²)` solution is usually acceptable.
5. Mathematical simplification can help understand formulas even when it does not directly improve complexity.

---

# Pattern Learned

**Pair Enumeration + Number Theory (GCD Optimization)**

Common techniques used:

* Brute Force Pair Generation
* Euclid's GCD Algorithm
* Overflow Handling with `long long`
* Complexity Analysis Based on Constraints
