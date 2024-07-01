// 2ng July 2024
// Check if Linked List of Strings is Palindrome

/*
Given a linked list with string data, check whether the combined string formed is palindrome. If the combined string is palindrome then return true otherwise return false.

Example1:
    Input: 
        4
        b eeee b b
    Output: 
        False

Example2:
    Input: 
        5
        a bc de d cba
    Output: 
        True
*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    string data;
    Node *next;

    Node(string x) {
        data = x;
        next = NULL;
    }
};

Node *newNode(string str) {
    Node *new_node = new Node(str);
    new_node->next = NULL;
    return new_node;
}

void print(Node *root) {
    Node *temp = root;

    while (temp != NULL) {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

class Solution {
  public:
    bool isPalindrome(string str) {
        int i = 0, j = str.length() - 1;
        while(i < j)
            if(str[i++] != str[j--])
                return false;
        return true;
    }
    
    bool compute(Node* head) {
        string str = "";
        while(head) {
            str += head->data;
            head = head->next;
        }
        return isPalindrome(str);
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        int K;
        cin >> K;
        struct Node *head = NULL;
        struct Node *temp = head;

        for (int i = 0; i < K; i++) {
            string str = "";
            cin >> str;
            if (head == NULL)
                head = temp = new Node(str);
            else {
                temp->next = new Node(str);
                temp = temp->next;
            }
        }
        Solution ob;
        bool ans = ob.compute(head);
        if (ans)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
