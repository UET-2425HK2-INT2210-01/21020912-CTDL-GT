# Bảng băm với phương pháp xử lý va chạm

### Hàm băm: `h(i) = (2i + 5) mod 11`
Với các khóa: `[12, 44, 13, 88, 23, 94, 11, 39, 20, 16, 5]`

## a) Chaining (Nối)

- Với phương pháp chaining, các phần tử có cùng giá trị băm sẽ được lưu trữ trong danh sách liên kết tại mỗi vị trí. Dưới đây là bảng băm với các khóa được xử lý theo phương pháp này.

| Vị trí  | Giá trị |
|---------|---------|
| 0       |         |
| 1       | 20      |
| 2       |         |
| 3       |         |
| 4       | 16 -> 5 |
| 5       | 44 -> 88 -> 11 |
| 6       | 94 -> 39 |
| 7       | 12 -> 23 |
| 8       |         |
| 9       | 13      |
| 10      |         |

Giải thích:
- `h(12) = 7` => vị trí 7: 12
- `h(44) = 5` => vị trí 5: 44
- `h(13) = 9` => vị trí 9: 13
- `h(88) = 5` => vị trí 5: 88 (va chạm với 44)
- `h(23) = 7` => vị trí 7: 23 (va chạm với 12)
- `h(94) = 6` => vị trí 6: 94
- `h(11) = 5` => vị trí 5: 11 (va chạm với 44, 88)
- `h(39) = 6` => vị trí 6: 39 (va chạm với 94)
- `h(20) = 1` => vị trí 1: 20
- `h(16) = 4` => vị trí 4: 16
- `h(5) = 4` => vị trí 4: 5 (va chạm với 16)

---

## b) Linear Probing (Dò tuyến tính)

- Với phương pháp dò tuyến tính, nếu có va chạm tại một vị trí, ta sẽ kiểm tra các vị trí tiếp theo (theo thứ tự) cho đến khi tìm thấy một vị trí trống.

| Vị trí  | Giá trị |
|---------|---------|
| 0       |         |
| 1       | 20      |
| 2       |         |
| 3       |         |
| 4       | 16      |
| 5       | 44      |
| 6       | 94      |
| 7       | 12      |
| 8       | 23      |
| 9       | 13      |
| 10      | 88      |

Giải thích:
- `h(12) = 7` => vị trí 7: 12
- `h(44) = 5` => vị trí 5: 44
- `h(13) = 9` => vị trí 9: 13
- `h(88) = 5` => vị trí 5 đã đầy (va chạm với 44), kiểm tra vị trí 6 => vị trí 6: 88
- `h(23) = 7` => vị trí 7 đã đầy (va chạm với 12), kiểm tra vị trí 8 => vị trí 8: 23
- `h(94) = 6` => vị trí 6 đã đầy (va chạm với 88), kiểm tra vị trí 7 => vị trí 7 đã đầy (va chạm với 12), kiểm tra vị trí 8 => vị trí 8 đã đầy (va chạm với 23), kiểm tra vị trí 9 => vị trí 9 đã đầy (va chạm với 13), kiểm tra vị trí 10 => vị trí 10: 94
- `h(11) = 5` => vị trí 5 đã đầy (va chạm với 44), kiểm tra vị trí 6 => vị trí 6 đã đầy (va chạm với 88), kiểm tra vị trí 7 => vị trí 7 đã đầy (va chạm với 12), kiểm tra vị trí 8 => vị trí 8 đã đầy (va chạm với 23), kiểm tra vị trí 9 => vị trí 9 đã đầy (va chạm với 13), kiểm tra vị trí 10 => vị trí 10 đã đầy (va chạm với 94), kiểm tra vị trí 0 => vị trí 0: 11
- `h(39) = 6` => vị trí 6 đã đầy (va chạm với 94), kiểm tra vị trí 7 => vị trí 7 đã đầy (va chạm với 12), kiểm tra vị trí 8 => vị trí 8 đã đầy (va chạm với 23), kiểm tra vị trí 9 => vị trí 9 đã đầy (va chạm với 13), kiểm tra vị trí 10 => vị trí 10 đã đầy (va chạm với 94), kiểm tra vị trí 0 => vị trí 0 đã đầy (va chạm với 11), kiểm tra vị trí 1 => vị trí 1: 39
- `h(20) = 1` => vị trí 1: 20
- `h(16) = 4` => vị trí 4: 16
- `h(5) = 4` => vị trí 4 đã đầy (va chạm với 16), kiểm tra vị trí 5 => vị trí 5 đã đầy (va chạm với 44), kiểm tra vị trí 6 => vị trí 6 đã đầy (va chạm với 88), kiểm tra vị trí 7 => vị trí 7 đã đầy (va chạm với 12), kiểm tra vị trí 8 => vị trí 8 đã đầy (va chạm với 23), kiểm tra vị trí 9 => vị trí 9 đã đầy (va chạm với 13), kiểm tra vị trí 10 => vị trí 10 đã đầy (va chạm với 94), kiểm tra vị trí 0 => vị trí 0: 5

---

