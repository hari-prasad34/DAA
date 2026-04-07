#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;

// Node structure
struct Node {
    char data;
    int freq;
    Node *left, *right;

    Node(char data, int freq) {
        this->data = data;
        this->freq = freq;
        left = right = nullptr;
    }
};

// Comparator for priority queue (min heap)
struct compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};

// Function to print Huffman Codes
void printCodes(Node* root, string code) {
    if (!root)
        return;

    // If leaf node
    if (root->data != '$')
        cout << root->data << ": " << code << endl;

    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

// Build Huffman Tree
void HuffmanCodes(vector<char> data, vector<int> freq) {
    priority_queue<Node*, vector<Node*>, compare> pq;

    // Create leaf nodes and push into queue
    for (int i = 0; i < data.size(); i++) {
        pq.push(new Node(data[i], freq[i]));
    }

    // Build the tree
    while (pq.size() != 1) {
        Node *left = pq.top(); pq.pop();
        Node *right = pq.top(); pq.pop();

        Node *top = new Node('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        pq.push(top);
    }

    // Print Huffman Codes
    printCodes(pq.top(), "");
}

// Main function
int main() {
    vector<char> data = {'A', 'B', 'C', 'D', 'E', 'F'};
    vector<int> freq = {5, 9, 12, 13, 16, 45};

    HuffmanCodes(data, freq);

    return 0;
}
