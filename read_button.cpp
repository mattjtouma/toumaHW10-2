// This program reads the status of a pushbutton attached to p8.16
// It uses an HTML form that can be accessed at http://192.168.7.2:8080/cgi-bin/read_button.cgi
// The build file configures the pin direction and compiles this program
//
#include <iostream>         // for the input/output
#include <cgicc/Cgicc.h>    // the cgicc headers
#include <cgicc/CgiDefs.h>
#include <cgicc/HTTPHTMLHeader.h>
#include <cgicc/HTMLClasses.h>
#include "GPIO.h" // Molloy's GPIO class
#include <pthread.h> // Needed for Molloy's GPIO class to compile correctly

using namespace std;
using namespace cgicc;
using namespace exploringBB;

int main(){
	
	// Instatiate the GPIO button input object.
	// p8.16 => GPIO46
	GPIO buttonPin(46);

	// HTML
	cout << HTTPHTMLHeader() << endl; // Generate the HTML form
	cout << html() << head(title("Read Button")) << endl; // Browser tab title
	cout << body() << h1("CPE 422/522 Reading a Pushbutton as Digital Input") << endl; // Main heading
	cout << h2("Reading a Pushbutton on gpio46 via a Web Browser") << endl; // Sub heading
	// Action element calls this program
	cout << "<form action=\"/cgi-bin/read_button.cgi\" method=\"POST\">\n";
	cout << "<div><input type=\"submit\" value=\"Read Button\"/>"; // Button element
	cout << "</div></form>"; // End the form element
	
	// Depending on the state of the button, display specific information
	cout << h3("Pushbutton State") << endl; // Another sub heading
	// If the button is not pressed, the value will be 1
	if (buttonPin.getValue() == 1) cout << h3("Button not pressed.") << endl;
	// Otherwise, the button must be pressed. Since the internal pull-up resistor is enabled,
	// there is no possibility that the button state could be anything other than a true 0 or 1
	else cout << h3("Button is pressed.") << endl;
	// End the HTML elements
	cout << body() << html();

	return 0;
}
