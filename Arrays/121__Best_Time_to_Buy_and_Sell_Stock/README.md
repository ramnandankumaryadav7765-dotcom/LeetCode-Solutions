# 121. Best Time to Buy and Sell Stock

## Problem

You are given an array `prices` where `prices[i]` is the price of a stock on the `i-th` day.

You want to maximize your profit by choosing a single day to buy one stock and a different future day to sell that stock.

Return the maximum profit you can achieve. If no profit is possible, return `0`.

---

## Example

**Input**
prices = [7,1,5,3,6,4]

**Output**
5

**Explanation**

Buy at price `1` and sell at price `6`.

Profit = `6 - 1 = 5`

---

## Approach

- Traverse the array only once.
- Keep track of the minimum price seen so far.
- At every index, assume the current day is the selling day.
- Calculate the current profit.
- Update the maximum profit whenever a better profit is found.

---

## Algorithm

1. Initialize `minimum` as the first price.
2. Initialize `maximumProfit` as `0`.
3. Traverse the array from left to right.
4. Update the minimum price seen so far.
5. Calculate the current profit.
6. Update the maximum profit.
7. Return the maximum profit.

---

## Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

---

## Key Learning

This problem teaches an important interview pattern:

> Maintain the best information from the past while scanning the array once.

Instead of searching for the global minimum first, continuously update the minimum price seen so far and calculate the best possible profit for each selling day.

---

## Tags

`Array` `Greedy` `One Pass` `Optimization`
