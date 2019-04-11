#include "ofApp.h"
#include "view.h"
#include <cv.h>

/* Initalize screens used in this class */
void View::setupScreens(int width, int height) {
	cam_width = width;
	cam_height = height;
	combined_video.allocate(cam_width, cam_height, OF_PIXELS_RGB);
	hidden_screen.allocate(cam_width, cam_height, OF_IMAGE_COLOR);
	video_texture.allocate(cam_width, cam_height, GL_RGB);
	mask.allocate(cam_width, cam_height, OF_PIXELS_RGB);
	ofSetVerticalSync(true);
}

/* Sets mask as a black screen with a red cursor*/
void View::createMask(int cursor_x, int cursor_y) {
	ofBackground(0, 0, 0);
	ofSetColor(255, 0, 0);
	ofDrawCircle(cursor_x, cursor_y, 30);
	ofSetColor(255, 255, 255);

	ofTexture temp;
	temp.allocate(cam_width, cam_height, GL_RGB);
	temp.loadScreenData(0, 0, cam_width, cam_height);
	temp.readToPixels(mask);
}

/* Sets room image in area where cursor shines*/
void View::combineMaskAndRoom(int cursor_x, int cursor_y) {
	ofImage img("black_screen.jpg");
	combined_video = img.getPixels();
	for (int x = cursor_x - 30; x < cursor_x + 30; x++) {
		for (int y = cursor_y - 30; y < cursor_y + 30; y++) {
			if (x < 0 || x >= cam_width || y < 0 || y >= cam_height) {
				continue;
			}
			if (mask.getColor(x, cam_height - y) == ofColor(255, 0, 0)) {
				combined_video.setColor(x, y, hidden_screen.getColor(x, y));
			}
		}
	}
}

/* Gets image under cursor*/
void View::loadRoom() {
	hidden_screen.load("test.jpg");
	hidden_screen.setImageType(OF_IMAGE_COLOR);
}

/* Draws combined image*/
void View::drawScreen(int cursor_x, int cursor_y) {
	createMask(cursor_x, cursor_y);
	loadRoom();
	combineMaskAndRoom(cursor_x, cursor_y);
	video_texture.loadData(combined_video);
	video_texture.draw(0, 0);
}