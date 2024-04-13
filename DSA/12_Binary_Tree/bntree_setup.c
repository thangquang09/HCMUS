#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct Node{
    int data;
    struct Node* left; // luu dia chi node con ben trai
    struct Node* right; // luu dia chi node con ben phai
}Node;


/*
6
1 2 L 1 3 R 2 4 L 2 5 R 3 6 L 3 7 R

1 cạnh là u v c. Nếu c là R thì v là con phải của u
Nếu c là L thì v là con trái của u

Xây dựng cây nhị phân từ danh sách cạnh trên

*/
Node* makeNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insertNode(int data, Node* root) {
    if(!root) return;
    if(data < root->data) {
        // Nếu node bên trái là null thì tạo node
        if(root->left == NULL) {
            root->left = makeNode(data);
        }else {
        // Không thì tiếp tục tìm bên trái
            insertNode(data, root->left);
        }
    }else if(data > root->data) {
        // Nếu node con bên phải là null thì tạo node mới
        if(root->right == NULL) {
        // Không thì tiếp tục tìm bên phải
            root->right = makeNode(data);
        }else {
            insertNode(data, root->right);
        }
    }
}

// insert kiểu con trỏ
Node* insert(Node* root, int data) {
    if(!root) {
        return makeNode(data);
    }
    if(data < root->data) {
        root->left = insert(root->left, data);

    }else if(data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

/*
Thao tác xóa:
TH1: Node cần xóa không có con -> giải phóng node này
TH2: Node cần xóa có 1 con -> gán nó là con nó và giải phòng
    Node con
TH3: Node cần xó có đủ 2 con
    Bước 1: Tìm node con X nhỏ nhất lớn hơn Node cần xóa
    Bước 2: Gán giá trị Node cần xóa thành giá trị của node X
    Bước 3: Xóa node X ra khỏi cây
*/

// Ham minNode
// Ta chỉ cần đi sang phải và sau đó đi sang trái liên tục
// khi đến Node lá thì đó là Node nhỏ nhất lớn hơn Node cần xóa
Node* minNode(Node* root) {
    Node* tmp = root;
    while(tmp != NULL && tmp->left != NULL) {
        tmp = tmp->left;
    }
    return tmp;
}

Node* deleleNode(Node* root, int key) {
    if(!root) return root;
    if(key < root->data) {
        root->left = deleleNode(root->left, key);
    }
    else if(key > root->data) {
        root->right = deleleNode(root->right, key);
    }
    else {
        // key == root->data
        // không có con trái
        if(root->left == NULL) {
            Node* tmp = root->right;
            free(root);
            return tmp;
        }
        // không có con phải
        else if(root->right == NULL) {
            Node* tmp = root->left;
            free(root);
            return tmp;
        }
        // Còn lại
        else {
            Node* tmp = minNode(root->right);
            root->data = tmp->data;
            root->right = deleleNode(root->right, tmp->data);
        }
    }
    return root;
}

void duyet(Node* root) {
    if(!root) return;
    printf("%d ", root->data);
    duyet(root->left);
    duyet(root->right);
}

int main() {
    Node *root = NULL;
    int a[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(a) / sizeof(int);
    for(int i = 0; i < n; i++) {
        if(!root) {
            root = makeNode(a[i]);
        }else {
            insertNode(a[i], root);
        }
    }
    root = deleleNode(root,3);
    duyet(root);
    return 0;
}