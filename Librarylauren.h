#include <iostream>
#include <string>
#include <cstddef>

using namespace std;
#ifndef LIBRARY_LIBRARY_H
#define LIBRARY_LIBRARY_H

//creates a Book 
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

//creates a library using Books
class Library {
 public:
  Library();
  void add(Book);
  void check_in(Book);
  Book *check_out(Book);
  Book *search(Book);
  long available_copies(Book);

//constructs a BookNode that contains a Book
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

//Function: Constructs a Library
//Pre: Library class defined
//Post: root is constructed as nullptr in Library
Library::Library(){
		root = nullptr;
}

//Function: adds a Book object to the library
//Pre: Book, Library, and BookNode are initialized
//Post: void, but adds a Book to the libary (binary tree)
void Library::add(Book book){
  BookNode *target_book = search(book, root);
  if( target_book == nullptr){
	BookNode* book_nd = new BookNode(book);
	add(root, book_nd);
	}
	else{
		check_in(book);
	}
}

//Function: checks in a book to the library
//Pre: Library, and Book are initialized
//Post: increment the book count
void Library::check_in(Book book){
	BookNode *target_book = search(book, root);
	if(target_book != nullptr){
		target_book->count++;
	}
}

//Function: gets the available copy count for a book
//Pre: book is initialized
//Post: return count number of a book
long Library::available_copies(Book book){
	BookNode *target_book = search(book, root);
	if(target_book != nullptr){
		return target_book->count;
	}
	else{
		return 0;
	}
}

//Funtion: decrements Book count and returns a pointer to the Book
//Pre: Book is initialized
//Post: Book count is decremented, and a pointed to the book is returned
Book* Library::check_out(Book book){
	BookNode *target_book = search(book, root);
	if(target_book != nullptr){
		target_book->count--;
		return &target_book->value;
	}
	else{
		return nullptr;
	}
}

//Function: searches for a book in the library
//Pre: book is initialized
//Post: book pointer is returned
Book* Library::search(Book book){
	BookNode* found_bk = search(book, root);
	if(found_bk != nullptr){
		Book* val = &found_bk->value;
		return val;
	}
	else{
		return nullptr;
	}
}

//Function: adds a book to the library using BookNode in the correct position
//Pre: BookNode is initialized
//Post: Book is added to the library 
void Library::add(BookNode *&root, BookNode *&book_nd){
			if(root == nullptr){
				root = book_nd;
			}
			else if(book_nd < root){
				add(root->left, book_nd);
			}
			else if(root < book_nd){
				add(root->right, book_nd);
			}

}

//Function: Searches for a book in the library by searching BookNodes
//Pre: BookNode is initialized 
//Post: the found book is returned as its BookNode, not found nullptr returned 
Library::BookNode *Library::search(Book book, Library::BookNode* root){
		if(root == nullptr){
			return root;
		}
		
		while(root!= nullptr ){
			if(root->value == book){
				return root;
			}
			else if(book < root->value){
				root = root->left;
			}
			else if(root->value < book){
				root = root->right;
			}
		return root;
	}
		return nullptr;
}


#endif //LIBRARY_LIBRARY_H
