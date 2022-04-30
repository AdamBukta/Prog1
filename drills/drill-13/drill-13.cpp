/*
    g++ drill-13.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o drill-13 `fltk-config --ldflags --use-images` -std=c++11
*/
#include "Simple_window.h"
#include "Graph.h"

double one(double) { return 1; }

double square(double x) { return x*x; }

int main()
{
    const Point tl {100, 100};
    Simple_window win {tl, 800, 1000, "Canvas"};

    int x_size = 800;
    int y_size = 800;
    int x_grid = 100;
    int y_grid = 100;

    Lines grid;
    for (int x = x_grid; x < x_size; x = x+x_grid)
        grid.add(Point{x, 0}, Point{x, y_size});
    for (int y = y_grid; y < y_size; y = y+y_grid)
        grid.add(Point{0, y}, Point{x_size, y});

    grid.set_color(Color::red);

    win.attach(grid);

    Vector_ref<Rectangle> rects;
    for (int i = 0; i < x_size; i += x_grid) {
        rects.push_back(new Rectangle{Point{i,i}, Point{i+x_grid,i+x_grid}});
        rects[rects.size() - 1].set_color(Color::invisible);
        rects[rects.size() - 1].set_fill_color(Color::red);
        win.attach(rects[rects.size() - 1]);
    }


    Image kep200_1 {Point{0,300}, "kep200_1.jpg"};
    Image kep200_2 {Point{300,600}, "kep200_2.jpg"};
    Image kep200_3{Point{500,100}, "kep200_3.jpg"};


    win.attach(kep200_1);
    win.attach(kep200_2);
    win.attach(kep200_3);

    Image kep100 {Point{0,0}, "kep100.jpg"};
    win.attach(kep100);
	win.wait_for_button();
    
    for (int i = 0; i < 8; ++i) 
	{
        
        for (int j = 0; j < 7; ++j) 
		{
            kep100.move(100, 0);
            win.wait_for_button();
        }

        if(i < 7)
        {
            kep100.move(-700, 100);
        }

        win.wait_for_button();
        
    }

}
