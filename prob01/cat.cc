// Name: Joseph Eggers
// CWID: 885939488
// Email: joseph.eggers@csu.fullerton.edu

#include "cat.h"

// TODO: Implement Cat methods and CreateKitty function here.
#include <iostream>
#include <memory>
#include <string>

using std::string;

Cat::~Cat() { std::cout << name_ << " stalks away" << std::endl; }

std::unique_ptr<Cat> CreateKitty(string name) {
  std::unique_ptr<Cat> f(new Cat);
  f->SetName(name);
  return move(f);
}
