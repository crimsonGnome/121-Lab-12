// Name: Joseph Eggers
// CWID: 885939488
// Email: joseph.eggers@csu.fullerton.edu

#include "human.h"

#include <iostream>

#include "cat.h"

using std::cout, std::endl;

Human::~Human() { cout << name_ << " walks away" << endl; }

void Human::Adopt(std::unique_ptr<Cat> cat) { this->cat_ = move(cat); }

void Human::TransferTo(Human* humanAdopter) {
  std::unique_ptr<Cat> cat = move(cat_);
  humanAdopter->Adopt(move(cat));
}

void const Human::Print() {
  if (cat_ == nullptr) {
    cout << name_ << " is a human with no cat" << endl;
  } else {
    cout << name_ << " is a human with a cat named " << cat_->GetName() << endl;
  }
}
