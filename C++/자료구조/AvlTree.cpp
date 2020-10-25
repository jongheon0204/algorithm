#include <iostream>
#define max(a, b) ((a) > (b) ? (a) : (b))

template <class T>
class Node{
private:
    Node * right;
    Node * left;
    int height;
    T item;
public:
    Node(T item):item(item), height(0){
        right = left = nullptr;
    }

    void setRight(Node * right){
        this->right = right;
    }

    void setLeft(Node * left){
        this->left = left;
    }

    void setHeight(int height){
        this->height = height;
    }

    Node * getRight(){
        return this->right;
    }

    Node * getLeft(){
        return this->left;
    }

    int getHeight(){
        return this->height;
    }

    T getItem(){
        return this->item;
    }
};

template <class T>
class AVL{
private:
    Node<T> * root;
    int numOfNodes;

    int height(Node<T> * node){
        return node == nullptr ? 0 : node->getHeight();
    }

    // 왼쪽 자식 트리에 치우친 경우
    Node<T> * rightRotate(Node<T> * node){
        // 현재 노드의 왼쪽 자식
        Node<T> * left = node->getLeft();
        // 왼쪽 자식의 오른쪽 자식을 가져온다
        Node<T> * lRight = left->getRight();

        left->setRight(node);
        lRight->setLeft(lRight);

        left->setHeight(1 + max(height(left->getLeft()), height(left->getRight())));
        lRight->setHeight(1 + max(height(lRight->getLeft()), height(lRight->getRight())));

        return lRight;
    }

    Node<T> * leftRotate(Node<T> * node){
        // 현재 노드의 오른쪽 자식
        Node<T> * right = node->getRight();
        // 오른쪽 자식의 왼쪽 자식
        Node<T> * rLeft = right->getLeft();

        right->setLeft(node);
        node->setRight(rLeft);

        node->setHeight(1 + max(height(node->getLeft()), height(node->getRight())));
        right->setHeight(1 + max(height(right->getLeft()), height(right->getRight())));

        return right;
    }


    Node<T> * insert(Node<T> * node, T item){
        if(node == nullptr) return new Node(item);

        if(node->getItem() > item){
            node->setLeft(insert(node->getLeft(), item));
        }else if(node->getItem() < item){
            node->setRight(insert(node->getRight(), item));
        } // AVL에 이미 원소가 들어 있는 경우 별도로 변경할 필요 없다.
        else{
            return node;
        }

        // 현재 노드의 높이를 갱신
        node->setHeight(1 + max(height(node->getLeft()),  height(node->getRight())));

        // 왼쪽 서브트리 높이 - 오른쪽 서브트리 높이를 통해 한쪽으로 치우치는지 판단
        int bf = height(node->getLeft()) - height(node->getRight());

        // Left Left Case
        // 현재 추가된 데이터가 왼쪽 자식의 오른쪽 자식인지 왼쪽 자식의 왼쪽 자식인지에 따라 변환이 달라진다.
        if(bf > 1 && item < node->getLeft()->getItem()){
            return rightRotate(node);
        }

        // Right Right Case
        if(bf < -1 && item > node->getRight()->getItem()){
            return leftRotate(node);
        }

        // Left Right Case
        if(bf > 1 && item > node->getLeft()->getItem()){
            // Left Right Case를 Left Left Case로 바꿔준 후 계산
            node->setLeft(leftRotate(node->getLeft()));
            return rightRotate(node);
        }

        if(bf < -1 && item < node->getRight()->getItem()){
            node->setRight(rightRotate(node->getRight()));
            return leftRotate(node);
        }

        return node;
    }

    void inOrder(Node<T> * node){
        if(node == nullptr) return;
        inOrder(node->getLeft());
        std::cout<<node->getItem()<<' '<<node->getHeight()<<'\n';
        inOrder(node->getRight());
    }

public:
    AVL():numOfNodes(0), root(nullptr){}
    void insert(T item){
        this->root = insert(this->root, item);
        this->numOfNodes++;
    }

    void inOrder(){
        this->inOrder(this->root);
    }
};

int main(){
    AVL<int> avl;
    for(int i=0; i<10; i++){
        avl.insert(i);
        avl.insert(20-i);
        avl.inOrder();
    }
}