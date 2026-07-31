# 📒 DSA Diary Note #6

## LeetCode 3016 – **Minimum Number of Pushes to Type Word II**

### Difficulty

Medium

---

## Core Observation

Unlike LeetCode 3014:

```text
Characters are NOT necessarily unique.
```

Example:

```text
word = "aaabbbbcc"
```

Frequency:

```text
a → 3
b → 4
c → 2
```

Therefore:

```text
Frequency matters.
```

---

## Key Idea

We want:

```text
Most Frequent Character
            ↓
Least Number of Pushes
```

Because frequently used letters should be cheaper to type.

This is a Greedy Problem.

---

## Step 1 : Count Frequency

```cpp
vector<int> freq(26,0);

for(auto ch : word){
    freq[ch-'a']++;
}
```

Example:

```text
word = "aaabbbbcc"

freq = [3,4,2,0,0,0...]
```

---

## Step 2 : Sort Frequencies

```cpp
sort(freq.begin(), freq.end(), greater<int>());
```

After sorting:

```text
[4,3,2,0,0,0...]
```

Largest frequencies come first.

---

## Why Sorting?

We want:

```text
Highest Frequency
        ↓
Lowest Cost
```

Sorting automatically places the most frequent letters at the beginning.

---

## Step 3 : Assign Push Cost

```cpp
ans += freq[i] * (i/8 + 1);
```

---

### Understanding i/8 + 1

#### First Group

```text
i = 0 to 7
```

```cpp
i/8 = 0
```

Cost:

```cpp
0 + 1 = 1
```

---

#### Second Group

```text
i = 8 to 15
```

```cpp
i/8 = 1
```

Cost:

```cpp
1 + 1 = 2
```

---

#### Third Group

```text
i = 16 to 23
```

Cost:

```cpp
2 + 1 = 3
```

---

#### Fourth Group

```text
i = 24 to 25
```

Cost:

```cpp
3 + 1 = 4
```

---

## Push Cost Table

| Position | Cost |
| -------- | ---- |
| 1 - 8    | 1    |
| 9 - 16   | 2    |
| 17 - 24  | 3    |
| 25 - 26  | 4    |

---

## Dry Run

```text
word = "aaabbbbcc"
```

Frequency:

```text
a → 3
b → 4
c → 2
```

Sorted:

```text
[4,3,2]
```

Calculation:

```text
4 × 1 = 4
3 × 1 = 3
2 × 1 = 2
```

Answer:

```text
9
```

---

## Most Important Formula

```cpp
cost = i/8 + 1;
```

Creates:

```text
1 1 1 1 1 1 1 1
2 2 2 2 2 2 2 2
3 3 3 3 3 3 3 3
4 4
```

Automatically.

---

## Time Complexity

Frequency Count:

```text
O(n)
```

Sorting:

```text
O(26 log 26)
```

Since 26 is constant:

```text
Overall = O(n)
```

---

## Space Complexity

```text
O(26)
```

Which is effectively:

```text
O(1)
```

---

## New Concepts Learned

✅ Frequency Counting

✅ Greedy Assignment

✅ Sorting Frequencies

✅ greater<int>()

✅ Grouping using:

```cpp
i/8 + 1
```

---

## Interview Explanation

"I counted the frequency of every character and sorted frequencies in descending order. Then I assigned the highest frequencies to the cheapest keypad positions. The push cost of a position is determined by i/8 + 1, which groups characters into blocks of 8."

---

## ⭐ Revision Formula

```text
Count Frequency
        ↓
Sort Descending
        ↓
Highest Frequency First
        ↓
Cost = i/8 + 1
        ↓
Frequency × Cost
        ↓
Answer
```

### Pattern Learned

```text
Frequency Counting
        +
Sorting
        +
Greedy
```
