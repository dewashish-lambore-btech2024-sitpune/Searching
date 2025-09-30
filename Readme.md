# 🔍 Searching in C++

## 🎯 Objective  
To explore and develop **Searching algorithms in C++**, encompassing **Linear Search, Binary Search, Jump Search, Interpolation Search, and Fibonacci Search**, while evaluating their performance characteristics, complexity analysis, and practical scenarios.

---

## 📚 Theoretical Foundation  

Searching refers to the process of locating a specific element (the **target**) within a data collection.  

### 1. Linear Search  
- Examines array elements sequentially from beginning to end.  
- Applicable to **both sorted and unsorted arrays**.  
- Time Complexity: **O(n)**  

---

### 2. Binary Search  
- Requires **pre-sorted arrays**.  
- Continuously halves the search space by comparing with middle element.  
- Time Complexity: **O(log n)**  

---

### 3. Jump Search  
- Operates on **sorted arrays**.  
- Advances through array in fixed increments (√n) rather than examining each element.  
- Performs linear examination within identified block.  
- Time Complexity: **O(√n)**  

---

### 4. Interpolation Search  
- Designed for **sorted arrays with uniform distribution**.  
- Enhances binary search by calculating probable position using interpolation formula:  
  `pos = low + ((target - arr[low]) * (high - low)) / (arr[high] - arr[low])`  
- Time Complexity: **O(log log n)** (optimal case), **O(n)** (degraded case with non-uniform data).  

---

### 5. Fibonacci Search  
- Functions on **sorted arrays**.  
- Employs Fibonacci sequence to partition the array into segments.  
- Comparable to binary search but utilizes Fibonacci numbers for determining division points.  
- Time Complexity: **O(log n)**  

---

## 📋 Algorithms  

### 🧾 Linear Search  
1. Begin  
2. Accept array and target value.  
3. Iterate through each element from index 0 to n-1:  
   - If `arr[i] == target`, return current index.  
4. If unsuccessful, display "Element not present".  
5. Terminate  

---

### 🧾 Binary Search  
1. Begin  
2. Accept sorted array and target value.  
3. Set `low = 0`, `high = n-1`.  
4. Repeat while `low <= high`:  
   - Calculate `mid = (low + high) / 2`  
   - If `arr[mid] == target`, return current index.  
   - If `arr[mid] > target`, update `high = mid - 1`.  
   - Otherwise update `low = mid + 1`.  
5. If unsuccessful, display "Element not present".  
6. Terminate  

---

### 🧾 Jump Search  
1. Begin  
2. Accept sorted array and target value.  
3. Calculate step = √n.  
4. Advance in increments until `arr[min(step, n)-1] >= target`.  
5. Execute linear search within block from `previous step` to `current step`.  
6. If located, return index; otherwise display "Element not present".  
7. Terminate  

---

### 🧾 Interpolation Search  
1. Begin  
2. Accept sorted, uniformly distributed array and target value.  
3. Set `low = 0`, `high = n-1`.  
4. Repeat while `low <= high` and `target >= arr[low]` and `target <= arr[high]`:  
   - Calculate `pos = low + ((target - arr[low]) * (high - low)) / (arr[high] - arr[low])`.  
   - If `arr[pos] == target`, return current index.  
   - If `arr[pos] < target`, update `low = pos + 1`.  
   - Otherwise update `high = pos - 1`.  
5. If unsuccessful, display "Element not present".  
6. Terminate  

---

### 🧾 Fibonacci Search  
1. Begin  
2. Accept sorted array and target value.  
3. Initialize Fibonacci sequence: `fibM = fib(k)`, `fibMm1 = fib(k-1)`, `fibMm2 = fib(k-2)`.  
4. Generate Fibonacci numbers until `fibM >= n`.  
5. Set offset = -1.  
6. Repeat while `fibM > 1`:  
   - Calculate `i = min(offset + fibMm2, n-1)`  
   - If `arr[i] < target`: adjust Fibonacci values down by one position, update offset = i.  
   - If `arr[i] > target`: adjust Fibonacci values down by two positions.  
   - Otherwise return current index.  
7. Verify if final element matches target, return index if true.  
8. Otherwise display "Element not present".  
9. Terminate  

---

## 🧩 Complexity Analysis Comparison  

| Algorithm           | Best Case | Worst Case | Average Case | Space Complexity |
|---------------------|-----------|------------|--------------|------------------|
| Linear Search       | O(1)      | O(n)       | O(n)         | O(1)             |
| Binary Search       | O(1)      | O(log n)   | O(log n)     | O(1)             |
| Jump Search         | O(1)      | O(√n)      | O(√n)        | O(1)             |
| Interpolation Search| O(1)      | O(n)       | O(log log n) | O(1)             |
| Fibonacci Search    | O(1)      | O(log n)   | O(log n)     | O(1)             |

---

## 🚀 Practical Applications  

- **Linear Search** → Limited datasets or unordered collections.  
- **Binary Search** → Extensive sorted datasets, dictionary lookups.  
- **Jump Search** → Sorted collections where √n operations are acceptable.  
- **Interpolation Search** → Sorted, evenly distributed datasets (e.g., contact directories, numerical ranges).  
- **Fibonacci Search** → Sorted collections where division operations are computationally expensive (utilizes addition/subtraction).  

---

## 🧠 Summary  

- **Linear Search** offers simplicity but lacks efficiency for substantial datasets.  
- **Binary Search** provides optimal performance but necessitates pre-sorted data.  
- **Jump Search** enhances efficiency by bypassing blocks of elements.  
- **Interpolation Search** excels with uniformly distributed data patterns.  
- **Fibonacci Search** serves as an alternative to binary search, avoiding division operations.  
- Collectively, these algorithms establish the **cornerstone of search methodologies in DSA** and find extensive application in database systems, operating system management, and time-critical applications.
