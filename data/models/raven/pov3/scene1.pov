// POV V3.5
// Produced by Art of Illusion (Peter Eastman) 2.6.1
//   and POVExporter plugin (Norbert Krieg) version 1.11
//   creation date: Thu Dec 18 13:00:13 CET 2008

#version 3.5;

// Global settings
background { color rgb <0.0,0.0,0.0> }
global_settings {
	ambient_light <0.3,0.3,0.3>
}

#include "cb01.inc"



camera {
  location  <-8,-3,2>
  look_at   <0.0, 0.0,  0.0>
  right     x*image_width/image_height
}

camera {
  location  <-6,1,0>   
  //location  <-1,6,0>
  //location  <-4,4,-4>
  look_at   <0.0, 0.0,  0.0>
  right     x*image_width/image_height
}

               
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
        pigment {rgb <0.5,1,0.5>}
}
cylinder {
        <0,-10, 0>,
        <0,10,  0>,
        0.1    
        pigment {rgb <0.5,0.5,1>}
}



                

// create a regular point light source
light_source {
  0*x                  // light's position (translated below)
  color rgb <1,1,1>    // light's color
  translate <-6,-3,-3>
}
// create a regular point light source
light_source {
  0*x                  // light's position (translated below)
  color rgb <1,1,1>    // light's color
  translate <-6,3,3>
}
         
// create a regular point light source
light_source {
  0*x                  // light's position (translated below)
  color rgb <1,1,1>    // light's color
  translate <-6,3,-3>
}
// create a regular point light source
light_source {
  0*x                  // light's position (translated below)
  color rgb <1,1,1>    // light's color
  translate <-6,-3,3>
}


//#include "corps.inc"

#declare transl_aile_x=0.0;
#declare transl_aile_y=0.0;
#declare transl_aile_z=0.0;
#declare angle_aile_x=40.0;
#declare angle_aile_y=0.0;
#declare angle_aile_z=0.0;
#declare angle_aile2_x=-40.0;

#declare sens_aile=1.0;
#include "aile.inc" 

//#declare sens_aile=-1.0;
//#include "aile.inc" 

/*#declare transl_aile_x=0.0;
#declare transl_aile_y=0.0;
#declare transl_aile_z=0.0;
#declare angle_aile_x=45.0;
#declare angle_aile_y=0.0;
#declare angle_aile_z=0.0;
#include "aile.inc"
*/