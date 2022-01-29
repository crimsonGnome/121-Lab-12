// Name: Joseph Eggers
// CWID: 885939488
// Email: joseph.eggers@csu.fullerton.edu

#ifndef BUBBLES_H
#define BUBBLES_H

#include "abstract_bubble.h"
#include "cpputils/graphics/image.h"

// TODO: Declare your BigBubble and SmallBubble classes here.

class BigBubble : public AbstractBubble {
 public:
  // Constructor
  BigBubble(int x, int y, graphics::Image* image_ptr);

  // Ovverride clasess from virtual class AbstractBubble
  int GetBubbleSize() override { return 20; };
};

class SmallBubble : public AbstractBubble {
 public:
  // Constructor
  SmallBubble(int x, int y, graphics::Image* image_ptr);

  // Ovverride clasess from virtual class AbstractBubble
  int GetBubbleSize() override { return 10; };
};

#endif  // BUBBLES_H
