#include "main.h"
#include "Cache.h"

Cache::Cache(SearchEngine* s,ReplacementPolicy* r):rp(r),s_engine(s) {}
Cache::~Cache(){
	delete rp;
	delete s_engine;
}
Data* Cache::read(int addr) {
    return NULL;
}
Elem* Cache::put(int addr, Data* cont) {
    return NULL;
}
Elem* Cache::write(int addr, Data* cont) {
    return NULL;
}
void Cache::printRP() {
}
void Cache::printSE() {
}

void Node::inOrder() {
    cout << "Print AVL in inorder:\n";
    if (left) left->inOrder();
    el.print();
    if (right) right->inOrder();
}

void Node::preOrder() {
    cout << "\nPrint AVL in preorder:\n";
    el.print();
    if (left) left->preOrder();
    if (right) right->preOrder();
}

Node *AVL::rotateRight(Node *&node) {
    Node *temp = node->left;
    node->left = temp->right;
    temp->right = node;
    node = temp;
    return node;
}

Node *AVL::rotateLeft(Node *&node) {
    Node *temp = node->right;
    node->right = temp->left;
    temp->left = node;
    node = temp;
    return node;
}

Node *AVL::leftBalance(Node *&node, bool &taller) {
    if (node->left->balance == LH) {
        rotateRight(node);
        node->right->balance = EH;
    } else {
        rotateLeft(node->left);
        rotateRight(node);

        node->right->balance = node->balance == LH ? RH : EH;
        node->left->balance = node->balance == RH ? LH : EH;
    }
    node->balance = EH;
    taller = false;
    return node;
}

Node *AVL::rightBalance(Node *&node, bool &taller) {
    if (node->right->balance == RH) {
        rotateLeft(node);
        node->left->balance = EH;
    } else {
        rotateRight(node->right);
        rotateLeft(node);

        node->right->balance = node->balance == LH ? RH : EH;
        node->left->balance = node->balance == RH ? LH : EH;

    }
    node->balance = EH;
    taller = false;
    return node;
}

Node *AVL::removeLeftBalance(Node *&node, bool &shorter) {
    if (node->left->balance == RH) {
        rotateLeft(node->left);
        rotateRight(node);

        node->left->balance = node->balance == LH ? RH : EH;
        node->right->balance = node->balance == RH ? LH : EH;
        node->balance = EH;
    } else {
        if (node->left->balance == EH) {
            shorter = false;
        }
        rotateRight(node);
        node->right->balance = node->balance == LH ? EH : LH;
        node->balance = node->balance == LH ? EH : RH;
    }
    shorter = false;
    return node;
}

Node *AVL::removeRightBalance(Node *&node, bool &shorter) {
    if (node->right->balance == LH) {
        rotateRight(node->right);
        rotateLeft(node);

        node->left->balance = node->balance == RH ? LH : EH;
        node->right->balance = node->balance == LH ? RH : EH;
        node->balance = EH;
    } else {
        if (node->right->balance == EH) {
            shorter = false;
        }
        rotateLeft(node);
        node->left->balance = node->balance == RH ? EH : RH;
        node->balance = node->balance == RH ? EH : LH;
    }
    return node;
}

Node *AVL::insertRec(Node *&node, const Elem &value, bool &taller) {
    if (node == nullptr) {
        node = new Node(value);
        taller = true;
    } else {
        if (value.addr < node->el.addr) {
            insertRec(node->left, value, taller);

            if (taller) {
                if (node->balance == EH) {
                    node->balance = LH;
                } else if (node->balance == LH) {
                    leftBalance(node, taller);
                } else if (node->balance == RH) {
                    node->balance = EH;
                    taller = false;
                }
            }
        } else {
            insertRec(node->right, value, taller);
            if (taller) {
                if (node->balance == EH) {
                    node->balance = RH;
                } else if (node->balance == LH) {
                    node->balance = EH;
                    taller = false;
                } else if (node->balance == RH) {
                    rightBalance(node, taller);
                }
            }
        }
    }
    return node;
}

Node *AVL::removeRec(Node *&node, const int &addr, bool &shorter, bool &success) {
    if (node == nullptr) {
        shorter = false;
        success = false;
        return nullptr;
    }

    if (addr < node->el.addr) {
        removeRec(node->left, addr, shorter, success);
        if (shorter) {
            if (node->balance == LH) {
                node->balance = EH;
            } else if (node->balance == EH) {
                node->balance = RH;
                shorter = false;
            } else {
                removeRightBalance(node, shorter);
            }
        }
    } else if (addr > node->el.addr) {
        removeRec(node->right, addr, shorter, success);
        if (shorter) {
            if (node->balance == RH) {
                node->balance = EH;
            } else if (node->balance == EH) {
                node->balance = LH;
                shorter = false;
            } else {
                removeLeftBalance(node, shorter);
            }
        }
    } else {
        if (node->left == nullptr || node->right == nullptr) {
            Node *dltp = node;
            node = node->left? node->left : node->right;
            delete(dltp);
            shorter = true;
        } else {
            Node *dltp = node->left;
            while (dltp->right) {
                dltp = dltp->right;
            }
            node->el = dltp->el;
            removeRec(node->left, dltp->el.addr, shorter, success);
            if (shorter) {
                if (node->balance == LH) {
                    node->balance = EH;
                } else if (node->balance == EH) {
                    node->balance = RH;
                } else {
                    removeLeftBalance(node, shorter);
                }
            }
        }
        success = true;
    }
    return node;
}

Node *AVL::findUtility(Node *node, const int &key) {
    if (node == nullptr) {
        return nullptr;
    }
    if (key < node->el.addr) {
        return findUtility(node->left, key);
    } else if (key > node->el.addr) {
        return findUtility(node->right, key);
    } else {
        return node;
    }
}

Data *AVL::search(int key) {
    Node* ret = findUtility(this->root, key);
    if (ret != nullptr) {
        return ret->el.data;
    }
    return nullptr;
}

void AVL::insert(const Elem &value) {
    bool taller = false;
    this->insertRec(this->root, value, taller);
}

void AVL::deleteNode(int key) {
    bool shorter = false, success = false;
    this->removeRec(this->root, key, shorter, success);
}

void AVL::print(ReplacementPolicy *q) {
//    Chưa có ai chơi
}

void DBHashing::insert(const Elem &value) {
    int key = value.addr, i = 0;
    while (i < this->s) {
        int slot = (this->h1(key) + i*this->h2(key)) % this->s;
        if (this->HashTable[slot].status == NIL || this->HashTable[slot].status == DELETED) {
            this->HashTable[slot].data = value.data;
            this->HashTable[slot].status = NON_EMPTY;
        } else {
            i++;
        }
    }
}

void DBHashing::deleteNode(int key) {
    Data* ret = search(key);
    if (ret != nullptr) {
        
    }
}

Data *DBHashing::search(int key) {
    int i = 0, slot;
    do {
        slot = (this->h1(key) + i*this->h2(key)) % this->s;
        if (this->HashTable[slot].addr == key) {
            return this->HashTable[slot].data;
        }
        i++;
    } while (this->HashTable[slot].status == NIL && i < this->s);
    return nullptr;
}

void DBHashing::print(ReplacementPolicy *q) {
//    Chưa có ai chơi
}
