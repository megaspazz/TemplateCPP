
template <typename T>
struct Matrix {
    int N, M;
    vector<vector<int>> A;

    Matrix(int rows, int cols) {
        N = rows;
        M = cols;
        A.resize(N);
        for (int i = 0; i < N; i++) {
            A[i].resize(M);
        }
    }

    int *operator[](int idx) {
        return &A[idx][0];
    }
};

/**
 * This almost definitely has memory leaks.
 * This also hasn't been thorougly tested yet.
 */
template <typename T>
struct LinkedList {
    struct Node {
        T data;
        Node *next;
        Node *prev;

        Node() { }

        Node(const T &val) {
            data = val;
        }

        void remove() {
            next->prev = prev;
            prev->next = next;
        }

        Node *insertBefore(T val) {
            Node *node = new Node(val);
            prev->next = node;
            node->prev = prev;
            node->next = this;
            prev = node;
            return node;
        }

        Node *insertAfter(T val) {
            Node *node = new Node(val);
            next->prev = node;
            node->next = next;
            node->prev = this;
            next = node;
            return node;
        }
    };

    Node *head, *tail;

    LinkedList() {
        head->next = tail;
        tail->prev = head;
    }

    Node *addHead(T val) {
        return head->insertAfter(val);
    }

    Node *addTail(T val) {
        return tail->insertBefore(val);
    }
};
