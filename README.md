# BitmapPhotoCreator
The basics to create a bitmap image with examples of what can be created.

You can create a Bitmap image with the constructor:
  Bitmap(width_you_want_image_to_be, height_you_want_image_to_be);

The Bitmap class has a method called setPixles, which is what needs to be called when setting pixels at desired locations:
  bitmapClassObject.setPixels(x-coord, y-coord, red, green, blue);

You can loop through each pixel and set the red, green, and blue values to the desired color as you pass over the pixel.
This is similar to the fractal generator, but I was wanting something that is a stand-alone bitmap creator.  So these files are
all that is needed in order to create a bitmap and you can programatically set each pixel.  It's really fun and I recommend
everyone to check it out.

I included some examples of things to draw, but there are many more possibilities to what can be created.
