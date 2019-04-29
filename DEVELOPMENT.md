# Project Log
**Week 1: Experimentation**
* Entry One
	* Accomplishments:
		* I started by playing with the videograbber library since there was very helpful examples provided by openframeworks.
		With minor tweaking, I changed one of the examples so that it detected only very bright spots such as a flashlight. 
		It works fairly well in a dark room but it also detects the light outside during the day.
		* I spent awhile wrestling with openCV to get it downloaded. The main problem I was having was that visual studio wasn't
		automatically including certain directories, but I got it to compile. I started to consider what methods I might use later
		on but haven't actually implemented any openCV yet.
	* Problems:
		* As I said, the videograbber detects the bright lights coming through windows as the same brightness as a flashlight,
		so I will probably have to use openCV to detect the circular shape of a flashlight

**Week 2**
* Entry Two
	* Accomplishments:
		* I started by setting up a class structure. I made a controller, view, and model class, based on what we learned in lecture. I
		designed it like that because I had already divided up the tasks of each class when I wrote my proposal, so it seemed logical to 
		stick with it unless I came up with a better idea.
		* After I set up structure I started working on translating a flashlight into a cursor, since that seemed like one of the more 
		difficult yet necessary tasks. After masking the video input, I use openCV to find blobs and then decide which one is the 
		correct cursor based on how circular it is, how close it is to a certain radius, and how close it is to the last blob that was
		used as a cursor. I have it basically working with bugs described below.
	* Problems:
		* The biggest problem is bright spots other than the flashlight. Right now, the program usually picks the correct blob but 
		sometimes jumps across the screen, which would be annoying during game play. It also can't detect the light at all if it is in 
		the same place as a light spot like a window. I tested it again when it got dark out and the problem obviously went away.
	* Next Steps:
		* At some point I'd like to do more tuning to make the controls better
		* Start to develop the view class so that something actually appears on the cursor

* Entry Three
	* Accomplishments:
		* I added a screen under the cursor to represent the area the player is searching. I also tweaked the settings for detecting the
		cursor and cleaned up with comments.
	* Problems:
		* The largest problem was that there are many obscure settings I needed to set for the screen to display properly. For example, the
		hidden screen had to be initalized with a certain enum so that it would be in color. The setColor method also tints the screen
		in an unexpected way, which took some time to figure out. There was also a double for loop that was making the video laggy, but I 
		fixed it by looping over a smaller area.
	* Next Steps:
		* Figure out how to determine when you've won

* Entry Four
	* Accomplishments:
		* Cleaned up which methods and variables should be public/private
		* Added tests. I just added tests for some of the bigger methods and will probably make them more rigourous later, but I wanted to make 
		sure I was thinking about how to test while writing the source code.
		
	* Problems: 
		* The most difficult part of this was that I wanted to be able to use my methods with static images instead of the camera
		for testing, but the ofx library is really weird about converting between different types of images. I also didn't really write any tests
		for View because it mostly draws stuff to the screen, which is both easy to see is working and difficult to test automatically.

**Week 3**
* Entry Five
	* Accomplishments:
		* I started setting up the classes for the map part of the game. I created Map, Room, and Door objects and figured out how to organize them
		into the existing project. This was surprisingly easy.
	* Problems:
		* I didn't run into many problems while actually adding the code. I spent the most time considering what objects deserved their own class
		and the responsibilities of each object. Once I decided on that it was mostly a matter of rearranging code to fit the new structure.
	* Next Steps:
		* I discovered a bug caused by the center of the cursor being off screen
		* The game is kind of laggy, so I'm considering ways to optimize the code
		* Consider adding an alternate way to move the cursor for when the flashlight cursor is iffy

* Entry Six
	* Accomplishments:
		* I implemented a way to play the game with the mouse instead of a flashlight. There is not currently a way to switch between the two
		modes once the game has started, but it is really easy to change it in the code.
		* I created goals for the user to actually look for, so that the game can now be properly played.
	* Problems:
		* I wanted to make it possible to switch between the mouse and flashlight in the game. I don't know how hard it will be to actually do this,
		but I ran into some errors that I didn't feel like dealing with yet, so it isn't implemented. I may or may not fix this since the point
		of the game in the end is to use the flashlight
	* Next Steps:
		* I still need to fix the bugs from the last entry

* Entry Seven
	* Accomplishments:
		* I finished up my tests. I was able to cover the controller and model classes fairly well. I
		didn't do much direct testing on the room and door classes because I did test the map class and 
		it is so reliant on the other two classes
		* I added some input validation to fix the bugs I found before. I'm not completely sure that the problem is gone but I haven't been able to 
		replicated the error. I also made it slightly less laggy by deleting a few lines that unneccessarily drew on the screen.
	* Problems:
		* I didn't do much testing on the view class because I didn't know how to test image output in a meaningful way.

**Week 4**
* Entry Eight
	* Accomplishments: Since this is only half a week, I didn't start the third stage of my project. I mostly just added final touches to the UI
	and added the README info