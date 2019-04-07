# Final Project Proposal
**General Description:**  A game which is played on a black screen where you can only see a spotlight of area on the screen 
behind the 'cursor'. Instead of using the mouse cursor, you control the cursor with an actual flashlight. The goal is to 
locate some object. Inspired by flashlight tag.

**MVC Implementation:** 
* Controller: The game is controlled by a flashlight, so the laptop's video camera must record the light and translate that 
into a certain area of the screen the user will be able to see.
* Model: Underneath, the game will need to keep track of the location of the cursor and the location of the object. If I 
have enough time, it could also track what room the player is in (see stages).
* View: The player should be able to see a mostly dark screen. The area where the cursor is will display a picture of the
room underneath.

**Stages:**  I've split the project into different stages based on how much I actually accomplish in the time given. The
first stage is a bare minimum that I would consider complete, the other stages are cool additions I'd like to do if possible.
* Stage 1: Static screen. Each game has a single picture that the user is examining with the flashlight and looking for 
the object.
* Stage 2: Map. There are doors that the user can somehow open that allows you to move from room to room. The user is looking
for an object that can be in any of the rooms.
* Stage 3: Rotation. In addition to moving from room to room, there is a way for the user to rotate 90 degrees so that each 
room has multiple views associated with it and the user can turn around.

**Resources:** 
* The [Videograbber](https://openframeworks.cc/documentation/video/) library in openframeworks can record what is on the screen.
It also has methods to deal with masking the image so only the relevant light spots show up.
* [OpenCV](https://opencv.org/) can be used for image processing to figure out where the light is an calculate data like 
center and radius