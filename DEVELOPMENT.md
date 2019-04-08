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
