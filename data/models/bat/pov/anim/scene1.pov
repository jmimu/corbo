// POV V3.5
// Produced by Art of Illusion (Peter Eastman) 2.6.1
//   and POVExporter plugin (Norbert Krieg) version 1.11
//   creation date: Thu Dec 18 13:00:13 CET 2008

//#version 3.5;

// Global settings
background { color rgb <1.0,1.0,0.0> }
global_settings {
	ambient_light <0.3,0.3,0.3>
	
}

#include "bat1.inc"



camera {
  location  <-8,-3,2>
  look_at   <0.0, 0.0,  0.0>
  right     x*image_width/image_height
}

camera {
//  location  <-8,1,0>
  location  <-1,1,-8>
  look_at   <0.0, 0.0,  0.0>
  right     x*image_width/image_height
}

camera {
  location  <10+cos(temps)/7.0,-3+cos(temps+1)/2.0,3+cos(temps-1)/3.0>
  look_at   <cos(temps-2)/10.0,cos(temps)/4.0,cos(temps+2)/11.0>
  right     x*image_width/image_height
}

/*camera {
  location  <0,0,10>
  look_at   <0,0,0>
  right     x*image_width/image_height
}*/
   /*            
cylinder {
        <-10,0, 0>,
        <10,0,  0>,
        0.1    
        pigment {rgb <1,0.5,0.5>}
}
cylinder {
        <0,0,-10>,
        <0,0,10>,
        0.1    
        pigment {rgb <0.5,0.5,1>}
}
cylinder {
        <0,-10, 0>,
        <0,10,  0>,
        0.1    
        pigment {rgb <0.5,1,0.5>}
}
*/
        

light_source {
  0*x                  // light's position (translated below)
  color rgb <1,1,1>    // light's color
  translate <3,cos(temps)*15-13*0,sin(temps)*15>
}
light_source {
  0*x                  // light's position (translated below)
  color rgb <1,1,1>    // light's color
  translate <3,cos(temps-pi/2)*15-13*0,sin(temps-pi/2)*15>
}
light_source {
  0*x                  // light's position (translated below)
  color rgb <1,1,1>    // light's color
  translate <3,cos(temps-pi)*15-13*0,sin(temps-pi)*15>
}
light_source {
  0*x                  // light's position (translated below)
  color rgb <1,1,1>    // light's color
  translate <3,cos(temps+pi/2)*15-13*0,sin(temps+pi/2)*15>
}


#declare angle_aile=-80.0*cos((2*pi-temps)*(2*pi-temps)/(2*pi));


camera {
  location  <10+cos(temps)/7.0,-3,3+cos(temps-1)/3.0>
  look_at   <cos(temps-2)/10.0,cos((2*pi-temps)*(2*pi-temps)/(2*pi))/4.0,cos(temps+2)/11.0>
  right     x*image_width/image_height
}



union {

#include "tete.inc"

#declare sens_aile=1.0;
#include "aile.inc" 

#declare sens_aile=-1.0;
#include "aile.inc" 

rotate <60,0,-0.0>
	//rotate <0,cos(cos((2*pi-temps)*(2*pi-temps)/(2*pi))*pi)/4.0,0>
}
