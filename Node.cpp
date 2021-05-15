struct Node {
	char data;
	Node* left;
	Node* right;

	/*С лекции:
	root = new_Node(data);
	add(Node* node);
	add(data);
	*/

};

struct Tree {
	Node* root;
	/*С лекции:
	add(Node* node);
	add(data) {
		Node* node = new Node(data);
		if (root == None) {
			root = node;
		}
	}
	Node* current = root;
	while (1){
		if (current.data > data) {
			current = left;
		}
		else if (current.data < data) {
			current = right;
		}
		if (cuurent == None) {
			current = node;
		}
	}*/
};

Node* init() {
	Node* n = new Node();
	n->left;
	n->right;
	n->data;
	return n;
}

void insert(Node* node, char data) {
	if (node == nullptr) {
		node->data = data;
		node->left = init();
		node->right = init();
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