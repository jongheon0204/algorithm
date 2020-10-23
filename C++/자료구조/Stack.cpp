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
class Stack{
private:
    Node<T> * head;
    Node<T> * tail;
    int num;
public:
    Stack():num(0){
        head = tail = nullptr;
    }

    void push(T item){
        Node<T> * node = new Node(item);
        if(head == nullptr){
            head = tail = node;
        }else{
            tail->setNext(node);
            node->setPre(tail);
            tail = node;
        }
        this->num++;
    }

    T pop(){
        if(tail == nullptr) throw "Stack is Empty";
        T ret = tail->getItem();
        Node<T> * node = tail;
        if(head == tail){
            head = tail = nullptr;
        }else{
            tail = tail->getPre();
            tail->setNext(nullptr);
        }
        this->num--;
        delete node;
        return ret;
    }

    T top(){
        if(tail == nullptr) throw "top is Em[ty";
        return tail->getItem();
    }

    int size(){
        return this->num;
    }

    bool isEmpty(){
        return this->num == 0;
    }
};
