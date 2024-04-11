# Lưu ý khi làm bài thi về đệ quy

* Bước 1: Base case xảy ra: ghi rõ ràng

* Bước 2: Kết quả của base case: ghi rõ ràng

* Bước 3: Trước base case là trường hợp nào: là trường hợp trước khi đệ quy dừng

* Bước 4: Trước bước 3 đúng **1** trường hợp thôi

## Ví dụ trong bài PRACTICE 2

### 1. Tính tổng $S(n) = 1 + \frac{1}{2} + ... + \frac{1}{n}.$

```c++
float S1(int n) {
    if(n == 1) return 1;
    return 1.0/n + S1(n - 1);
}
```

* Bước 1: Base case xảy ra:
    Base case là khi $n$ == $1$ hàm trả về $1$

    ``` c++
    if(n == 1) return 1;
    ```

* Bước 2: Kết quả của base case:
    Kết quả của base case là $S(1) = 1$

* Bước 3: Trước base case là trường hợp nào: là trường hợp trước khi đệ quy dừng
    Trường hợp $n == 2$ Kết quả của $S(2) = 1.5$

* Bước 4: Trước bước 3 đúng **1** trường hợp thôi
    Trường hợp $n == 3$ Kết quả của $S(3) = 1.8(3)$

### 2. Tính tổng $S(n) =\frac{1}{2} + \frac{1}{4} ... + \frac{1}{2^n}.$

```c++
float S2(int n) {
    if(n == 1) return 0.5;
    return 1.0/pow(2, n) + S2(n - 1);
}
```

* Bước 1: Base case xảy ra:
    Base case là khi $n$ == $1$ hàm trả về $1$.

    ``` c++
    if(n == 1) return 0.5;
    ```

* Bước 2: Kết quả của base case:
    Kết quả của base case là $S(1) = 0.5$.

* Bước 3: Trước base case là trường hợp nào: là trường hợp trước khi đệ quy dừng
    Trường hợp $n == 2$ Kết quả của $S(2) = 0.75$.

* Bước 4: Trước bước 3 đúng **1** trường hợp thôi
    Trường hợp $n == 3$ Kết quả của $S(3) = 0.875$.

### 3. Tính tổng $S(n) =\frac{1}{2} + \frac{2}{3} ... + \frac{n}{n + 1}.$

```c++
float S3(int n) {
    if(n == 1) return 0.5;
    return 1.0*n/(n + 1) + S3(n - 1);
}
```

* Bước 1: Base case xảy ra:
    Base case là khi $n$ == $1$ hàm trả về $0.5$.

    ``` c++
    if(n == 1) return 0.5;
    ```

* Bước 2: Kết quả của base case:
    Kết quả của base case là $S(1) = 0.5$.

* Bước 3: Trước base case là trường hợp nào: là trường hợp trước khi đệ quy dừng
    Trường hợp $n == 2$ Kết quả của $S(2) = 1.166667$.

* Bước 4: Trước bước 3 đúng **1** trường hợp thôi
    Trường hợp $n == 3$ Kết quả của $S(3) = 1.916667$.

### 4. Tính tổng $S(n) =\frac{1}{2} + \frac{2}{3} ... + \frac{n}{n + 1}.$

```c++
float f(int n) {
    if(n == 0) return 2;
    if(n == 1) return 3;
    return 6*f(n - 1) - 9*f(n - 2);
}
```

* Bước 1: Base case xảy ra:
    Base case là khi $n$ == $0$ hàm trả về $2$ và khi $n == 1$ hàm trả về $3$

    ``` c++
    if(n == 0) return 2;
    if(n == 1) return 3;
    ```

* Bước 2: Kết quả của base case:
    Kết quả của base case là $f(0) = 2$.
    Kết quả của base case là $f(1) = 3$.

* Bước 3: Trước base case là trường hợp nào: là trường hợp trước khi đệ quy dừng
    Trường hợp $n == 2$ Kết quả của $f(2) = 0$.

* Bước 4: Trước bước 3 đúng **1** trường hợp thôi
    Trường hợp $n == 3$ Kết quả của $f(3) = -27$.
