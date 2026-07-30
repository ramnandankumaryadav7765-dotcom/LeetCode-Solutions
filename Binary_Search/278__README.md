## LeetCode 2682 – Find the Losers of the Circular Game

### Difficulty

LeetCode: Easy

### My Opinion

Although LeetCode marks it as Easy, it feels closer to Easy-Medium because it combines:

* Simulation
* Circular Traversal
* Modulo Arithmetic
* Visited Array
* Cycle Detection

---

## 1. Core Idea

Simulate the game exactly as given.

* Start from Friend 1 (index 0).
* On each turn move (turn × k) steps.
* Mark every friend who receives the ball.
* Stop when a friend receives the ball for the second time.
* Friends who never received the ball are the losers.

---

## 2. Pattern Recognition

Whenever a problem says:

* Already visited?
* Already seen?
* Repeated position?
* Stop when repetition occurs?

Think:

```cpp
vector<bool> visited(n, false);
```

or

```cpp
unordered_set
```

---

## 3. Important Variables

```cpp
int current = 0;
```

Current position of the ball.

Initially:

```text
Friend 1
```

which corresponds to:

```text
Index 0
```

---

```cpp
int turn = 1;
```

Represents the current round.

Movement pattern:

```text
1 × k
2 × k
3 × k
4 × k
...
```

---

## 4. Circular Movement Formula

```cpp
current = (current + turn * k) % n;
```

This is the most important line of the problem.

### Why % n ?

Because the circle wraps around.

Example:

```text
n = 5
current = 4
turn = 1
k = 2
```

Without modulo:

```text
4 + 2 = 6
```

Index 6 does not exist.

With modulo:

```cpp
(4 + 2) % 5
```

```text
6 % 5 = 1
```

Correct circular movement.

---

## 5. Stopping Condition

```cpp
if(visited[current]){
    break;
}
```

Problem says:

> Stop when a friend receives the ball again.

Therefore:

```text
Already Visited
        ↓
Game Ends
```

---

## 6. Mark Friend as Visited

```cpp
visited[current] = true;
turn++;
```

Meaning:

```text
Friend received the ball
        ↓
Move to next turn
```

---

## 7. Finding Losers

After simulation:

```cpp
for(int i = 0; i < n; i++){
    if(!visited[i]){
        ans.push_back(i + 1);
    }
}
```

---

### Why i + 1 ?

Array:

```text
0 1 2 3 4
```

Friend Numbers:

```text
1 2 3 4 5
```

LeetCode wants friend numbers.

---

## 8. Dry Run

Input:

```text
n = 5
k = 2
```

Initially:

```text
visited = [T,F,F,F,F]
current = 0
turn = 1
```

---

### Turn 1

```cpp
current = (0 + 1*2) % 5
```

```text
current = 2
```

```text
visited = [T,F,T,F,F]
```

---

### Turn 2

```cpp
current = (2 + 2*2) % 5
```

```text
current = 1
```

```text
visited = [T,T,T,F,F]
```

---

### Turn 3

```cpp
current = (1 + 3*2) % 5
```

```text
current = 2
```

Already visited.

Stop.

---

Losers:

```text
4, 5
```

Answer:

```text
[4,5]
```

---

## 9. Time Complexity

Simulation:

```text
O(n)
```

Finding losers:

```text
O(n)
```

Overall:

```text
O(n)
```

---

## 10. Space Complexity

Visited array:

```text
O(n)
```

---

## 11. Concepts Learned

### Simulation

Follow the instructions exactly as given.

---

### Circular Traversal

```cpp
(index + steps) % n
```

Used in:

* Circular Queue
* Josephus Problem
* Round Robin Scheduling
* Circular Array Problems

---

### Visited Array

```cpp
vector<bool> visited(n,false);
```

Used for:

* Tracking visited positions
* Detecting repetition
* Cycle detection

---

## 12. Common Mistakes

❌ Forgetting:

```cpp
visited[0] = true;
```

Friend 1 initially has the ball.

---

❌ Forgetting:

```cpp
% n
```

which breaks circular movement.

---

❌ Returning index instead of friend number.

Wrong:

```cpp
ans.push_back(i);
```

Correct:

```cpp
ans.push_back(i+1);
```

---

## 13. Interview Explanation

"I simulated the game using a visited array. On each turn I moved (turn × k) positions in a circular manner using modulo arithmetic. The game stops when a friend is visited again, and all unvisited friends are returned as losers."

---

## ⭐ Revision Formula

```text
Start at Friend 1
        ↓
Mark Visited
        ↓
Move (turn × k)
        ↓
Use % n for Circle
        ↓
If Already Visited → Stop
        ↓
Collect Unvisited Friends
```

---

## Final Takeaway

This problem teaches three very important patterns:

1. Simulation
2. Circular Traversal using Modulo
3. Visited Array for Repetition Detection

Whenever you see:

```text
Circle
+
Repeated Visit
+
Follow Given Rules
```

Think:

```text
Simulation + Visited Array + Modulo
```
