// POV V3.5
// Produced by Art of Illusion (Peter Eastman) 2.6.1
//   and POVExporter plugin (Norbert Krieg) version 1.11
//   creation date: Fri Dec 19 12:20:38 CET 2008

#version 3.5;

// Global settings
background { color rgb <1.0,1.0,0.0> }
global_settings {
	ambient_light <0.3,0.3,0.3>
}

#include "bat1.inc"

// Camera settings
camera {
	perspective
	location <-7.35141,4.130636,5.921889>
	direction <0.43229690102569585,-0.5253857093013131,-0.7328637293696121>
	up <0.4558090112061583,0.8285710039104249,-0.32512803136938984>
	right <1.0348028522729251,-0.2573470884088799,0.7948934098451764>
	angle 39.900000000000006
}

camera {
  location  <1,0,6>   
  //location  <0,-3,3>
  location  <3,2,4>
  look_at   <0.0, 0.0,  0.0>
  //look_at   <0.0, -3.0,  0.0>
  right     x*image_width/image_height
}

// Directional light (simulated as far away point light distance=10000units)
// Light 1
light_source {
	<0.0,0.0,10000.0>
	color <0.8,0.8,0.8>
	parallel
	point_at <0.0,0.0,0.0>
}


light_source {
  0*x                  // light's position (translated below)
  color rgb <1,1,1>    // light's color
  translate <-6,-3,-3>
}
light_source {
  0*x                  // light's position (translated below)
  color rgb <1,1,1>    // light's color
  translate <-6,3,3>
}
light_source {
  0*x                  // light's position (translated below)
  color rgb <1,1,1>    // light's color
  translate <-6,3,-3>
}
light_source {
  0*x                  // light's position (translated below)
  color rgb <1,1,1>    // light's color
  translate <-6,-3,3>
}
light_source {
  0*x                  // light's position (translated below)
  color rgb <1,1,1>    // light's color
  translate <6,-3,-3>
}
light_source {
  0*x                  // light's position (translated below)
  color rgb <1,1,1>    // light's color
  translate <6,3,3>
}
light_source {
  0*x                  // light's position (translated below)
  color rgb <1,1,1>    // light's color
  translate <6,3,-3>
}
light_source {
  0*x                  // light's position (translated below)
  color rgb <1,1,1>    // light's color
  translate <6,-3,3>
}

cylinder {
        <-10,0, 0>,
        <10,0,  0>,
        0.02    
        pigment {rgb <1,0.5,0.5>}
}
cylinder {
        <0,0,-10>,
        <0,0,10>,
        0.02    
        pigment {rgb <0.5,0.5,1>}
}
cylinder {
        <0,-10, 0>,
        <0,10,  0>,
        0.02    
        pigment {rgb <0.5,1,0.5>}
} 


union {

#include "tete.inc"
#declare sens_aile=1.0;
#declare angle_aile=45.0;
#include "aile.inc"

#declare sens_aile=-1.0;
#include "aile.inc"
                
rotate <60,0,-0.0>
}