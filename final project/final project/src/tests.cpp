/*#define CATCH_CONFIG_MAIN 
#include "catch.hpp"
#include "controller.h"
#include "view.h"
#include "model.h"
#include <vector>

Controller control;
Model model;
///////////////CONTROLLER TESTS////////////////////
TEST_CASE("Find circles test") {
	
	control.setup(1390,675, false);
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

TEST_CASE("Calculate cursor test") {
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


//////////////////MODEL TESTS////////////////////
TEST_CASE("win test") {
	model.setGoal();
	
	int test_true[4][2] = { {model.getGoalLocation()[0], model.getGoalLocation()[1]},
						    {model.getGoalLocation()[0] + 14, model.getGoalLocation()[1]},
						    {model.getGoalLocation()[0], model.getGoalLocation()[1] + 14},
						    {model.getGoalLocation()[0] + 5, model.getGoalLocation()[1] + 5} };
	int test_false[3][2] = { {model.getGoalLocation()[0] + 15, model.getGoalLocation()[1]},
						     {model.getGoalLocation()[0], model.getGoalLocation()[1] + 15},
						     {model.getGoalLocation()[0] + 50, model.getGoalLocation()[1] } };
	
	for (int i = 0; i < 4; i++) {	
		model.setCursor(test_true[i][0], test_true[i][1], 30);
		model.game_state_ = model.GAME;
		REQUIRE(model.checkWin() == true);
	
	}

	for (int i = 0; i < 3; i++) {
		model.setCursor(test_false[i][0], test_false[i][1], 30);
		model.game_state_ = model.GAME;
		REQUIRE(model.checkWin() == false);
	}

	//Stay in win state after first win
	model.setCursor(test_true[0][0], test_false[0][1], 30);
	model.checkWin();
	model.setCursor(test_false[0][0], test_false[0][1], 30);
	REQUIRE(model.checkWin() == true);

}

TEST_CASE("set goals test") {
	REQUIRE(0 == 0);
}*/