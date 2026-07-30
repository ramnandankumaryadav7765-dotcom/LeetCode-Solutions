# LeetCode 2682 - Find the Losers of the Circular Game

## Approach

1. Create a visited array to track which friends have received the ball.

2. Start from Friend 1 (index 0).

3. On each turn move:

   (turn × k) steps

4. Use modulo (%) to move in a circular manner.

5. If a friend is visited again, stop the game.

6. Traverse the visited array and collect all unvisited friends.

---

## Important Variables

```cpp
int current = 0;
```

Current friend's index.

```cpp
int turn = 1;
```

Current round number.

```cpp
vector<bool> visited(n, false);
```

Tracks who has received the ball.

---

## Most Important Line

```cpp
current = (current + turn * k) % n;
```

Why?

Because friends sit in a circle.

Example:

```text
n = 5

0 1 2 3 4
```

If:

```text
current = 4
turn = 1
k = 2
```

Then:

```cpp
(4 + 2) % 5 = 1
```

So we wrap around the circle.

---

## Stopping Condition

```cpp
if(visited[current]){
    break;
}
```

The problem says:

"Stop when a friend receives the ball for the second time."

---

## Why i + 1 ?

Array indices:

```text
0 1 2 3 4
```

Friend numbers:

```text
1 2 3 4 5
```

Therefore:

```cpp
ans.push_back(i + 1);
```

---

## Time Complexity

```text
O(n)
```

Each friend is visited at most once.

---

## Space Complexity

```text
O(n)
```

For the visited array.

---

## Patterns Learned

✅ Simulation

✅ Visited Array

✅ Circular Traversal

✅ Modulo Arithmetic

---

## Revision Formula

Start at Friend 1

↓

Mark Visited

↓

Move (turn × k)

↓

Use % n

↓

If already visited → Stop

↓

Collect unvisited friends
