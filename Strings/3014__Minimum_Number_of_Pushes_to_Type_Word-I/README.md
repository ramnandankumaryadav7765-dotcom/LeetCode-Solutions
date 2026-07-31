# 📒 DSA Diary Note #5

## LeetCode 3014 – Minimum Number of Pushes to Type Word I

### Difficulty

Easy

### Core Observation

The most important line in the problem is:

```text
All characters in word are distinct.
```

This means:

```text
No character repeats.
```

Therefore:

```text
Frequency does NOT matter.
```

We do NOT need:

```cpp
unordered_map
unordered_set
```

The answer depends only on:

```cpp
word.length()
```

---

## Keypad Structure

There are 8 positions for each push count.

```text
Position 1 - 8    → 1 Push
Position 9 - 16   → 2 Pushes
Position 17 - 24  → 3 Pushes
Position 25 - 26  → 4 Pushes
```

---

## Cost Calculation

### First 8 Characters

```text
8 × 1 = 8
```

---

### Next 8 Characters

```text
8 × 2 = 16
```

Total till 16 characters:

```text
8 + 16 = 24
```

---

### Next 8 Characters

```text
8 × 3 = 24
```

Total till 24 characters:

```text
24 + 24 = 48
```

---

### Last 2 Characters

```text
2 × 4 = 8
```

Maximum total:

```text
48 + 8 = 56
```

---

## Correct Formula

```cpp
if(n <= 8)
    return n;

else if(n <= 16)
    return (n - 8) * 2 + 8;

else if(n <= 24)
    return (n - 16) * 3 + 24;

else
    return (n - 24) * 4 + 48;
```

---

## Common Mistake

❌ Wrong

```cpp
(n - 16) * 4 + 48
```

Reason:

```text
48 already represents cost of first 24 characters.
```

So only characters after 24 should be multiplied by 4.

---

✅ Correct

```cpp
(n - 24) * 4 + 48
```

---

## Example

### Input

```text
word = "abcdefghijklmnop"
```

Length:

```text
n = 16
```

Cost:

```text
8 × 1 = 8
8 × 2 = 16
```

Answer:

```text
24
```

---

## Better Pattern

For every character index:

```cpp
pushes = index / 8 + 1;
```

Example:

```text
Index 0-7    → 1 push
Index 8-15   → 2 pushes
Index 16-23  → 3 pushes
Index 24-25  → 4 pushes
```

---

## Time Complexity

```text
O(1)
```

Using formula.

---

## Space Complexity

```text
O(1)
```

No extra data structures.

---

## What I Learned

### Observation-Based Problem

Sometimes the biggest clue is hidden in the constraints.

Here:

```text
All characters are distinct
```

allows us to ignore frequency counting completely.

---

### Interview Explanation

"Since all characters are unique, frequency does not matter. The answer depends only on the number of characters. I divide the letters into groups of 8, where each group requires one additional push count, and calculate the total cost accordingly."

---

## ⭐ Revision Formula

```text
All Characters Unique
          ↓
Frequency Irrelevant
          ↓
Only Length Matters
          ↓
Every 8 Characters
Push Count Increases by 1
```

### Pattern Learned

```text
Constraint Analysis
        +
Mathematical Observation
        +
Grouping
```
