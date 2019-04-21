#include "ofApp.h"
#include "view.h"
#include <cv.h>

/* Initalize screens used in this class */
void View::setupScreens(int width, int height, std::string start_file) {
	text.load("verdana.ttf", 12);

	cam_width_ = width;
	cam_height_ = height;
	combined_video_.allocate(cam_width_, cam_height_, OF_PIXELS_RGB);
	hidden_screen_.allocate(cam_width_, cam_height_, OF_IMAGE_COLOR);
	video_texture_.allocate(cam_width_, cam_height_, GL_RGB);
	mask_.allocate(cam_width_, cam_height_, OF_PIXELS_RGB);
	win_screen_.allocate(cam_width_, cam_height_, OF_IMAGE_COLOR);
	ofSetVerticalSync(true);

	loadRoom(start_file);
}

/* Sets mask as a black screen with a red cursor*/
void View::createMask(int cursor_x, int cursor_y, int cursor_r) {
	ofBackground(0, 0, 0);
	ofSetColor(255, 0, 0);
	ofDrawCircle(cursor_x, cursor_y, cursor_r);
	ofSetColor(255, 255, 255);

	ofTexture temp;
	temp.allocate(cam_width_, cam_height_, GL_RGB);
	temp.loadScreenData(0, 0, cam_width_, cam_height_);
	temp.readToPixels(mask_);
}

/* Sets room image in area where cursor shines*/
void View::combineMaskAndRoom(int cursor_x, int cursor_y, int cursor_r) {
	ofImage img("black_screen.jpg");
	img.resize(cam_width_, cam_height_);
	combined_video_ = img.getPixels();
	for (int x = cursor_x - cursor_r; x < cursor_x + cursor_r; x++) {
		for (int y = cursor_y - cursor_r; y < cursor_y + cursor_r; y++) {
			if (x < 0 || x >= cam_width_ || y < 0 || y >= cam_height_) {
				continue;
			}
			if (mask_.getColor(x, cam_height_ - 1 - y) == ofColor(255, 0, 0)) {
				combined_video_.setColor(x, y, hidden_screen_.getColor(x, y));
			}
		}
	}
	
}

/* Gets image under cursor*/
void View::loadRoom(string filename) {
	hidden_screen_.load(filename);
	hidden_screen_.resize(cam_width_, cam_height_);
	hidden_screen_.setImageType(OF_IMAGE_COLOR);
}

/* Draws combined image*/
void View::drawGameScreen(vector<int> cursor, string goal, string filename) {
	createMask(cursor[X], cursor[Y], cursor[RADIUS]);
	combineMaskAndRoom(cursor[X], cursor[Y], cursor[RADIUS]);
	video_texture_.loadData(combined_video_);
	video_texture_.draw(0, 0);

	ofSetColor(154, 154, 154);
	ofDrawRectangle(0, 0, cam_width_, 20);
	ofSetColor(0, 0, 0);
	text.drawString("Please find " + goal, 50, 15);
	ofSetColor(255, 255, 255);
}

/* Draws mask_*/
void View::drawThreshold(vector<int> cursor, ofxCvGrayscaleImage mask) {
	video_texture_.loadData(mask.getPixels());
	video_texture_.draw(0, 0);

	ofSetColor(255, 0, 0);
	ofDrawCircle(cursor[X], cursor[Y], 30);
	ofSetColor(154, 154, 154);
	ofDrawRectangle(0, 0, cam_width_, 20);
	ofSetColor(0, 0, 0);
	text.drawString("Use the R, F, T, and G keys to callibrate the threshold. Press N to start the game", 50, 15);
	ofSetColor(255, 255, 255);
}

void View::drawWinScreen() {
	ofBackground(255, 255, 0);
	hidden_screen_.load("win_screen.jpg");
	hidden_screen_.resize(cam_width_, cam_height_);
	hidden_screen_.setImageType(OF_IMAGE_COLOR);
	hidden_screen_.draw(0, 0);

}