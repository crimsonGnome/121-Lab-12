// Name: Joseph Eggers
// CWID: 885939488
// Email: joseph.eggers@csu.fullerton.edu

#include <vector>

#include "abstract_bubble.h"
#include "cpputils/graphics/image.h"

// TODO: Include any other necessary headers.

#ifndef BUBBLE_JAR_H
#define BUBBLE_JAR_H

// BubbleJar class exists but is incomplete. In bubble_jar.h you need to
// modify the Initialize function and add a few member variables.
class BubbleJar : public graphics::MouseEventListener,
                  public graphics::AnimationEventListener {
 public:
  // Clean-up.
  ~BubbleJar();

  // Set up state.
  // TODO: Update this function declaration per the instructions in the README.
  void Initialize(int maxAge);

  // Display the image.
  void Start();

  // Override from MouseEventListener
  void OnMouseEvent(const graphics::MouseEvent& event) override;

  // Override from AnimationEventListener
  void OnAnimationStep() override;

  // Used by unit tests to inspect the image.
  graphics::Image* GetImageForTesting() { return &image_; }

 private:
  graphics::Image image_;
  std::vector<std::unique_ptr<AbstractBubble>> abstractVector_;
  int maxAge_;
};

#endif  // BUBBLE_JAR_H
