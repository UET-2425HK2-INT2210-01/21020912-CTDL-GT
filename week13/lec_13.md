# Bài 1: Kiểm tra biểu thức chính quy `/\<[^>]+\>/`

Biểu thức chính quy `/\<[^>]+\>/` sẽ khớp với bất kỳ chuỗi nào có dạng:

- Bắt đầu bằng dấu `<`
- Theo sau là **một hoặc nhiều ký tự không phải là `>`**
- Kết thúc bằng dấu `>`

## Phân tích từng trường hợp:

### 1. `<an xml tag>`
✅ **Khớp** – Bên trong cặp dấu `< >` là chuỗi ký tự `"an xml tag"` không chứa `>`, vì vậy biểu thức phù hợp.

### 2. `<opentag> <closetag>`
✅ **Khớp hai lần** – Cả hai chuỗi `<opentag>` và `<closetag>` đều khớp với biểu thức chính quy.

### 3. `</closetag>`
✅ **Khớp** – Dấu gạch chéo `/` được phép trong chuỗi (vì nó không phải là `>`), nên biểu thức này khớp.

### 4. `<>`
❌ **Không khớp** – Không có ký tự nào giữa `<` và `>`, trong khi biểu thức yêu cầu **ít nhất một ký tự** giữa chúng (`+`).

### 5. `<with attribute=”77”>`
✅ **Khớp** – Bên trong dấu `< >` có chứa các ký tự và không chứa `>`, nên biểu thức khớp.

## ✅ Kết luận:
Các trường hợp **khớp** với biểu thức chính quy:

- Trường hợp 1
- Trường hợp 2
- Trường hợp 3
- Trường hợp 5

Trường hợp **không khớp**:

- Trường hợp 4
# Bài 2: Kiểm tra biểu thức chính quy `/a.[bc]+/`

Biểu thức chính quy `/a.[bc]+/` khớp với chuỗi có dạng:

- Bắt đầu bằng ký tự `a`
- Tiếp theo là **một ký tự bất kỳ** (dấu `.` đại diện cho bất kỳ ký tự nào, trừ dòng mới)
- Sau đó là **ít nhất một ký tự thuộc tập `b` hoặc `c`** (tức `[bc]+`)

---

## Phân tích từng trường hợp:

### 1. `abc`
✅ **Khớp**  
Giải thích: `a` + `b` (ký tự bất kỳ) + `c` (trong `[bc]+`)

---

### 2. `abbbbbbbb`
✅ **Khớp**  
Giải thích: `a` + `b` (ký tự bất kỳ) + `bbbbbbb` (chuỗi `b` nằm trong `[bc]+`)

---

### 3. `azc`
✅ **Khớp**  
Giải thích: `a` + `z` (ký tự bất kỳ) + `c` (nằm trong `[bc]+`)

---

### 4. `abcbcbcbc`
✅ **Khớp**  
Giải thích: `a` + `b` (ký tự bất kỳ) + `cbcbcbc` (toàn bộ đều là `b` hoặc `c`)

---

### 5. `ac`
❌ **Không khớp**  
Giải thích: `a` + `c` (là ký tự bất kỳ), **nhưng sau đó không còn ký tự nào** để phù hợp với `[bc]+` → **không đủ điều kiện**

---

### 6. `azccbbbbcbccc`
✅ **Khớp**  
Giải thích: `a` + `z` (ký tự bất kỳ) + `ccbbbbcbccc` (tất cả đều là `b` hoặc `c`)

---

## ✅ Kết luận:
Các chuỗi **khớp** với biểu thức `/a.[bc]+/`:

- Trường hợp 1: `abc`
- Trường hợp 2: `abbbbbbbb`
- Trường hợp 3: `azc`
- Trường hợp 4: `abcbcbcbc`
- Trường hợp 6: `azccbbbbcbccc`

Chuỗi **không khớp**:

- Trường hợp 5: `ac`

# Bài 3: Kiểm tra biểu thức chính quy `/ (very )+(fat)?(tall|ugly) man /`

## Mô tả biểu thức:

Biểu thức chính quy này sẽ khớp với chuỗi có cấu trúc như sau:

- `(very )+` → **Ít nhất một lần** xuất hiện của từ `"very "`  
- `(fat)?` → Từ `"fat"` là **tùy chọn** (có thể có hoặc không)  
- `(tall|ugly)` → Một trong hai từ `"tall"` hoặc `"ugly"`  
- `" man"` → Kết thúc bằng từ `"man"` có khoảng trắng phía trước

---

## Phân tích từng trường hợp:

### 1. `very fat man`
❌ **Không khớp**  
- `"very"` ✅  
- `"fat"` ✅  
- **Thiếu** `"tall"` hoặc `"ugly"` → **không thỏa `(tall|ugly)`**

---

### 2. `fat tall man`
❌ **Không khớp**  
- Không có `"very "` → **không thỏa** điều kiện bắt buộc `(very )+`

---

### 3. `very very fat ugly man`
✅ **Khớp**  
- `"very very"` ✅  
- `"fat"` ✅  
- `"ugly"` ✅  
- `"man"` ✅  
→ Toàn bộ chuỗi khớp với biểu thức

---

### 4. `very very very tall man`
✅ **Khớp**  
- `"very very very"` ✅  
- Không có `"fat"` → vẫn hợp lệ vì `(fat)?` là tùy chọn  
- `"tall"` ✅  
- `"man"` ✅  
→ Toàn bộ chuỗi hợp lệ

---

## ✅ Kết luận:

### Các chuỗi **khớp** với biểu thức:

- Trường hợp 3: `very very fat ugly man`
- Trường hợp 4: `very very very tall man`

### Các chuỗi **không khớp**:

- Trường hợp 1: `very fat man` (thiếu `tall` hoặc `ugly`)
- Trường hợp 2: `fat tall man` (thiếu từ `very` ở đầu)

# Bài Biểu thức chính quy cho chuỗi dạng `abc.def.ghi.jkx`

## Yêu cầu:

- Chuỗi có 4 nhóm ký tự, mỗi nhóm đúng 3 ký tự (tương ứng `abc`, `def`, `ghi`, `jkx`)
- Các ký tự trong nhóm có thể là **bất kỳ ký tự nào trừ newline**
- Các nhóm được **ngăn cách bởi dấu chấm thực sự (`.`)**
- Chuỗi phải **đúng độ dài** và **không có ký tự thừa**

---

## Biểu thức chính quy:

```regex
^...\....\....\...$
```
# Bài 5: Biểu thức chính quy khớp số 

## Các định dạng cần khớp:

- (123) 456 7899  
- (123).456.7899  
- (123)-456-7899  
- 123-456-7899  
- 123 456 7899  
- 1234567899

---

## Biểu thức chính quy:

```regex
^(\(\d{3}\)|\d{3})[ .-]?\d{3}[ .-]?\d{4}$
```
# Biểu thức chính quy kiểm tra chuỗi hợp lệ

## Yêu cầu:

- Chuỗi gồm các ký tự:  
  - Số (`0-9`)  
  - Chữ thường (`a-z`)  
  - Chữ hoa (`A-Z`)  
- Các ký tự phân cách hợp lệ:  
  - Dấu gạch ngang (`-`)  
  - Dấu gạch dưới (`_`)  
  - Dấu cách (` `)  
- Không được có hai ký tự phân cách liên tiếp  
- Không được có ký tự phân cách ở đầu hoặc cuối chuỗi

---

## Biểu thức chính quy:

```regex
^[a-zA-Z0-9]+([ _-][a-zA-Z0-9]+)*$
```