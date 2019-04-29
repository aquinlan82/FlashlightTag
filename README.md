#Flashlight ISpy

**What is it?** ISpy, but harder. Use the arrow keys to navigate a house and a flashlight to navigate the room. The goal is to find the provided object. Cursor can also be moved with mouse.

**How to Run:** The game is playable as is, all you need to do is compile the code! However, there are a few things that can be altered with slight modifications:
* By default, the flashlight is detected using your laptop's built in camera. To change cameras, change the index of the `vid_grabber_.setDeviceID(0); ` line in controller.cpp.
* If you want to play with the mouse instead of a flashlight change the `MouseController control_;` line in ofApp.h to `FlashController control_;`