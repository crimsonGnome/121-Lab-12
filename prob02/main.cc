#include "bubble_jar.h"

int main() {
  // TODO: Update the creation of the BubbleJar to pass in a maximum age.
  BubbleJar jar;
  int maxAge = 150;
  jar.Initialize(maxAge);
  jar.Start();
  return 0;
}
