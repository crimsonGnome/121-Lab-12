// Name: Joseph Eggers
// CWID: 885939488
// Email: joseph.eggers@csu.fullerton.edu

#include <iostream>
#include <string>

#include "cat.h"
#include "human.h"

int main() {
  std::string name1;
  std::string name2;
  std::string cat_name;
  std::cout << "What is the first human's name? ";
  std::cin >> name1;

  std::cout << "What is the second human's name? ";
  std::cin >> name2;

  std::cout << "What is the cat's name? ";
  std::cin >> cat_name;
  std::cout << std::endl;

  // Use strings name1 and name2 to construct two Human objects and call
  // Human::Print() on both.
  Human person1(name1);
  Human person2(name2);

  person1.Print();
  person2.Print();

  // Use cat_name and the ``CreateKitty`` function to create a
  // unique pointer to a Cat.
  std::unique_ptr<Cat> cat = move(CreateKitty(cat_name));

  std::cout << "First human is adopting..." << std::endl;
  // Have the first Human Adopt the cat, then print the first and second
  // Humans.
  person1.Adopt(move(cat));

  // Print Humans
  person1.Print();
  person2.Print();

  std::cout << "First human is transferring to second human..." << std::endl;
  // Have the first Human Transfer their cat to the second Human, then
  // print the first and second Humans.

  Human* person2ptr;
  person2ptr = &person2;

  person1.TransferTo(person2ptr);

  // Print Humans
  person1.Print();
  person2.Print();

  return 0;
}
