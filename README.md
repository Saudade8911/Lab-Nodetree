Cây nhị phân dạng mảng

1. Giới thiệu

Chương trình cài đặt cây nhị phân bằng mảng trong C++.

Mỗi node được lưu trong mảng tree[100], trong đó:

id: mã của node.

content: nội dung câu hỏi hoặc kết luận.

left: chỉ số node con bên trái.

right: chỉ số node con bên phải.

isLeaf: xác định node có phải node lá hay không.

0: node quyết định.

1: node lá/kết luận.

Quy ước:

root = 1: node gốc có chỉ số 1.

0: không có node con.

Chương trình mô phỏng một cây quyết định hỗ trợ cảnh báo học vụ cho sinh viên.

2. Cấu trúc dữ liệu

struct NodeTree {
    int id;
    string content;
    int left, right;
    int isLeaf;
};

NodeTree tree[100];

int n = 0;
int root = 1;

Cây mẫu gồm 7 node:

             1
           /   \
          2     3
         / \   / \
        4   5 6   7

Trong đó:

Node 1: DTB < 2.0?

Node 2: No >= 12 tin chi?

Node 3: DTB >= 3.2?

Node 4: Canh bao hoc vu muc 2

Node 5: Canh bao hoc vu muc 1

Node 6: De xuat khen thuong

Node 7: Theo doi binh thuong

3. Các chức năng

1. Khởi tạo cây mẫu

Nạp cây quyết định mẫu gồm 7 node.

1. Khoi tao cay mau

2. Nhập cây

Cho phép nhập số node và nội dung của từng node.

Chương trình tự xác định left, right theo vị trí mảng và xác định isLeaf.

2. Nhap cay

3. Hiển thị cây

In bảng gồm:

ID | Content | Left | Right | IsLeaf

3. Hien thi cay

4. Duyệt cây

Thực hiện 3 phép duyệt:

Preorder (tiền tự)

Inorder (trung tự)

Postorder (hậu tự)

4. Duyet cay

5. Tìm node

Tìm node dựa trên id.

Nếu tìm thấy, chương trình hiển thị vị trí và nội dung node.

5. Tim node

6. In đường đi

Tìm và in đường đi từ node gốc đến node cần tìm.

Chương trình sử dụng hàm đệ quy findPath() và mảng path[].

Ví dụ:

Duong di: 1 -> 2 -> 5

6. In duong di

7. Thống kê

Tính:

Chiều cao cây.

Số node lá.

7. Tinh chieu cao va dem node la

Với cây mẫu:

Chieu cao cay: 3
So node la: 4

8. Mô phỏng tư vấn học vụ

Chương trình đi từ node gốc xuống các node con dựa trên câu trả lời:

y / Y: đi sang left.

n / N: đi sang right.

Khi đến node lá, chương trình đưa ra kết luận.

8. Mo phong tu van

4. Các hàm chính

Hàm

Chức năng

init()

Khởi tạo cây

input()

Nhập cây

loadSampleTree()

Nạp cây mẫu 7 node

printTree()

Hiển thị bảng cây

preorder()

Duyệt tiền tự

inorder()

Duyệt trung tự

postorder()

Duyệt hậu tự

findNode()

Tìm node theo ID

findPath()

Tìm đường đi từ gốc

showPath()

In đường đi

height()

Tính chiều cao cây

countLeaves()

Đếm node lá

runDecisionTree()

Mô phỏng tư vấn học vụ

5. Cách chạy chương trình

Biên dịch chương trình bằng trình biên dịch C++ như:

Code::Blocks

Dev-C++

Visual Studio

GCC/G++

Sau khi chạy, menu chính xuất hiện:

===== MENU CAY NHI PHAN =====
1. Khoi tao cay mau
2. Nhap cay
3. Hien thi cay
4. Duyet cay
5. Tim node
6. In duong di
7. Tinh chieu cao va dem node la
8. Mo phong tu van
0. Thoat

6. Kiểm thử

Test 1: Nạp cây mẫu

Chọn:

1

Kết quả: cây gồm 7 node được nạp.

Test 2: Duyệt tiền tự

Chọn:

1
4

Kết quả thứ tự ID:

1 2 4 5 3 6 7

Test 3: Tìm đường đi đến node 5

Chọn:

1
6
5

Kết quả:

Duong di: 1 -> 2 -> 5

Test 4: Tính chiều cao và số node lá

Chọn:

1
7

Kết quả:

Chieu cao cay: 3
So node la: 4

Test 5: Mô phỏng tư vấn

Chọn:

1
8

Sau đó trả lời y hoặc n theo từng câu hỏi.

Ví dụ:

DTB < 2.0? (y/n): y
No >= 12 tin chi? (y/n): n

Ket luan: Canh bao hoc vu muc 1

7. Ví dụ kết quả cây mẫu

Bảng cây:

ID    Content                     Left    Right    IsLeaf
1     DTB < 2.0?                 2       3        0
2     No >= 12 tin chi?          4       5        0
3     DTB >= 3.2?                6       7        0
4     Canh bao hoc vu muc 2      0       0        1
5     Canh bao hoc vu muc 1      0       0        1
6     De xuat khen thuong        0       0        1
7     Theo doi binh thuong       0       0        1

8. Đặc điểm của chương trình

Sử dụng mảng để lưu cây.

left và right lưu chỉ số node con, không sử dụng con trỏ động.

Sử dụng đệ quy cho các phép duyệt cây, tìm đường đi, tính chiều cao và đếm node lá.

Có menu để kiểm thử từng chức năng.

Có cây mẫu 7 node để kiểm thử nhanh.

Có chức năng mô phỏng cây quyết định trong bài toán tư vấn học vụ.

9. Tác giả

Họ tên: Phạm Tùng Lâm - A52505

Lớp: TC3801

Môn: Cấu trúc dữ liệu và giải thuật

Bài thực hành: Cây nhị phân dạng mảng
