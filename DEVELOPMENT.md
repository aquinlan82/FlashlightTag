# Project Log
**Week 1: Experimentation**  
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