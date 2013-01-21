#include "testApp.h"
#include "ofxXmlSettings.h"
//--------------------------------------------------------------
void testApp::setup(){
	//SimpleReceiverPort.txt should just have the port number
	ofxXmlSettings settings("SimpleReceiverPort.xml");

	port = settings.getValue("PORT",12345);
	duration.setup(port);
	//ofxDuration is an OSC receiver, with special functions to listen for Duration specific messages
	//optionally set up a font for debugging
	duration.setupFont("GUI/NewMedia Fett.ttf", 12);
	ofAddListener(duration.events.trackUpdated, this, &testApp::trackUpdated);
	
	
	
	ofEnableAlphaBlending();
    ofSetCircleResolution(100);
    
    width = ofGetWidth();
    height = ofGetHeight();
	
    // Initial Allocation
    //
    fluid.allocate(width, height, 0.5);
    
    // Seting the gravity set up & injecting the background image
    //
    fluid.dissipation = 0.99;
    fluid.velocityDissipation = 0.99;
    
    fluid.setGravity(ofVec2f(0.0,0.0));
	//    fluid.setGravity(ofVec2f(0.0,0.0098));
    
    //  Set obstacle
    //
//    fluid.begin();
//    ofSetColor(255);
//    ofCircle(width*0.5, height*0.35, 40);
//    fluid.end();
    
    // Adding constant forces
    //
//    fluid.addConstantForce(ofPoint(width*0.5,height*0.85), ofPoint(0,-2), ofFloatColor(0.5,0.1,0.0), 10.f);

	
}
//--------------------------------------------------------------
//Or wait to receive messages, sent only when the track changed
void testApp::trackUpdated(ofxDurationEventArgs& args){
	ofLogVerbose("Duration Event") << "track type " << args.track->type << " updated with name " << args.track->name << " and value " << args.track->value << endl;
	
	if(args.track->name=="dissipation")
	{
		fluid.dissipation = 0.99;

	}
	else if(args.track->name=="velocityDissipation")
	{
		fluid.velocityDissipation = 0.99;		
	}
}
//--------------------------------------------------------------
void testApp::update(){
	//  Update
    //
    fluid.update();
}

//--------------------------------------------------------------
void testApp::draw(){
	ofBackground(0);
    
    fluid.draw();
	duration.draw(0,0, ofGetWidth(), ofGetHeight());
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	if( key == 'p')
		bPaint = !bPaint;
    if( key == 'o')
        bObstacle = !bObstacle;
    if( key == 'b')
        bBounding = !bBounding;
    if( key == 'c')
        bClear = !bClear;
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	ofPoint m = ofPoint(mouseX,mouseY);
    ofPoint d = (m - oldM)*10.0;
    oldM = m;
    ofPoint c = ofPoint(640*0.5, 480*0.5) - m;
    c.normalize();
    fluid.addTemporalForce(m, d, ofFloatColor(c.x,c.y,0.5),3.0f);

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}