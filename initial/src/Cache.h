#ifndef CACHE_H
#define CACHE_H

#include "main.h"


class ReplacementPolicy {
protected:
	int count;
	Elem** arr;
	
public:
	virtual int insert(Elem* e) = 0; //insert e into arr[idx] if idx != -1 else into the position by replacement policy
	virtual void access(int idx) = 0; //idx is index in the cache of the accessed element
	virtual int remove() = 0; 
	virtual void print() = 0;
    virtual Elem* peek() = 0;
	
	bool isFull() {
	    return count == MAXSIZE;
	}
	bool isEmpty() {
	    return count == 0;
	}
	Elem* getValue(int idx){
	    return arr[idx];
	}
	void replace(int idx, Elem* e) {
		delete arr[idx];
		access(idx);
		arr[idx] = e;
	}
};

class SearchEngine {
	public:
	virtual Elem* search(int key) = 0; // nullptr if not found
    virtual void insert(Elem *value) = 0;
	virtual	void deleteNode(int key) = 0;
	virtual void print(ReplacementPolicy* r) = 0;
};

class FIFO : public ReplacementPolicy {
private:
    int front, rear, capacity;
public:
	FIFO() {
	    count = 0;
	    arr = new Elem*[MAXSIZE];
	    this->capacity = MAXSIZE;
	    this->front = 0;
        this->rear = -1;
	}
	~FIFO() {}
	int insert(Elem* e);
	void access(int idx);
	int remove();
	void print();
    Elem* peek();
};

class MRU : public ReplacementPolicy {
public:
	MRU() {
	    count = 0;
	    arr = new Elem* [MAXSIZE];
	}
	~MRU(){}

	int findIndexByAddr(int addr);

	int insert(Elem* e);
	void access(int idx);
	int remove();
	void print();
    Elem* peek();
};
class LRU: public MRU {
public:
	int remove() override;
    Elem* peek() override;
};

class LFU: public ReplacementPolicy {
public:
	LFU(){}
	~LFU(){}
	int insert(Elem* e){return 0;}
	void access(int idx){}
	int remove(){return 0;}
	void print(){}
    Elem* peek(){return nullptr;}
};

enum STATUS_TYPE { NIL, NON_EMPTY, DELETED };
class HashNode {
public:
    int addr;
    STATUS_TYPE status;
    Elem* data;

    HashNode() {};
    ~HashNode() {};
};

class DBHashing: public SearchEngine {
private:
    HashNode* HashTable;

    int (*h1)(int);
    int (*h2)(int);
    int s;

public:
	DBHashing(int (*h1)(int),int (*h2)(int),int s) {
	    this->h1 = h1;
	    this->h2 = h2;
	    this->s = s;
	    this->HashTable = new HashNode[s];
	}
	~DBHashing(){}

    void insert(Elem *value);
	void deleteNode(int key);
	void print(ReplacementPolicy* q);
    Elem* search(int key);
};

enum BalanceValue {
    LH = -1,
    EH = 0,
    RH = 1
};

class Node {
public:
    Elem * el;
    Node *left;
    Node *right;
    BalanceValue balance;

    Node(Elem *val): el(val), left(nullptr), right(nullptr), balance(EH) {};
    void inOrder();
    void preOrder();
};

class AVL : public SearchEngine {
public:
    Node *root;
protected:
    Node *rotateRight(Node *&node);
    Node *rotateLeft(Node *&node);
    Node *leftBalance(Node *&node, bool &taller);
    Node *rightBalance(Node *&node, bool &taller);
    Node *removeLeftBalance(Node *&node, bool &shorter);
    Node *removeRightBalance(Node *&node, bool &shorter);
    Node *insertRec(Node *&node, Elem *value, bool &taller);
    Node *removeRec(Node *&node, const int &addr, bool &shorter, bool &success);

    Node* findUtility(Node* node, const int &key);
//    Node* insertUtility(const Elem &value);
//    Node* deleteUtility(const int &key);
public:
    AVL() {
        root = nullptr;
    }
    ~AVL() {}
    void insert(Elem *value);
    void deleteNode(int key);
    void print(ReplacementPolicy* q);
    Elem* search(int key);
};

#endif