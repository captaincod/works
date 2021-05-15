#include <iostream>

struct Node {
	char data;
	Node* right;
	Node* left;

	Node() {
		data = NULL;
		right = nullptr;
		left = nullptr;
	}

};

struct Tree {
	Node* root;
};

void insert(Node* node, char data) {
	if (node->data == NULL) {
		node->data = data;
		node->left = new Node();
		node->right = new Node();
	}
	if (data <= node->data) {
		insert(node->left, data);
	}
	else {
		insert(node->right, data);
	}
}

Node* seek(Node* node, char data) {
	if (node == nullptr) {
		return nullptr;
	}
	if (data == node->data) {
		return node;
	}
	else if (data < node->data) {
		seek(node->left, data);
	}
	else {
		seek(node->right, data);
	}
}

Node* minimum(Node* node) {
	if (node->left == nullptr) {
		return node;
	}
	return minimum(node->left);
}

Node* remove(Node* node, char data) {
	if (node == nullptr) {
		return nullptr;
	}
	if (data < node->data) {
		node->left = remove(node->left, data);
	}
	else if (data > node->data) {
		node->right = remove(node->right, data);
	}
	else if (node->left != nullptr and node->right != nullptr) {
		node->data = minimum(node->right)->data;
		node->right = remove(node->right, data);
	}
	else {
		if (node->left != nullptr) {
			node = node->left;
		}
		else {
			node = node->right;
		}
	}
	return node;
}
