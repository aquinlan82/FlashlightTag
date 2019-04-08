#include "ofApp.h"
#include "view.h"
#include <cv.h>

void View::setupScreens(int width, int height) {
	cam_width = width;
	cam_height = height;
	combined_video.allocate(cam_width, cam_height, OF_PIXELS_RGB);
	hidden_screen.allocate(cam_width, cam_height, OF_PIXELS_RGB);
	ofSetVerticalSync(true);
}

void View::loadHiddenScreen() {
	ofLoadImage(hidden_screen, "test.jpg");
}

void View::combineScreens() {
	/*for (int x = 0; x < cam_width; x++) {
		for (int y = 0; y < cam_height; y++) {
			if (pixels.getColor(x, y).getBrightness() > 250) {
				combined_video.setColor(x, y, hidden_screen.getColor(x, y));
			}
			else {
				combined_video.setColor(x, y, ofColor::black);
			}
		}
	}*/
}
//temporary parameter while testing
void View::drawScreen() {
	ofBackground(100, 100, 100);
	ofSetHexColor(0xffffff);
	//vid_grabber.draw(20, 20);
	/*video_texture.draw(20 + cam_width, 20, cam_width, cam_height);
	grayDiff.draw(20, 20 + cam_height, cam_width, cam_height);

	for (int i = 0; i < contour_finder.nBlobs; i++) {
		ofRectangle r = contourFinder.blobs.at(i).boundingRect;
		r.x += 340; r.y += 260;
		ofColor c(0, 0, 255);
		ofSetColor(c);
		ofDrawRectangle(r);
	}*/

	
}