struct Mahasiswa {
    string nama;
    double ipk;
};

// Struktur Node
struct Node {
    Mahasiswa mhs;
    Node* next;
};

//[20.51, 8/6/2023] Muhamad Rofiq: 
void MyList::tambahBelakang(int databaru) {
    Node* baru = new Node;
    baru->data = databaru;
    baru->next = NULL;

    if (isEmpty()) {
        head = baru;
    } else {
        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = baru;
    }
}
//[20.52, 8/6/2023] Muhamad Rofiq:
void MyList::tambahBelakang(int databaru) {
    Node* baru = new Node;
    baru->data = databaru;
    baru->next = NULL;

    if (isEmpty()) {
        head = baru;
    } else {
        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = baru;
    }
}

void MyList::hapusDepan() {
    if (isEmpty()) {
        cout << "List kosong" << endl;
    } else {
        if (head->next == NULL) {
            delete head;
            head = NULL;
        } else {
            Node* hapus = head;
            head = head->next;
            delete hapus;
        }
    }
}
//[20.52, 8/6/2023] Muhamad Rofiq: void tukar(int& a, int& b, int& c) {
    if (a > b) {
        swap(a, b);
    }
    if (b > c) {
        swap(b, c);
    }
    if (a > b) {
        swap(a, b);
    }
}
//[20.53, 8/6/2023] Muhamad Rofiq: 
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    int a[N], b[N], c[N];
    for (int i = 0; i < N; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }

    int dpA[N], dpB[N], dpC[N];
    dpA[0] = a[0];
    dpB[0] = b[0];
    dpC[0] = c[0];

    for (int i = 1; i < N; i++) {
        dpA[i] = a[i] + max(dpB[i - 1], dpC[i - 1]);
        dpB[i] = b[i] + max(dpA[i - 1], dpC[i - 1]);
        dpC[i] = c[i] + max(dpA[i - 1], dpB[i - 1]);
    }

    int maksimumKebahagiaan = max({dpA[N - 1], dpB[N - 1], dpC[N - 1]});
    cout << maksimumKebahagiaan << endl;

    return 0;
}
//[20.53, 8/6/2023] Muhamad Rofiq:
#include <iostream>
#include <vector>
using namespace std;

int binarySearch(const vector<int>& arr, int target, int& iterations) {
 int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        }

        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }

        iterations++;
    }

    return -1;
}
//[21.02, 8/6/2023] Muhamad Rofiq:
#include <iostream>
#include <vector>

using namespace std;

pair<int, int> binary_search(vector<int>& A, int X) {
    int left = 0;
    int right = A.size() - 1;
    int count = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        count++;

        if (A[mid] == X) {
            return make_pair(mid, count);
        } else if (A[mid] < X) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return make_pair(-1, count);
}

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int X;
    cin >> X;

    pair<int, int> result = binary_search(A, X);

    cout << result.first << " " << result.second << endl;

    return 0;
}
