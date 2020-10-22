// 이중 연결 리스트로 구현한 큐

template <typename T>
class Node{
private:
    Node * next;
    Node * pre;
    T item;
public:
    Node(T item):item(item){
        next = pre = nullptr;
    }

    void setNext(Node * next){
        this->next = next;
    }

    void setPre(Node * pre){
        this->pre = pre;
    }

    Node * getNext(){
        return this->next;
    }

    Node * getPre(){
        return this->pre;
    }

    T getItem(){
        return this->item;
    }
};

template <typename T>
class Queue{
private:
    int num;
    Node<T> * head;
    Node<T> * tail;
public:
    Queue(){
        head = tail = nullptr;
        num = 0;
    }

    void push(T item){
        Node<T> * node = new Node<T>(item);
        if(tail == nullptr){
            head = tail = node;
        }else{
            tail->setNext(node);
            node->setPre(node);
            tail = node;
        }

        this->num++;
    }

    T pop(){
        if(head == nullptr) throw "Queue is Empty";
        Node<T> * node = head;
        T ret = head->getItem();
        if(head == tail){
            head = tail = nullptr;
        }else{
            head = head->getNext();
            head->setPre(nullptr);
        }

        delete node;

        this->num--;
        return ret;
    }

    int size(){
        return this->num;
    }

    bool isEmpty(){
        return this->num == 0;
    }

};