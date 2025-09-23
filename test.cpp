#include "library.h"


//lab 4

const float gravity = 32.174; // feet per second squared
const int default_speed = 100; // feet per second
const double pi = acos(-1.0);

double heightattime(int startspeed, int angle, double time) {
	 double height = startspeed * time - 0.5 * gravity * time * time;
	 return height;

}

double distanceattime(int startspeed, int angle, double time) {
	double radians = (pi / 180) * angle;
	double distance = startspeed * sin(radians) * time;
	return distance;

}

boolean recersiveplotshot(int ox, int oy, int startspeed, int angle, int time, double counter) {
	if (counter > time) {
		return false;
	}
	double height = heightattime(startspeed, angle, counter);
	double distance = distanceattime(startspeed, angle, counter);
	move_to(ox + distance, oy - height);
	set_heading_degrees(0);
	set_pen_width(5);
	draw_distance(1);
	set_pen_color(1.0, counter * 0.1, 0);
	if (oy - height >= 500) {
		if (ox + distance > 800) {
			if (ox + distance < 1000) {
				move_to(500, 100);
				set_pen_color(color::black);
				write_string("You hit the house!");
				return true;
			}
			move_to(400, 250);
			set_pen_color(color::black);
			write_string("Your shot went over the house");
			return false;
		}
		move_to(300, 400);
		set_pen_color(color::black);
		write_string("Your shot hit the ground");
		return false;
		
	}
	if (ox + distance > 850 && ox + distance < 950 && oy - height > 350) {
		move_to(500, 250);
		set_pen_color(color::black);
		write_string("You hit the house!");
		return true;
	}recersiveplotshot(ox, oy, startspeed, angle, time, counter + 0.025);

}

void shouldjustbeaforloop(double x, int y, int z) {
	if (z > 0) {
		set_pen_color(color::black);
		draw_distance(x);
		turn_right_by_degrees(y);
		shouldjustbeaforloop(x, y, z - 1);
	}
}

void drawhouse(int xh, int yh) {
	set_pen_color(color::black);
	move_to(xh, yh);
	set_heading_degrees(0);
	draw_distance(100);
	turn_right_by_degrees(90);
	draw_distance(150);
	turn_right_by_degrees(90);
	draw_distance(100);
	move_to(xh, yh-100);
	set_heading_degrees(45);
	draw_distance(106.1);
	turn_right_by_degrees(90);
	draw_distance(106.1);
	move_to(xh+50, yh);
	set_heading_degrees(0);
	draw_distance(70);
	turn_right_by_degrees(90);
	draw_distance(30);
	turn_right_by_degrees(90);
	draw_distance(70);
	move_to(xh+100, yh - 40);
	set_heading_degrees(0);
	draw_distance(30);
	turn_right_by_degrees(90);
	draw_distance(30);
	turn_right_by_degrees(90);
	draw_distance(30);
	turn_right_by_degrees(90);
	draw_distance(30);

}

void drawcannon(int xg, int yg, int degrees){
	move_to(xg, yg+10);
	set_heading_degrees(270-degrees);
	set_pen_color(color::white);
	draw_distance(10);
	set_pen_color(color::black);
	draw_distance(20);
	turn_right_by_degrees(90);
	draw_distance(30);
	turn_right_by_degrees(90);
	draw_distance(80);
	turn_right_by_degrees(90);
	draw_distance(30);
	turn_right_by_degrees(90);
	draw_distance(40);
	set_pen_color(color::white);
	draw_distance(10);
	set_pen_color(color::black);
	move_to(xg, yg);
	set_heading_degrees(90);
	double step = (2 * pi * 10) / 360;
	shouldjustbeaforloop(step, 1, 360);
	}



void setup(int angle) {
	make_window(1000, 500);
	drawhouse(800, 500);
	drawcannon(50, 480, angle);
}

boolean firecannon(int angle, int speed) {
	int ox = 80;
	int oy = 440;
	return recersiveplotshot(ox, oy, speed, 90, 100, 0);

}


void main() {
print("Please enter the angle you want the cannon at");
const int angle = read_int();
setup(angle);
print("Please enter the speed you would like ball to go");
const int speed = read_int();
if (firecannon(angle, speed)) {
	print("You hit the house!");
	new_line();
	print("Game Over");
}
else {
	print("You missed the house");
	new_line();
	print("try again!");
	new_line();
	print("Please enter the angle you want the cannon at");
	const int angle = read_int();
	print("Please enter the speed you would like ball to go");
	const int speed = read_int();
	if (firecannon(angle, speed)) {
		print("You hit the house!");
		new_line();
		print("Game Over");
	}
	else {
		print("You missed the house");
		new_line();
		print("try again!");
		new_line();
		print("Please enter the angle you want the cannon at");
		const int angle = read_int();
		print("Please enter the speed you would like ball to go");
		const int speed = read_int();
		if (firecannon(angle, speed)) {
			print("You hit the house!");
			new_line();
			print("Game Over");
		}
		else {
			print("You missed the house");
			new_line();
			print("try again!");
			new_line();
			print("Please enter the angle you want the cannon at");
			const int angle = read_int();
			print("Please enter the speed you would like ball to go");
			const int speed = read_int();
			if (firecannon(angle, speed)) {
				print("You hit the house!");
				new_line();
				print("Game Over");
			}
			else {
				print("you are out of chances please restart the game to try again");
			}
		}
	}
}


}
