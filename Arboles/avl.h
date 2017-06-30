#include <functional>

template <typename T, T iniT=0> class AVLTree {
    struct Node {
        T e;
        Node *l, *r;
        int h;

        Node(T e = iniT,
             Node* l = nullptr,
             Node* r = nullptr)
            : e(e), l(l), r(r) {
            int hl = l == nullptr? -1 : l->h;
            int hr = r == nullptr? -1 : r->h;
            this->h = (hl > hr? hl : hr) + 1;
        }
    };
    int h(Node* n) {
        return n == nullptr? -1 : n->h;
    }
    void fixH(Node* n) {
        n->h = (h(n->l) > h(n->r)? h(n->l) : h(n->r)) + 1;
    }
    void deleteAll(Node* n) {
        if (n != nullptr) {
            deleteAll(n->l);
            deleteAll(n->r);
            delete n;
        }
    }
    void enOrden(Node* n)  {
        if (n != nullptr) {
            enOrden(n->l);
            proc(n->e);
            enOrden(n->r);
        }
    }
    void rotarIzq(Node*& x) {
        Node* y = x->r;      // 1
        x->r = y->l;         // 2
        y->l = x;            // 3
        x = y;               // 4
        fixH(x->l);
        fixH(x);
    }
    void rotarDer(Node*& y) {
        Node* x = y->l;      // 1
        y->l = x->r;         // 2
        x->r = y;            // 3
        y = x;               // 4
        fixH(y->r);
        fixH(y);
    }
    void balancear(Node*& n) {
        if (h(n->l) - h(n->r) > 1) {
            if (h(n->l->r) > h(n->l->l)) {
                rotarIzq(n->l);
            }
            rotarDer(n);
        } else if (h(n->r) - h(n->l) > 1) {
            if (h(n->r->l) > h(n->r->r)) {
                rotarDer(n->r);
            }
            rotarIzq(n);
        }
    }
    bool insertar(T e, Node*& n) {
        bool flag = false;
        if (n == nullptr) {
            n = new Node(e);
            ++len;
            return n != nullptr;
        } else if (cmp(e, n->e) < 0) {
            flag = insertar(e, n->l);
        } else {
            flag = insertar(e, n->r);
        }
        if (flag) {
            balancear(n);
            fixH(n);
        }
        return flag;
    }
public:
    AVLTree(std::function<void(T)> proc, std::function<int(T, T)> cmp)
        : root(nullptr), len(0), proc(proc), cmp(cmp) {}
    ~AVLTree()                 { deleteAll(root);                   }
    void enOrden()             { enOrden(root);                     }
    bool insertar(T e)         { return insertar(e, root);          }
    int size()                 { return len;                        }
    int height()               { return h(root);                    }
private:
    Node                      *root;
    int                       len;
    std::function<void(T)>    proc;
    std::function<int(T, T)>  cmp;
};
