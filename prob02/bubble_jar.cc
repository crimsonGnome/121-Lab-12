#include "bubble_jar.h"

#include <iostream>

#include "abstract_bubble.h"
#include "bubbles.h"

// Some helpful constants.
const int kSize = 300;
const graphics::Color kWhite(255, 255, 255);

BubbleJar::~BubbleJar() {
  // Clean up state. You do not need to make changes.
  image_.RemoveMouseEventListener(*this);
  image_.RemoveAnimationEventListener(*this);
}

void BubbleJar::Initialize(int maxAge) {
  this->maxAge_ = maxAge;
  image_.Initialize(kSize, kSize);
  image_.AddAnimationEventListener(*this);
  image_.AddMouseEventListener(*this);
}

void BubbleJar::Start() {
  // Displays the BubbleJar. Feel free to rename the image.
  image_.ShowUntilClosed("Bubble Jar");
}

void BubbleJar::OnMouseEvent(const graphics::MouseEvent& event) {
  std::cout << "BubbleJar got a MouseEvent" << std::endl;
  // TODO: Create a BigBubble on mouse press and a SmallBubble on mouse release
  // and add them to the vector.

  graphics::Image* image = GetImageForTesting();
  if (event.GetMouseAction() == graphics::MouseAction::kPressed) {
    // Create the abstract Bubble pointer
    std::unique_ptr<AbstractBubble> x(
        new BigBubble(event.GetX(), event.GetY(), image));
    abstractVector_.push_back(move(x));

    // Draw Image
    int lastVec = abstractVector_.size() - 1;
    abstractVector_[lastVec]->Draw();
  } else if (event.GetMouseAction() == graphics::MouseAction::kReleased) {
    // Create the abstract Bubble pointer
    std::unique_ptr<AbstractBubble> y(
        new SmallBubble(event.GetX(), event.GetY(), image));
    abstractVector_.push_back(move(y));

    // Draw Image
    int lastVec = abstractVector_.size() - 1;
    abstractVector_[lastVec]->Draw();
  }
  // Flush
  image->Flush();
}

void BubbleJar::OnAnimationStep() {
  std::cout << "BubbleJar got an animation step" << std::endl;
  // TODO: Update all the bubbles, making sure to remove the old ones
  // from the vector when they get above the maximum age.
  //
  graphics::Image* image = GetImageForTesting();
  image->DrawRectangle(0, 0, image->GetWidth(), image->GetHeight(), 255, 255,
                       255);

  // Draw Image
  for (size_t i = 0; i < abstractVector_.size(); i++) {
    if (abstractVector_[i]->GetAge() >= maxAge_) {
      abstractVector_.erase(abstractVector_.begin() + i);
      i--;
    } else {
      abstractVector_[i]->Move();
      abstractVector_[i]->Draw();
    }
  }
  image->Flush();
}
