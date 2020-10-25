#include <iostream>

template <typename T>
class Node{
private:
    Node * parent;
    Node * right;
    Node * left;
    T item;
public:
    Node(T item):item(item){
        parent = right = left = nullptr;
    }

    ~Node(){
        delete parent;
        delete right;
        delete left;
    }

    void setParent(Node * node){
        this->parent = node;
    }

    void setRight(Node * node){
        this->right = node;
    }

    void setLeft(Node * node){
        this->left = node;
    }

    Node * getParent(){
        return this->parent;
    }

    Node * getRight(){
        return this->right;
    }

    Node * getLeft(){
        return this->left;
    }

    T getItem(){
        return this->item;
    }
};

template <typename T>
class BinaryTree{
private:
    Node<T> * root;
    int nodeNum;

    bool search(Node<T> * cmp, const T & item){
        if(cmp == nullptr) return false;
        if(cmp->getItem() == item) return true;
        if(cmp->getItem() > item){
            return search(cmp->getLeft(), item);
        }else{
            return search(cmp->getRight(), item);
        }
    }

    void insert(Node<T> * cmp, Node<T> * node) {
        if(cmp->getItem() == node->getItem()) return;
        if (cmp->getItem() > node->getItem()) {
            if (cmp->getLeft() == nullptr) {
                cmp->setLeft(node);
                node->setParent(cmp);
            } else {
                insert(cmp->getLeft(), node);
            }
        } else {
            if (cmp->getRight() == nullptr) {
                cmp->setRight(node);
                node->setParent(cmp);
            } else {
                insert(cmp->getRight(), node);
            }
        }
    }

    Node<T> * findSubtree(Node<T> * node){
        if(node == nullptr) return nullptr;
        while(node->getLeft() != nullptr){
            node = node->getLeft();
        }
        return node;
    }

    bool erase(Node<T> * node, const T & item, int child){
        if(node->getItem() > item){
            return erase(node->getLeft(), item, 1);
        }else if(node->getItem() < item){
            return erase(node->getRight(), item, 2);
        }

        // 노드의 오른쪽, 왼쪽 자식 둘다 있는 경우
        if(node->getRight() != nullptr && node->getLeft() != nullptr){
            // 오른쪽 서브 트리에서 가장 값이 작은 노드를 가져온다
            Node<T> * replace = findSubtree(node->getRight());
            // 가장 작은 노드의 오른쪽, 왼쪽 자식, 부모를 다시 설정해 준다
            replace->getParent()->setLeft(nullptr);
            replace->setLeft(node->getLeft());
            replace->setRight(node->getRight());
            replace->setParent(node->getParent());

            // 현재 노드가 부모 노드의 위치에 따라 값이 정해진다
            // 1 : 왼쪽 자식
            // 2 : 오른쪽 자식
            // 0 : 현재 노드가 root 노드
            if(child == 1){
                node->getParent()->setLeft(replace);
            }else if(child == 2){
                node->getParent()->setRight(replace);
            }else{
                this->root = replace;
            }
        } // 오른쪽 서브 트리만 존재하는 경우
        else if(node->getRight() != nullptr){
            node->getRight()->setParent(node->getParent());
            if(child == 1){
                node->getParent()->setLeft(node->getRight());
            }else if(child == 2){
                node->getParent()->setRight(node->getRight());
            }else{
                this->root = node->getRight();
            }
        } // 왼쪽 서브 트리만 존재하는 경우
        else if(node->getLeft() != nullptr){
            node->getLeft()->setParent(node->getParent());
            if(child == 1){
                node->getParent()->setLeft(node->getLeft());
            }else if(child == 2){
                node->getParent()->setRight(node->getLeft());
            }else{
                this->root = node->getLeft();
            }
        } // 자식이 존재하지 않는 경우
        else{
            if(child == 1){
                node->getParent()->setLeft(nullptr);
            }else if(child == 2){
                node->getParent()->setRight(nullptr);
            }else{
                this->root = nullptr;
            }
        }

        return true;
    }

    void inOrder(Node<T> * node){
        if(node == nullptr) return;
        preOrder(node->getLeft());
        std::cout<<node->getItem()<<' ';
        preOrder(node->getRight());
    }

    void preOrder(Node<T> * node){
        if(node == nullptr) return;
        std::cout<<node->getItem()<<' ';
        inOrder(node->getLeft());
        inOrder(node->getRight());
    }

    void postOrder(Node<T> * node){
        if(node == nullptr) return;
        postOrder(node->getLeft());
        postOrder(node->getRight());
        std::cout<<node->getItem()<<' ';
    }

public:
    BinaryTree():nodeNum(0), root(nullptr){}

    bool search(T item){
        return this->search(root, item);
    }

    void insert(T item){
        Node<T> * node = new Node(item);
        if(this->root == nullptr){
            root = node;
        }else{
            this->insert(root, node);
        }
        this->nodeNum++;
    }

    // 원소 제거
    bool erase(T item){
        if(!this->search(item)) return false;
        this->erase(this->root, item, 0);
        this->nodeNum--;
        return true;
    }

    // 전위 탐색
    void preOrder(){
        this->preOrder(this->root);
    }

    // 중위 탐색
    void inOrder(){
        this->inOrder(this->root);
    }

    // 후위 탐색
    void postOrder(){
        this->postOrder(this->root);
    }
};