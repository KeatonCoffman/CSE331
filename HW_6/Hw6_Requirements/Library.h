//  Author: Keaton Coffman
//  11/3/16
//  CSE 331 
//  Homework 6


#include <iostream>
#include <string>
#include <cstddef>

using namespace std;
#ifndef LIBRARY_LIBRARY_H
#define LIBRARY_LIBRARY_H

struct Book {
	Book() = delete;
	Book(string _isbn, string _title, string _author) : isbn(_isbn), title(_title), author(_author) {};

	string isbn;
	string title;
	string author;

	bool operator<(const Book &other) { return isbn < other.isbn; };
	bool operator==(const Book &other) { return isbn == other.isbn; };
	bool operator!=(const Book &other) { return isbn != other.isbn; };

};

class Library {
	public:
		Library();
		void add(Book);
		void check_in(Book);
		Book *check_out(Book);
		Book *search(Book);
		long available_copies(Book);
		

	private:
		struct BookNode {
			Book value;
			BookNode *left;
			BookNode *right;
			size_t count = 1;
			BookNode(Book b) : value(b), left(nullptr), right(nullptr) {};
			
		};
		BookNode *root;
		void add(BookNode *&root_node, BookNode *&new_node);
		BookNode *search(Book, BookNode *root);
		
};
	
	
	
	Library::Library(){
		root = nullptr;
	}
	// Function: Add a booknode to the library binary tree
		// Pre: Library is initialized and has a root node
		// Post: If the root does not exist make the new node the root, if the node already exists tell the user
		//		 If the root is greater than the new node recursively call the add function using the left child and new node
		//		 	Else add the new node to the left child with no children
		//		 Else; If the right child of the root node exists recursively call the add function using the right child and new node
		//			Else add the new node as the left child with no children
	void Library::add(Library::BookNode *&root_node, Library::BookNode *&new_node) {
		if (root_node == nullptr) {
			root_node = new_node;
		}
		if (root_node->value == new_node->value) {
			root_node->count++;
		}
		if (new_node->value < root_node->value) {
			if (root_node->left != nullptr) {
				add(root_node->left, new_node);
			}
			else {
				root_node->left = new_node;
				(root_node->left)->left = nullptr;
				(root_node->left)->right = nullptr;
			}
		}
		else {
			if (root_node->right != nullptr) {
				add(root_node->right, new_node);
			}
			else {
				root_node->right = new_node;
				(root_node->right)->left = nullptr;
				(root_node->right)->right = nullptr;
			}
		}
		};
		
		// Function: Search the library for a book
		// Pre: Library is initialized and has a root node
		// Post: If the root is does not exist or the root value is equal to the key return the root node
		//		 If the root value is less than the key recursively call search on the right child and key
		//		 If the root value is greater than the key recursively call search on the left child and key
		Library::BookNode *Library::search(Book key, Library::BookNode *root) {
			if ((root == nullptr) || (root->value == key)){
				return root;
			}
			else if (root->value < key) {
				search(key,root->right);
			}
			else if (key < root->value) {
				search(key,root->left);
			}
		}

	
	
	// Function: Adds a new book to the library
	// Pre: Library is initialized and has a root node
	// Post: Create a new BookNode and then add it to the library using the add helper function
	void Library::add(Book new_book) {
		BookNode* book = new BookNode(new_book);
		add(root,book);
	};

	
	
	
	// Function: Check a book into the library
	// Pre: Library is initialized and has a root node
	// Post: A search is called to find the book, if the book is found increment book count, else add the book to the library
	void Library::check_in(Book book){
		BookNode* new_node = search(book,root);
		if (new_node->value == book) {
			new_node->count++;
		}
		else {
			add(book);
		}

	};
	
	

	// Function: Checks a book out of the library
	// Pre: Library is initialized and has a root node
	// Post: A search is called to find the book, if the book is found decrement book count else tell user the book is not in the library
	Book *Library::check_out(Book book) {
		BookNode* book_node = search(book,root);
		if (book_node->value == book) {
			book_node->count--;
			return &book_node->value;
		}
		else {
			cout << "There are no available copies because this book is not in the library" << endl;
			return 0;
		}
	};


	
	// Function: Find a book in the library
	// Pre: Library is initialized and has a root node
	// Post: Calls the helper search function
	Book *Library::search(Book book) {
		BookNode* key_book = search(book,root);
		if(key_book != nullptr)
			return &key_book->value;
		else{
			return nullptr;
		}
	};
	
	
	
	
	// Function: Searches the library for available copies
	// Pre: Library is initialized and has a root node
	// Post: Calls search to find the book, if the book is found increment count of book node else tell user no copies are available
	long Library::available_copies(Book book) {
		BookNode* book_node = search(book,root);
		if (book_node->value == book) {
			book_node->count++;
			return book_node->count;
		}
		else {
			cout << "There are no available copies in the library" << endl;
		}
	};
	
	


#endif //LIBRARY_LIBRARY_H
