import ddf.minim.*;
import ddf.minim.analysis.*;

Minim minim;
AudioInput in;
FFT fftLin;
FFT fftLog;

PFont font;

float[][] stftVals;
final int TIME_SIZE = 1024;
final int FREQUENCY_SIZE = 512;
int stftPointer;

int LINE_AVERAGE_SIZE = 30;

float FFT_SCALE = 6.7;

void setup(){
  size(TIME_SIZE, FREQUENCY_SIZE);

  minim = new Minim(this);
  
  // use the getLineIn method of the Minim object to get an AudioInput
  in = minim.getLineIn();
  
  // uncomment this line to *hear* what is being monitored, in addition to seeing it
  //in.enableMonitoring();
  
  // create an FFT object that has a time-domain buffer the same size as jingle's sample buffer
  // note that this needs to be a power of two 
  // and that it means the size of the spectrum will be 1024. 
  // see the online tutorial for more info.
  fftLin = new FFT( in.bufferSize(), in.sampleRate() );
  //fftLin = new FFT( in.bufferSize(), 128 );
  // calculate the averages by grouping frequency bands linearly. use 30 averages.
  fftLin.linAverages( LINE_AVERAGE_SIZE );
  
  // create an FFT object for calculating logarithmically spaced averages
  fftLog = new FFT( in.bufferSize(), in.sampleRate() );
  //fftLog = new FFT( in.bufferSize(), 128 );
  fftLog.window(FFT.HAMMING);

  
  // calculate averages based on a miminum octave width of 22 Hz
  // split each octave into three bands
  // this should result in 30 averages
  fftLog.logAverages( 22, 3 );
  //fftLog.logAverages( 30, 1 );
  //fftLog.logAverages( 60, 7 );
  
  // Initialize the font used for display
  font = loadFont("ArialMT-12.vlw");
  
  // SFTF Values
  stftVals = new float[TIME_SIZE][FREQUENCY_SIZE];
  stftPointer = 0; 
  
  // Color mode for drawing spectrum
  colorMode(HSB, 360,100,100);
}

void update(){
  // perform a forward FFT on the samples in mix buffer
  fftLin.forward( in.mix );
  //fftLog.forward( in.mix );

  //println(fftLin.specSize());
  // Save values to stft
  /*
  for(int i = 0;i < FREQUENCY_SIZE; ++i){
    stftVals[stftPointer][i] = fftLin.getBand(i);
  }  */
  //println(FREQUENCY_SIZE/LINE_AVERAGE_SIZE);
  for(int i = 0;i < LINE_AVERAGE_SIZE; ++i){
    for(int j = 0; j < FREQUENCY_SIZE/LINE_AVERAGE_SIZE; ++j){
      stftVals[stftPointer][i *FREQUENCY_SIZE/LINE_AVERAGE_SIZE + j ] = fftLin.getAvg(i);
    }
  }
  // Advance the pointer mod TIME_SIZE
  stftPointer = (stftPointer+1) % TIME_SIZE;
}

void draw(){
  update();
  
  background(0);
  //textFont(font);
  //textSize( 18 );

  drawSTFT();
  
  //log();
}

void drawSTFT(){
  // Before we deal with screen pixels
  loadPixels();  
  // Loop through every pixel
  int x;
  int hue;
  for (int i = 0; i < TIME_SIZE; ++i){
    for(int j = 0; j < FREQUENCY_SIZE; ++j){
      // Shift the output by the stftPointer (shows time progression)
      x = (i + stftPointer) % TIME_SIZE; 
      // Hue values should range between 250 ( blue) and 0 (red)
      //hue = (int)stftVals[x][j];
      hue =  max(250 - (int)(stftVals[x][j] * FFT_SCALE), 0);
      pixels[i + j*TIME_SIZE] = color(hue,100,100);
    }
  }
  // When we are finished dealing with screen pixels
  updatePixels(); 
}

void log(){
  println("fftLin.specSize():" + fftLin.specSize());
  println("fftLin.avgSize():" + fftLin.avgSize());
  println("fftLog.avgSize():" + fftLog.avgSize());
  //println("fftLin.getBandWidth():" + fftLin.getBandWidth());
  //println("fftLog.getBandWidth():" + fftLog.getBandWidth());  
}
