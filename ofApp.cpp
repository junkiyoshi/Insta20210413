#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openframeworks");

	ofBackground(239);
	ofSetColor(39);

	for (int x = -280; x <= 280; x += 35) {

		for (int y = -280; y <= 280; y += 35) {

			this->location_list.push_back(glm::vec2(x, y));
		}
	}
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWindowSize() * 0.5);

	for (auto& location : this->location_list) {

		int angle = ofMap(ofNoise(glm::vec3(location * 0.0008, ofGetFrameNum() * 0.002)), 0, 1, 0, 720);
		int param = angle % 90;
		angle = angle - param;

		ofSetColor(39);
		if (param < 5) {

			angle += ofMap(param, 5, 0, 0, -90);
			ofSetColor(239, 0, 0);
		}
		else if (param > 85) {

			angle += ofMap(param, 85, 0, 0, 90);
			ofSetColor(239, 0, 0);
		}


		this->draw_arrow(location, angle, 20);
	}
}

//--------------------------------------------------------------
void ofApp::draw_arrow(glm::vec2 location, float angle, float size) {

	angle *= DEG_TO_RAD;

	ofBeginShape();
	ofVertex(location + glm::vec2(size * cos(angle), size * sin(angle)));
	ofVertex(location + glm::vec2(size * 0.5 * cos(angle + PI * 0.5), size * 0.5 * sin(angle + PI * 0.5)));
	ofVertex(location + glm::vec2(size * 0.5 * cos(angle - PI * 0.5), size * 0.5 * sin(angle - PI * 0.5)));
	ofEndShape(true);

	ofBeginShape();
	ofVertex(location + glm::vec2(size * 0.5 * cos(angle + PI * 0.5), size * 0.5 * sin(angle + PI * 0.5)) * 0.25);
	ofVertex(location + glm::vec2(size * 0.5 * cos(angle + PI * 0.5), size * 0.5 * sin(angle + PI * 0.5)) * 0.25 - glm::vec2(size * cos(angle), size * sin(angle)) * 0.5);
	ofVertex(location + glm::vec2(size * 0.5 * cos(angle - PI * 0.5), size * 0.5 * sin(angle - PI * 0.5)) * 0.25 - glm::vec2(size * cos(angle), size * sin(angle)) * 0.5);
	ofVertex(location + glm::vec2(size * 0.5 * cos(angle - PI * 0.5), size * 0.5 * sin(angle - PI * 0.5)) * 0.25);
	ofEndShape(true);
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}