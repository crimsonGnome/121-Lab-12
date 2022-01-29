// Name: Joseph Eggers
// CWID: 885939488
// Email: joseph.eggers@csu.fullerton.edu

#ifndef CAT_H
#define CAT_H

#include <memory>
#include <string>

using std::string;

class Cat {
 private:
  string name_;

 public:
  // Constructor
  Cat() = default;
  Cat(string name) { this->name_ = name; };

  // Destructor
  ~Cat();

  // Getter
  string GetName() const { return name_; };

  // Setter
  void SetName(string name) { this->name_ = name; };
};

std::unique_ptr<Cat> CreateKitty(string name);

#endif  // CAT_H
