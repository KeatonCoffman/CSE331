//
// Created by Scott Swarthout on 10/4/16.
//
#include <iostream>
#include "Library.h"
using namespace std;

int main() {
  Library library;
  Book hamlet("978-0743477123", "Hamlet", "William Shakespeare");
  Book macbeth("978-0743477109", "Macbeth", "The Bard");
  library.add(hamlet);
  library.add(macbeth);
  auto num_left = library.available_copies(hamlet);
  cout << "Number of copies (Hamlet): " << num_left << endl;
  auto found = library.search(hamlet);
  cout << "Found book: " << found->isbn << found->author << endl;
  auto checked_out = library.check_out(*found);
  num_left = library.available_copies(hamlet);
  cout << "Checked out book: " << checked_out->isbn << checked_out->author << endl;
  cout << "Number of copies (Hamlet): " << num_left << endl;
  library.check_in(*checked_out);
  num_left = library.available_copies(hamlet);
  cout << "Number of copies (Hamlet): " << num_left << endl;
}

