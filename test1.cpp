#include <iostream>
#include <string>
using namespace std;
struct NodeTree{
    int id;
    string content;
    int left,right;
    int isLeaf;
}; 
NodeTree tree[100];
int n=0;
int root = 1;

void init(){
    root = 1;
    n=0;
    for(int i = 0;i<100;i++){
        tree[i].left = 0;
        tree[i].right = 0;
    }
}

void input(){
    cout << "Nhap so node: " << endl;
    cin >> n;
    cin.ignore();
    if (n <= 0 || n >= 100){
        cout << "So node khong hop le!\n";
        n = 0; return;
    }
    for(int i = 1;i<=n;i++){
        tree[i].id = i;
        cout << "Node " << i << endl;
        cout << "Nhap content: ";
        getline(cin,tree[i].content);
        tree[i].left = 2*i;
        tree[i].right = 2*i+1;

        if(tree[i].left >n)
            tree[i].left = 0;
        if(tree[i].right >n)
            tree[i].right = 0;
        if(tree[i].left == 0 && tree[i].right == 0)
            tree[i].isLeaf = 1;
        else
            tree[i].isLeaf = 0;
}
}
void loadSampleTree() {
    n = 7;
    root = 1;

    tree[1] = {1, "DTB < 2.0?", 2, 3, 0};
    tree[2] = {2, "No >= 12 tin chi?", 4, 5, 0};
    tree[3] = {3, "DTB >= 3.2?", 6, 7, 0};
    tree[4] = {4, "Canh bao hoc vu muc 2", 0, 0, 1};
    tree[5] = {5, "Canh bao hoc vu muc 1", 0, 0, 1};
    tree[6] = {6, "De xuat khen thuong", 0, 0, 1};
    tree[7] = {7, "Theo doi binh thuong", 0, 0, 1};

    cout << "Da nap cay mau!\n";
}
void printTree(int n){
    cout << "\nID\tContent\t\t\tLeft\tRight\tIsLeaf\n";

    for (int i = 1; i <= n; i++) {

        cout << tree[i].id << "\t"
            << tree[i].content << "\t\t"
            << tree[i].left << "\t"
            << tree[i].right << "\t"
            << tree[i].isLeaf << endl;
    }
}
int findNode(int id) {

    for (int i = 1; i <= n; i++) {

        if (tree[i].id == id)
            return i;
    }

    return 0;
}
void preorder(int p) {

    if (p == 0)

        return;

    cout << tree[p].content << " ";

    preorder(tree[p].left);

    preorder(tree[p].right);

}



void inorder(int p) {

    if (p == 0)

        return;

    inorder(tree[p].left);

    cout << tree[p].content << " ";

    inorder(tree[p].right);

}

void postorder(int p) {

    if (p == 0)

        return;

    postorder(tree[p].left);

    postorder(tree[p].right);

    cout << tree[p].content << " ";
}
bool findPath(int current, int targetId, int path[], int &len) {

    if (current == 0)
        return false;

    path[len++] = current;

    if (tree[current].id == targetId)
        return true;

    if (findPath(tree[current].left, targetId, path, len))
        return true;

    if (findPath(tree[current].right, targetId, path, len))
        return true;

    len--;

    return false;
}
void showPath() {

    int targetId;

    cout << "Nhap ID node can tim: ";
    cin >> targetId;

    int path[100];
    int len = 0;

    if (findPath(root, targetId, path, len)) {

        cout << "Duong di: ";

        for (int i = 0; i < len; i++) {

            cout << path[i];

            if (i < len - 1)
                cout << " -> ";
        }

        cout << endl;
    }
    else {
        cout << "Khong tim thay node!\n";
    }
}
    int height(int i) {

    if (i == 0)
        return 0;

    int hLeft = height(tree[i].left);
    int hRight = height(tree[i].right);

    return 1 + (hLeft > hRight ? hLeft : hRight);
}
    int countLeaves(int i) {

    if (i == 0)
        return 0;

    if (tree[i].left == 0 && tree[i].right == 0)
        return 1;

    return countLeaves(tree[i].left) + countLeaves(tree[i].right);
}
void runDecisionTree() {

    int current = root;
    char answer;

    while (current != 0 && tree[current].isLeaf == 0) {

        cout << "\n" << tree[current].content;
        cout << " (y/n): ";
        cin >> answer;

        if (answer == 'y' || answer == 'Y') {

            current = tree[current].left;

        }
        else if (answer == 'n' || answer == 'N') {

            current = tree[current].right;

        }
        else {
            cout << "Chi duoc nhap y hoac n!\n";
        }
    }

    if (current != 0) {
        cout << "\nKet luan: " << tree[current].content << endl;
    }
    else {
        cout << "\nDu lieu cay bi loi!\n";
    }
}
int main() {
    init();
    int choice;
    do {

        cout << "\n===== MENU CAY NHI PHAN =====\n";
        cout << "1. Khoi tao cay mau\n";
        cout << "2. Nhap cay\n";
        cout << "3. Hien thi cay\n";
        cout << "4. Duyet cay\n";
        cout << "5. Tim node\n";
        cout << "6. In duong di\n";
        cout << "7. Tinh chieu cao va dem node la\n";
        cout << "8. Mo phong tu van\n";
        cout << "0. Thoat\n";

        cout << "Nhap lua chon: ";
        cin >> choice;

        switch (choice) {

            case 1:
                loadSampleTree();
                break;

            case 2:
                init();
                input();
                break;

            case 3:
                printTree(n);
                break;

            case 4:
                cout << "\nPreorder (Tien tu): ";
                preorder(root);

                cout << "\nInorder (Trung tu): ";
                inorder(root);

                cout << "\nPostorder (Hau tu): ";
                postorder(root);

                cout << endl;

                break;

            case 5: {
                int id;
                cout << "Nhap ID node can tim: ";
                cin >> id;

                int pos = findNode(id);

                if (pos != 0) {
                    cout << "Tim thay node!\n";
                    cout << "Vi tri: " << pos << endl;
                    cout << "Content: " << tree[pos].content << endl;
                }
                else {
                    cout << "Khong tim thay node!\n";
                }
                break;
            }

            case 6:
                showPath();
                break;

            case 7:
                cout << "\nChieu cao cay: " << height(root) << endl;

                cout << "So node la: " << countLeaves(root) << endl;

                break;
            case 8:
                runDecisionTree();
                break;

            case 0:
                cout << "Ket thuc chuong trinh!\n";
                break;

            default:
                cout << "Lua chon khong hop le!\n";
        }

    } while (choice != 0);

    return 0;
}

