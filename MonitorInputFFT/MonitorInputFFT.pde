/**
  * This sketch demonstrates how to monitor the currently active audio input 
  * of the computer using an <code>AudioInput</code>. What you will actually 
  * be monitoring depends on the current settings of the machine the sketch is running on. 
  * Typically, you will be monitoring the built-in microphone, but if running on a desktop
  * its feasible that the user may have the actual audio output of the computer 
  * as the active audio input, or something else entirely.
  * <p>
  * When you run your sketch as an applet you will need to sign it in order to get an input. 
  */

import ddf.minim.*;
import ddf.minim.analysis.*;


Minim minim;
AudioInput in;

FFT fftLin;
FFT fftLog;

float height3;
float height23;
float spectrumScale = 6;

PFont font;

void setup()
{
  size(1024, 200 + 480, P3D);
  height3 = (height-200)/3;
  height23 = 2* (height- 200)/3;
  
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
  fftLin.linAverages( 30 );
  
  // create an FFT object for calculating logarithmically spaced averages
  fftLog = new FFT( in.bufferSize(), in.sampleRate() );
  //fftLog = new FFT( in.bufferSize(), 128 );
  //fftLog.window(FFT.HAMMING);

  
  // calculate averages based on a miminum octave width of 22 Hz
  // split each octave into three bands
  // this should result in 30 averages
  fftLog.logAverages( 22, 3 );
  //fftLog.logAverages( 30, 1 );
  //fftLog.logAverages( 60, 7 );
  
  rectMode(CORNERS);
  font = loadFont("ArialMT-12.vlw");
}

void draw()
{
  background(0);
   stroke(255, 255, 0);
  
  // draw the waveforms so we can see what we are monitoring
  for(int i = 0; i < in.bufferSize() - 1; i++)
  {
    line( i, 50 + in.left.get(i)*50, i+1, 50 + in.left.get(i+1)*50 );
    line( i, 150 + in.right.get(i)*50, i+1, 150 + in.right.get(i+1)*50 );
  }
  
  pushMatrix();
  stroke(255);
  //translate(0,200);
    
  textFont(font);
  textSize( 18 );
 
  float centerFrequency = 0;
  int ii = 0;
  
  // perform a forward FFT on the samples in jingle's mix buffer
  // note that if jingle were a MONO file, this would be the same as using jingle.left or jingle.right
  fftLin.forward( in.mix );
  fftLog.forward( in.mix );
 
  // draw the full spectrum
  {
    noFill();
    for(int i = 0; i < fftLin.specSize(); i++)
    {
      // if the mouse is over the spectrum value we're about to draw
      // set the stroke color to red
      if ( i == mouseX )
      {
        centerFrequency = fftLin.indexToFreq(i);
        ii = i;
        stroke(255, 0, 0);
      }
      else
      {
          stroke(255);
      }
      line(i, height3, i, height3 - fftLin.getBand(i)*spectrumScale);
    }
    
    fill(255, 128);
    text("Spectrum Center Frequency(" + ii + "): " + int(centerFrequency), 5, height3 - 25);
  }
  
  // no more outline, we'll be doing filled rectangles from now
  noStroke();
  
  // draw the linear averages
  {
    // since linear averages group equal numbers of adjacent frequency bands
    // we can simply precalculate how many pixel wide each average's 
    // rectangle should be.
    int w = int( width/fftLin.avgSize() );
    for(int i = 0; i < fftLin.avgSize(); i++)
    {
      // if the mouse is inside the bounds of this average,
      // print the center frequency and fill in the rectangle with red
      if ( mouseX >= i*w && mouseX < i*w + w )
      {
        centerFrequency = fftLin.getAverageCenterFrequency(i);

        fill(255, 128);
        text("Linear Average Center Frequency(" + i + "): " + int(centerFrequency), 5, height23 - 25);
        
        fill(255, 0, 0);
      }
      else
      {
          fill(255);
      }
      // draw a rectangle for each average, multiply the value by spectrumScale so we can see it better
      rect(i*w, height23, i*w + w, height23 - fftLin.getAvg(i)*spectrumScale);
    }
  }
  
  /*
  // draw the logarithmic averages
  {
    // since logarithmically spaced averages are not equally spaced
    // we can't precompute the width for all averages
    for(int i = 0; i < fftLog.avgSize(); i++)
    {
      centerFrequency    = fftLog.getAverageCenterFrequency(i);
      // how wide is this average in Hz?
      float averageWidth = fftLog.getAverageBandWidth(i);   
      
      // we calculate the lowest and highest frequencies
      // contained in this average using the center frequency
      // and bandwidth of this average.
      float lowFreq  = centerFrequency - averageWidth/2;
      float highFreq = centerFrequency + averageWidth/2;
      
      // freqToIndex converts a frequency in Hz to a spectrum band index
      // that can be passed to getBand. in this case, we simply use the 
      // index as coordinates for the rectangle we draw to represent
      // the average.
      int xl = (int)fftLog.freqToIndex(lowFreq);
      int xr = (int)fftLog.freqToIndex(highFreq);
      
      // if the mouse is inside of this average's rectangle
      // print the center frequency and set the fill color to red
      if ( mouseX >= xl && mouseX < xr )
      {
        fill(255, 128);
        text("Logarithmic Average Center Frequency(" + i + "): " + int(centerFrequency), 5, height - 25);
        fill(255, 0, 0);
      }
      else
      {
          fill(255);
      }
      // draw a rectangle for each average, multiply the value by spectrumScale so we can see it better
      rect( xl, height, xr, height - fftLog.getAvg(i)*spectrumScale );
    }
  }
  */  
  {
    // since linear averages group equal numbers of adjacent frequency bands
    // we can simply precalculate how many pixel wide each average's 
    // rectangle should be.
    float fftLogAvgSize = fftLog.avgSize();
    int w = int( width/fftLog.avgSize() );
    for(int i = 0; i < fftLog.avgSize(); i++)
    {
      // if the mouse is inside the bounds of this average,
      // print the center frequency and fill in the rectangle with red
      if ( mouseX >= i*w && mouseX < i*w + w )
      {
        centerFrequency = fftLog.getAverageCenterFrequency(i);

        fill(255, 128);
        text("Log Average Center Frequency(" + i + "): " + int(centerFrequency), width/2, height - height3 - 50);
        text("Log Average Band Width(" + i + "): " + int( fftLog.getAverageBandWidth(i)), width/2, height - height3 -30);
        text("Log Average(" + i + "): " +  fftLog.getAvg(i), width/2, height - height3 -10);

        fill(255, 0, 0);
      }
      else
      {
          stroke(0,0,255);
          fill(100, 210, 240);
      }
      // draw a rectangle for each average, multiply the value by spectrumScale so we can see it better
      //float spec = fftLog.getAvg(i) * (1.0 + float(i) * 10/fftLogAvgSize) * 2.5;
      float spec =  log(fftLog.getAvg(i))  * spectrumScale;
      rect(i*w, height, i*w + w, height - spec);
    }
  }
  
   
  
  popMatrix();
  println("fftLin.specSize():" + fftLin.specSize());
  println("fftLin.avgSize():" + fftLin.avgSize());
  println("fftLog.avgSize():" + fftLog.avgSize());
  //println("fftLin.getBandWidth():" + fftLin.getBandWidth());
  //println("fftLog.getBandWidth():" + fftLog.getBandWidth());
}
