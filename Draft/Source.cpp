#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::vector;
using std::string;
using std::cout;

// Класс точки
class Point {
public:
	int x, y;

	Point(int X, int Y) {
		x = X;
		y = Y;
	}
	void print() {
		cout << "(" << x << ", " << y << ")\n";
	}
};

class Line {
public:
	float p1[2], p2[2];

	Line(int x_1, int y_1, int x_2, int y_2) {
		p1[0] = x_1;
		p1[1] = y_1;
		p2[0] = x_2;
		p2[1] = y_2;
	}
	void print() {
		printf("(%.3f, %.3f), (%.3f, %.3f)\n", p1[0], p1[1], p2[0], p2[1]);
	}
	void normilize(int width_window, int height_window) {						// Приводит к Normilize Device Coordinate
		p1[0] -= width_window/2;
		p1[0] /= width_window;

		p1[1] -= height_window/2;
		p1[1] /= height_window;

		p2[0] -= width_window / 2;
		p2[0] /= width_window;

		p2[1] -= height_window / 2;
		p2[1] /= height_window;
	}
};
/*	Генерирует массив для сетки
	/

*/

// dx, dy - шаги сетки
vector<Line> grid_generator(float dx, float dy) {
	int w = 800;			// Ширина рабочего пространства
	int h = 800;			// Высота рабочего пространства

	int s_x = 80;
	int s_y = 350;
		
	//float dx = 80;						// Шаг сетки
	//float dy = 80;	

	vector<Line> lines;
	lines.reserve((w / dx) + (h / dy));		// Аллоцирование место под линии перпендикулярные Ox и Oy
	for (int i = 0; i <= w/dx; i++) {
		Line l(
			s_x + i * dy, s_y,
			s_x + i * dy, s_y + h
		);

		l.normilize(1440, 1024);
		lines.push_back(l);
	}
	
	for (int i = 0; i <= h / dy; i++) {
		Line l(
			s_x,		s_y + i*dy,
			s_x + w,	s_y + i*dy
		);

		l.normilize(1440, 1024);
		lines.push_back(l);
	
	}

	vector<float> output;
	output.reserve(2 * 6 * lines.size());		// В линии 2 точки по 6 значений

	for (auto l : lines){
		output.push_back(l.p1[0]);		// p1 x
		output.push_back(l.p1[1]);		// p1 y
		output.push_back(0.0f);			// p1 z

		output.push_back(l.p2[0]);		// p2 x
		output.push_back(l.p2[1]);		// p2 y
		output.push_back(0.0f);			// p2 z



		printf("%.3ff, %.3ff, 1.0f, 1.0f, 1.0f, 1.0f,\n", l.p1[0], l.p1[1]);
		printf("%.3ff, %.3ff, 1.0f, 1.0f, 1.0f, 1.0f,\n", l.p2[0], l.p2[1]);
	}

	return lines;

};

class Grid {
public:
	int window_size[2];				// Размер окна приложения		[px]
	int grid_size[2];				// Размер окна сетки			[px]
	float coord_x, coord_y;			// Расположение					[px]
	float dx, dy;					// Шаги сетки					[px]
	float rgb[3];					// Цвет и прозрачность сетки	[colors]

	vector<float> output_vertex;	// 
	

	Grid(int Window_size[2], int Grid_size[2], float Dx, float Dy, float Coord_x, float Coord_y, float RGB[3]) {
		window_size[0] = Window_size[0];
		window_size[1] = Window_size[1];
		grid_size[0] = Grid_size[0];
		grid_size[1] = Grid_size[1];
		coord_x = Coord_x;
		coord_y = Coord_y;
		dx = Dx;
		dy = Dy;

		rgb[0] = RGB[0];
		rgb[1] = RGB[1];
		rgb[2] = RGB[2];
		


		return;
	};

	void generate_grid() {

		return;
	}

	void draw() {
		return; 
	}

	void move(float move_x, float move_y) {
		return;
	}

	void reshape(float dx, float dy) {
		return;
	}
	
	// Поварачивает на degree градусов		[deg]
	void rotate(int degree) {
		return;
	}

	void print_setting() {
		printf("Grid ------------------\n");

		printf("window size     : (%d, %d) \n", window_size[0], window_size[1]);
		printf("grid size       : (%d, %d) \n", grid_size[0], grid_size[1]);
		printf("dx dy           : (%.2f, %.2f) \n", dx, dy);
		printf("coord_x coord_y : (%.2f, %.2f) \n", coord_x, coord_y);
		printf("rgba            : (%.2f, %.2f, %.2f, %.2f) \n", rgb[0], rgb[1], rgb[2]);

		printf("------------------------------------------\n");
	}
};

void test() {
	int x = 5;							// for с внешней инициализацией
	for (; x > 0; x--) {
		printf("%d, ", x);
	}
	cout << "\n";

}

int main() {
	// grid_generator(50.0f, 50.0f);

	int window_size[2] = { 1440, 1024 };
	int grid_size[2] = { 800, 800 };
	float dx = 50;
	float dy = 50;
	float coord_x = 80;
	float coord_y = 80;
	float rgb[3] = {1.0f, 1.0f, 1.0f};

	Grid grid(window_size, grid_size, dx, dy, coord_x, coord_y, rgb);
	grid.print_setting();

	/*Point a(10, 10);
	a.print();

	Line l_1(1, 2, 3, 4);
	l_1.print();

	test();*/
	return 0;
};
