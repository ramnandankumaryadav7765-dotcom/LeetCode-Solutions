# LeetCode 1464 - Maximum Product of Two Elements in an Array

## Problem

Given an integer array `nums`, return the maximum value of:

`(nums[i] - 1) * (nums[j] - 1)`

where `i != j`.

---

## Approach 1: Brute Force

### Idea

Check every possible pair and calculate the product. Keep track of the maximum value obtained.

### Algorithm

1. Iterate through all pairs `(i, j)`.
2. Calculate `(nums[i] - 1) * (nums[j] - 1)`.
3. Update the maximum answer.

### Complexity

* Time Complexity: `O(n²)`
* Space Complexity: `O(1)`

### Learning

* Simplest approach.
* Useful for understanding the problem before optimization.

---

## Approach 2: Sorting

### Idea

After sorting the array, the two largest elements will be at the end of the array. Since the product is maximized by the largest numbers, we can directly use them.

### Algorithm

1. Sort the array.
2. Take the last two elements.
3. Return `(largest - 1) * (secondLargest - 1)`.

### Complexity

* Time Complexity: `O(n log n)`
* Space Complexity: `O(1)` (ignoring sorting space)

### Learning

* Sorting is often useful when only the largest or smallest elements matter.
* Easier to implement than brute force.

---

## Approach 3: Two Traversals

### Idea

Find the largest element and its index in the first traversal. In the second traversal, find the largest element excluding that index.

### Algorithm

1. Find the maximum element and its index.
2. Traverse the array again and find the maximum among the remaining elements.
3. Compute the answer.

### Complexity

* Time Complexity: `O(n)`
* Space Complexity: `O(1)`

### Learning

* Multiple linear traversals still result in `O(n)` complexity.
* Always initialize index variables to avoid undefined behavior.

---

## Approach 4: One Traversal (Optimal)

### Idea

Maintain the largest and second-largest elements while traversing the array only once.

### Algorithm

1. Keep two variables: `first` and `second`.
2. If the current element is greater than `first`, update both.
3. Otherwise, if it is greater than `second`, update `second`.
4. Return `(first - 1) * (second - 1)`.

### Complexity

* Time Complexity: `O(n)`
* Space Complexity: `O(1)`

### Learning

* Most efficient solution.
* Common interview pattern for finding the largest and second-largest elements.
* Handles duplicate maximum values correctly.

---

## Mistakes I Made

### Mistake 1: Invalid Index Access

I used:

```cpp
nums[i-1]
nums[j-1]
```

When `i = 0` or `j = 0`, this becomes `nums[-1]`, which is invalid.

### Mistake 2: Wrong Formula

I directly multiplied elements instead of using:

```cpp
(nums[i] - 1) * (nums[j] - 1)
```

### Mistake 3: Using the Same Element Twice

I allowed `i == j`, which violates the condition that both indices must be different.

### Mistake 4: Uninitialized Index Variable

While finding the maximum element, I forgot to initialize the index variable. This can lead to undefined behavior.

### Mistake 5: Missing Second Maximum Update

I only updated the maximum element and forgot to update the second maximum when required.

Incorrect:

```cpp
if(x > first){
    second = first;
    first = x;
}
```

Correct:

```cpp
if(x > first){
    second = first;
    first = x;
}
else if(x > second){
    second = x;
}
```

---

## Key Takeaways

1. Start with a brute-force solution to understand the problem.
2. Look for sorting-based optimizations.
3. If only a few extreme values are needed, avoid sorting and track them directly.
4. Always test edge cases such as:

   * Duplicate maximum values
   * Array of size 2
   * Maximum element at index 0
5. The "Largest and Second Largest" pattern is very common in DSA and interviews.

---

## Final Optimal Solution

```cpp
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int first = 0;
        int second = 0;

        for(int x : nums) {
            if(x > first) {
                second = first;
                first = x;
            }
            else if(x > second) {
                second = x;
            }
        }

        return (first - 1) * (second - 1);
    }
};
```

### Final Complexity

* Time Complexity: `O(n)`
* Space Complexity: `O(1)`

### Pattern Learned

**Tracking Largest and Second Largest Elements in One Pass**
