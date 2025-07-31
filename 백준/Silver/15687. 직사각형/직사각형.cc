class Rectangle {
private:
  int width, height;
public:
  Rectangle(int w, int h): width(w), height(h) {}
  int get_width() const {return this->width;}
  int get_height() const {return this->height;}
  void set_width(int w) {
    if (w<=0 || w>1000) return;
    else this->width=w;
  };
  void set_height(int h) {
    if (h<=0 || h>2000) return;
    else this->height=h;
  };
  int area() const {return width*height;}
  int perimeter() const {return (width+height)<<1;}
  bool is_square() const {return width==height;}
};
