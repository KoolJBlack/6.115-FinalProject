import processing.serial.*;

Serial myPort;  // Create object from Serial class
char val;      // Data received from the serial port
String serialIn; // String data received from serial port

int NUM_AVG = 16/2;
int NUM_VAL = 128;

int[] avgs = new int[NUM_AVG];
int[] vals = new int[NUM_VAL];

boolean beat1, beat2;
long lastBeatTime;

int BEAT_TIMEOUT = 300;


void setup() {
  size(512, 256);
  
  // List all the avaliale serial ports
  println(Serial.list()); 
  
  // I know that the first port in the serial list on my mac
  // is always my  FTDI adaptor, so I open Serial.list()[0].
  // On Windows machines, this generally opens COM1.
  // Open whatever port is the one you're using.
  String portName = Serial.list()[6];
  myPort = new Serial(this, portName, 9600);

  // Drawing modes
  rectMode(CORNER);
  ellipseMode(CENTER);
}

void update(){
  if ( myPort.available() > 0) {  // If data is available,
    while(true){
      val = myPort.readChar();         // read it and store it in val
      if(val == 0xFF){
        println(val);
        break;
      }
    }// end while
    
    while(myPort.available() == 0){}
    avgs[0] = myPort.read();
    while(myPort.available() == 0){}
    avgs[1] = myPort.read();
    while(myPort.available() == 0){}
    avgs[2] = myPort.read();
    while(myPort.available() == 0){}
    avgs[3] = myPort.read();
    while(myPort.available() == 0){}
    avgs[4] = myPort.read();
    while(myPort.available() == 0){}
    avgs[5] = myPort.read();
    while(myPort.available() == 0){}
    avgs[6] = myPort.read();
    while(myPort.available() == 0){}
    avgs[7] = myPort.read();
    
    
    for(int i =0; i < avgs.length; ++i){
      print(avgs[i] + " ");
    }
    println();
    
    while(myPort.available() == 0){}
    int beatIn = myPort.read();
    switch(beatIn){
      case 3:
        beat1 = true;
        beat2 = true;
        break;
      case 2:
        beat1 = false;
        beat2 = true;
        break;
      case 1:
        beat1 = true;
        beat2 = false;
        break;
      case 0:
        beat1 = false;
        beat2 = false;
        break;
      default:
        println("error");
    }
  }// end if myport
  
}

void parseSerialAvg(){
  String[] toParse = serialIn.split(" ");
  //println("toParse.length :" + toParse.length);
  
  if(toParse.length != NUM_AVG + 2){
    return;
  }
  
  for(int i = 1; i < NUM_AVG + 1; ++i){
    avgs[i-1] = Integer.parseInt(toParse[i].trim(),16);
    //println("A:" + avgs[i-1]);
  } 
  
  println(toParse[toParse.length-1]);
  
  char beatIn =toParse[toParse.length-1].trim().charAt(1);
  
  //long diff = System.currentTimeMillis() - lastBeatTime;
  switch(beatIn){
    case '3':
      beat1 = true;
      beat2 = true;
      break;
    case '2':
      beat1 = false;
      beat2 = true;
      break;
    case '1':
      beat1 = true;
      beat2 = false;
      break;
    case '0':
      beat1 = false;
      beat2 = false;
      break;
  }
}


void parseSerialVal(){
  String[] toParse = serialIn.split(" ");
  //println("toParse.length :" + toParse.length);
  if(toParse.length != NUM_VAL + 1){
    return;
  }
  for(int i = 1; i < NUM_VAL + 1; ++i){
    vals[i-1] = Integer.parseInt(toParse[i].trim(),16);
    //println("A:" + avgs[i-1]);
  } 
}

void draw(){
  update();

  drawAvg();
  //drawVal();

}

void drawAvg(){
  background(0);             // Set background to black
  
  stroke(255);
  fill(0,0,255);
  
  
  for(int i = 0; i < NUM_AVG; ++i){
    rect(i * width/NUM_AVG, height, width/NUM_AVG, -avgs[i]);
  }
  
  if(beat1){
    fill(255,0,0);
    ellipse(100,100, 50, 50);
  }
  if(beat2){
    fill(255,0,0);
    ellipse(width-100,100, 50, 50);    
  }
}

void drawVal(){
  background(0);             // Set background to black
  
  stroke(255);
  fill(0,0,255);
  
  for(int i = 0; i < NUM_VAL; ++i){
    rect(i * width/NUM_VAL, height, width/NUM_VAL, -vals[i]);
  }
}



