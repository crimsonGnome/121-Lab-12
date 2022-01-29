// Name: Joseph Eggers
// CWID: 885939488
// Email: joseph.eggers@csu.fullerton.edu

#ifndef HUMAN_H
#define HUMAN_H

// TODO: Place your Human class here.

#include <memory>
#include <string>

#include "cat.h"

using std::string;

class Human {
 private:
  string name_;
  std::unique_ptr<Cat> cat_ = nullptr;

 public:
  // Constructor
  Human() = default;
  Human(string name) { this->name_ = name; };
  // Destructor
  ~Human();

  // Getter
  string GetName() const { return name_; };

  // Setter
  void SetName(string name) { this->name_ = name; };

  // memeber functions
  void Adopt(std::unique_ptr<Cat> cat);
  void TransferTo(Human* humanAdopter);
  void const Print();
};

#endif  // HUMAN_H
