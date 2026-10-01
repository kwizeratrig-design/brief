// Brief enclosure - parametric starting point
// Board 40 x 60 mm, no mounting holes. USB-C at +Y, buttons at -Y.

board_x = 40;
board_y = 60;
board_t = 1.6;
wall = 2.0;
floor_t = 2.0;
base_h = 10;
lid_t = 2.5;
button1 = [11.25, 7.75];
button2 = [27.25, 7.75];
led1 = [4.77, 18.5];
led2 = [20.77, 18.5];

module base() {
  difference() {
    cube([board_x + 2*wall, board_y + 2*wall, base_h]);
    translate([wall, wall, floor_t]) cube([board_x, board_y, base_h-floor_t+0.2]);
    for (p=[button1,button2]) translate([wall+p[0]-4.2,wall+p[1]-4.2,-0.1]) cube([8.4,8.4,base_h+0.2]);
    for (p=[led1,led2]) translate([wall+p[0],wall+p[1],-0.1]) cylinder(h=base_h+0.2,d=6,$fn=48);
    translate([wall+board_x/2-5,wall+board_y-0.2,4]) cube([10,wall+0.4,5]);
  }
}

module lid() {
  difference() {
    cube([board_x+2*wall,board_y+2*wall,lid_t]);
    for (p=[button1,button2]) translate([wall+p[0]-4.2,wall+p[1]-4.2,-0.1]) cube([8.4,8.4,lid_t+0.2]);
    for (p=[led1,led2]) translate([wall+p[0],wall+p[1],-0.1]) cylinder(h=lid_t+0.2,d=6,$fn=48);
  }
}

// Export one part at a time by uncommenting base(); or lid();
