# Kernel Performance Comparison

This programming project contains a comparative analysis of the execution times of C and ASM dot product kernels for various input sizes.

## Execution Time Analysis

Each kernel was executed **20 times** for each input size, and the average execution times were calculated.

### 2²⁰ Elements

![Description](https://i.imgur.com/OsGRYsA.jpeg)

|**Kernel**|**Execution Time (ms)**|
|---|---|
|C|Average: 3.51017 ms|
|ASM|Average: 0.92274 ms|

### 2²⁴ Elements

![Description](https://i.imgur.com/ABgUh3P.jpeg)

|**Kernel**|**Execution Time (ms)**|
|---|---|
|C|Average: 56.3765 ms|
|ASM|Average: 13.2645 ms|

### 2²⁸ Elements

![Description](https://i.imgur.com/b6cID70.jpeg)

|**Kernel**|**Execution Time (ms)**|
|---|---|
|C|Average: 999.748 ms|
|ASM|Average: 230.531 ms|

## Performance Analysis

1. **ASM Performance**:
    - It is significantly faster for all the input sizes, outperforming C by ~75-90%.
    - The performance gap increases with larger input sizes.
2. **C Performance**:
    - Its performance is slower compared to ASM, with increasing disparity as input sizes grow.

Developed by QUIRANTE, JULIAN ROY BERNARDO and PORCIUNCULA, LEXREY DANCEL