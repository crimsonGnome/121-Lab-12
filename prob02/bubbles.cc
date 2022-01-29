// Name: Joseph Eggers
// CWID: 885939488
// Email: joseph.eggers@csu.fullerton.edu

// TODO: Provide implementation of methods from bubbles.h if necessary.

#include "bubbles.h"

#include "abstract_bubble.h"
#include "cpputils/graphics/image.h"

BigBubble::BigBubble(int x, int y, graphics::Image* image_ptr)
    : AbstractBubble(x, y, image_ptr) {}

SmallBubble::SmallBubble(int x, int y, graphics::Image* image_ptr)
    : AbstractBubble(x, y, image_ptr) {}
