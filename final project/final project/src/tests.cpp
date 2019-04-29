/*#define CATCH_CONFIG_MAIN 
#include "catch.hpp"
#include "controller.h"
#include "view.h"
#include "model.h"
#include <vector>

FlashController control;
Model model;

///////////////CONTROLLER TESTS////////////////////
TEST_CASE("Setup Test") {
	control.setup(1390, 675, true);
	REQUIRE(control.getWidth() == 1390);
	REQUIRE(control.getHeight() == 675);
	REQUIRE(control.getCameraImage().isInitialized());
}

TEST_CASE("Get and Set Width and Height") {
	control.setSize(400, 500);
	REQUIRE(control.getWidth() == 400);
	REQUIRE(control.getHeight() == 500);

	control.setSize(0, 40);
	REQUIRE(control.getWidth() == 400);
	REQUIRE(control.getHeight() == 500);

	control.setSize(500, -50);
	REQUIRE(control.getWidth() == 400);
	REQUIRE(control.getHeight() == 500);
}

TEST_CASE("Find circles Test") {
	int correct_x[4][5] = { {475, 1049, 128},
							{970},
							{1077, 171, 146},
							{} };
	for (int i = 0; i < 4; i++) {
		control.updateMaskImg("mask" + to_string(i) + ".png");
		control.findCircles();

		for (int j = 0; j < control.getBrightSpots().size(); j++) {
			REQUIRE(control.getBrightSpots()[j][0] == correct_x[i][j]);
		}
	}
}

TEST_CASE("Calculate Cursor Test") {
	int correct_cursor[4][2] = { {1049, 558},
								 {970, 527},
								 {146,471},
								 {0,0} };
	for (int i = 0; i < 4; i++) {
		control.updateMaskImg("mask" + to_string(i) + ".png");
		control.findCircles();
		vector<int> cursor = control.calculateCursor({ 0,0,0 }, 30);

		REQUIRE(cursor[0] == correct_cursor[i][0]);
		REQUIRE(cursor[1] == correct_cursor[i][1]);
	}
}

TEST_CASE("Get Camera Test") {
	control.getCameraImage().update();
	REQUIRE(control.getCameraImage().isFrameNew());
}


//////////////////MODEL & MAP TESTS////////////////////
TEST_CASE("Set and Get Cursor") {
	model.setCursor(20, 30, 40);
	REQUIRE(model.getCursor()[0] == 20);
	REQUIRE(model.getCursor()[1] == 30);
	REQUIRE(model.getCursor()[2] == 40);

	model.setCursor(0, 30, 40);
	REQUIRE(model.getCursor()[0] == 20);
	REQUIRE(model.getCursor()[1] == 30);
	REQUIRE(model.getCursor()[2] == 40);

	model.setCursor(20, -50, 40);
	REQUIRE(model.getCursor()[0] == 20);
	REQUIRE(model.getCursor()[1] == 30);
	REQUIRE(model.getCursor()[2] == 40);

	model.setCursor(20, 30, -6);
	REQUIRE(model.getCursor()[0] == 20);
	REQUIRE(model.getCursor()[1] == 30);
	REQUIRE(model.getCursor()[2] == 40);
}

TEST_CASE("Get and Set Goal Location") {
	model.setGoal(0);
	REQUIRE(model.getGoalLocation()[0] == 0);
	REQUIRE(model.getGoalLocation()[1] == 60);
	REQUIRE(model.getGoalLocation()[2] == 463);

	model.setGoal(5);
	REQUIRE(model.getGoalLocation()[0] == 1);
	REQUIRE(model.getGoalLocation()[1] == 1160);
	REQUIRE(model.getGoalLocation()[2] == 596);

	model.setGoal(20);
	REQUIRE(model.getGoalLocation().size() == 3);
}

TEST_CASE("Get and Set Goal Name") {
	model.setGoal(0);
	REQUIRE(model.getGoalName() == "a broom");
	model.setGoal(5);
	REQUIRE(model.getGoalName() == "a corn magnet");
	model.setGoal(20);	
	REQUIRE(!model.getGoalName().empty());

}

TEST_CASE("Win Test") {
	model.generateMap();
	model.setGoal(0);

	int test_true[4][3] = { {0, model.getGoalLocation()[1], model.getGoalLocation()[2]},
						    {0, model.getGoalLocation()[1] + 14, model.getGoalLocation()[2]},
							{0, model.getGoalLocation()[1] + 5, model.getGoalLocation()[2] + 5},
						    {0, model.getGoalLocation()[1], model.getGoalLocation()[2] + 14} };

	int test_false[3][3] = { {0, model.getGoalLocation()[1] + 15, model.getGoalLocation()[2]},
						     {0, model.getGoalLocation()[1], model.getGoalLocation()[2] + 15},
						     {0, model.getGoalLocation()[1] + 50, model.getGoalLocation()[2] } };

	for (int i = 0; i < 4; i++) {
		model.setCursor(test_true[i][1], test_true[i][2], 30);
		model.game_state_ = model.GAME;
		REQUIRE(model.checkWin() == true);
	}

	for (int i = 0; i < 3; i++) {
		model.setCursor(test_false[i][1], test_false[i][2], 30);
		model.game_state_ = model.GAME;
		REQUIRE(model.checkWin() == false);
	}

	//Stay in win state after first win
	model.setCursor(test_true[0][1], test_false[0][2], 30);
	model.checkWin();
	model.setCursor(test_false[0][1], test_false[0][2], 30);
	REQUIRE(model.checkWin() == true);

}

TEST_CASE("Change Room Test") {
	REQUIRE(model.getFilename() == "entry1.jpg");
	model.tryOpenDoor(OF_KEY_UP);
	REQUIRE(model.getFilename() == "livingroom1.jpg");
	model.tryOpenDoor(OF_KEY_LEFT);
	REQUIRE(model.getFilename() == "bed1.jpg");
	model.tryOpenDoor(OF_KEY_RIGHT);
	REQUIRE(model.getFilename() == "office1.jpg");
}

*/



