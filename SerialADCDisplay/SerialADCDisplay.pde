import processing.serial.*;

Serial myPort;  // Create object from Serial class
String serialIn; // String data received from serial port
int newVal;


int[] vals = new int[512];


void setup() {
  size(512, 256);
  
  // List all the avaliale serial ports
  println(Serial.list()); 
  
  
  // I know that the first port in the serial list on my mac
  // is always my  FTDI adaptor, so I open Serial.list()[0].
  // On Windows machines, this generally opens COM1.
  // Open whatever port is the one you're using.
  String portName = Serial.list()[0];
  myPort = new Serial(this, portName, 9600);
  myPort.clear();

  frameRate(5000);
}

void draw(){
  if ( myPort.available() > 0) {  // If data is available,
    //val = myPort.read();         // read it and store it in val
    serialIn = myPort.readStringUntil(' ');
    //serialIn = myPort.readString();
    if(serialIn == null || serialIn == ""){
      return;
    }
  }
  
  // Format to integer
  println("serialIn "  + serialIn);
  
  
  newVal = Integer.parseInt(serialIn.trim(),16);

  // Shift all numbers
  for(int i = 0; i < vals.length - 1; ++i){
    vals[i] = vals[i + 1];
  }
  // Add new number to end
  vals[vals.length -1] = newVal;

  background(0);
  stroke(255);  
  
  // Draw signal
  for(int i = 0; i < vals.length - 1; ++i){
    line( i, height - vals[i], i+1, height - vals[i + 1]);
  }

}

