# 🏰 Tower of Hanoi – C Implementation Using Stacks and Queues
<img width="488" height="276" alt="image" src="https://github.com/user-attachments/assets/fb2c11e6-fb49-4519-93a8-334637d213f3" />


## 📋 Overview

This project is a C implementation of the classic **Tower of Hanoi** puzzle. The solution uses **Stacks** and **Queues** to simulate the movement of disks between rods, showcasing the algorithmic beauty of recursion and data structure manipulation.

The Tower of Hanoi puzzle consists of three rods and a number of disks of different sizes which can slide onto any rod. The puzzle starts with the disks neatly stacked in ascending order of size on one rod, the smallest at the top. The objective is to move the entire stack to another rod, obeying the following rules:

1. Only one disk can be moved at a time.
2. Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack or on an empty rod.
3. No larger disk may be placed on top of a smaller disk.

---

## 📦 Features

- Recursive solution to solve Tower of Hanoi
- Use of **Stacks** to model the rods
- Use of **Queues** (optional) for move tracking or visual scheduling
- Terminal-based visualization of disk movements
- Supports any number of disks

---

## 🧠 Data Structures Used

- **Stack (LIFO)**:
  - Used to represent each of the three rods (source, auxiliary, destination).
  - Implemented using linked lists or arrays.

- **Queue (FIFO)** _(optional)_:
  - Used to keep track of the sequence of moves or to simulate animation steps.

---
![Uploading image.png…]()

## 🚀 How to Run

### 1. Compile the code:

```bash
gcc hanoi.c -o hanoi
