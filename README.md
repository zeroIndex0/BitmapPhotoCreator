# BitmapPhotoCreator

I used Code::Blocks 16.01 with the default complier to create this program.

This program is, hopefully, simple to set up.  You just need to put all the files in this repository into a folder and
link those files with whatever compiler you are using and then build and run the project.  In my case, I create an empty project in
codeblocks and then add the files from this repository to the project, then select build and run. You will then see a "test.bmp"
image which is the output of the drawing code in main.cpp.  You can then change those loops to whatever you want and create your 
own images.  If you have any questions getting this set up, feel free to ask and I will do my best to assit you in getting this
program running.

I included some example code, in main.cpp, of things to draw, but there are many more possibilities to what can be created.

The basics to create a bitmap image with examples of what can be created.
<p><em><strong>Note that this will run and create an image without adjusting any code.  Below is just an explanation of how to change properties.</strong></em></p>

You can create a Bitmap image with the constructor:
  <code>Bitmap(<em>width_you_want_image_to_be</em>, <em>height_you_want_image_to_be</em>);</code>

The Bitmap class has a method called setPixles, which is what needs to be called when setting pixels at desired locations:
  <code>bitmapClassObject.setPixels(<em>x-coordinate</em>, <em>y-coordinate</em>, <em>red</em>, <em>green</em>, <em>blue</em>);</code>

You can loop through each pixel and set the red, green, and blue values to the desired color as you pass over the pixel.
This is similar to the fractal generator, but I was wanting something that is a stand-alone bitmap creator.  So these files are
all that is needed in order to create a bitmap and you can programatically set each pixel.  It's really fun and I recommend
everyone to check it out.
