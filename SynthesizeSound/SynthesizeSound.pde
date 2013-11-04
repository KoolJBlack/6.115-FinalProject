/**
 * This sketch demonstrates how to create synthesized sound with Minim 
 * using an AudioOutput and an Oscil. An Oscil is a UGen object, 
 * one of many different types included with Minim. For many more examples 
 * of UGens included with Minim, have a look in the Synthesis 
 * folder of the Minim examples.
 */

import ddf.minim.*;
import ddf.minim.ugens.*;

Minim       minim;
AudioOutput out;
Oscil       wave;
float frequency;
float amplitude; 

PFont font;

void setup()
{
  size(1024, 400, P3D);

  minim = new Minim(this);

  // use the getLineOut method of the Minim object to get an AudioOutput object
  out = minim.getLineOut();

  amplitude = 0.5f;
  frequency = 440;

  // create a sine wave Oscil, set to 440 Hz, at 0.5 amplitude
  wave = new Oscil( frequency, amplitude, Waves.SINE );
  // patch the Oscil to the output
  wave.patch( out );

  font = loadFont("ArialMT-12.vlw");
  rectMode(CORNERS);
}

void draw()
{
  background(0);
  stroke(255);

  frequency = float(mouseX)/width * 22000;
  // Update the osccil
  wave.setFrequency(frequency); 
  wave.setAmplitude(amplitude);

  // draw the waveforms
  for (int i = 0; i < out.bufferSize() - 1; i++)
  {
    line( i, 50 + out.left.get(i)*50, i+1, 50 + out.left.get(i+1)*50 );
    line( i, 150 + out.right.get(i)*50, i+1, 150 + out.right.get(i+1)*50 );
  }

  stroke(255);
  fill(255);
  text("Spectrum Frequency: " +  int(frequency), width/2, height/4);

  computeFFT();
}

void computeFFT() {
  // Get stream fromoutput mix
  for (int i = 0; i < N_points; ++i){
    data_re[i] = out.mix.get(i);
  }
  
  // Compute FFt
  FFT(1, exponent);
  
  int w = width/N_points;
  stroke(0,0,255);
  fill(100, 210, 240);
  
  for (int i = 0; i < N_points; ++i){
    // draw a rectangle for each average, multiply the value by spectrumScale so we can see it better
    //float spec = fftLog.getAvg(i) * (1.0 + float(i) * 10/fftLogAvgSize) * 2.5;
    float spec = mod[i] * 10000;
    
    rect(i*w, height, i*w + w, height - spec);
    //println(spec);
  }
  
  // clean old fft data
  for (int i=0;i<N_points; ++i) {    
    mod[i]=0;       //init 0
    data_re[i]=0;
    data_imm[i]=0;
  }
}

void keyPressed() {
  switch(keyCode) {
  case UP:
    amplitude += 0.05f;
    break;
  case DOWN:
    amplitude -= 0.05f;
    break;
  }
}

