# sfGUI

- **sfGUI** is an Immediate Mode GUI library built on top of the SFML ([Simple and Fast Multimedia Layer](https://www.sfml-dev.org/)) library.
- This is still a work in progress.

# Current status: ✅

# Change Logs:

### Beta Version 1.0.1:
- Refactored the Element, Transformable and Rectangle to use Element_Properties, Transformable_Properties and Rectangle_Properties respectively.
- Added Button (subclass of Rectangle).
- _A lot_ of debugging.

### Beta Version 1.0.0:
- Added abstract base class Element.
- Added Transformable (subclass of Div).
- Added Div (subclass of Transformable).
- Added Rectangle (subclass of Transformable).
- Wrote basic logic for adding elements inside a div and drawing the main div which also draws all its member elements.
- Wrote basic logic for all possible transformations on a rectangle with/without rounded corners.
- Optimized Rectangles to draw only necessary shapes (plain rectangle if radius == 0 or just a circle if radius == len / 2 and is square)

# Supported platforms:
- _Currently the only platform supported is **Linux** and a **system-wide install** of SFML is required to run this library._
- _Note:_ I will add support for other platforms after I am done with a prototype of the library. Until then... _works on my machine :)_
