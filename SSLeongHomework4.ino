class Triangle{
  private:
      double coordinate_x1;
      double coordinate_y1;
      double coordinate_x2;
      double coordinate_y2;
      double coordinate_x3;
      double coordinate_y3;
  public: 
      Triangle(double x1, double y1, double x2, double y2, double x3, double y3){
        coordinate_x1 = x1;
        coordinate_y1 = y1;
        coordinate_x2 = x2;
        coordinate_y2 = y2;
        coordinate_x3 = x3;
        coordinate_y3 = y3;
      }
    
      void setX1(double x1){
        coordinate_x1 = x1;
      }
      void setY1(double y1){
        coordinate_y1 = y1;
      }
      void setX2(double x2){
        coordinate_x2 = x2;
      }
      void setY2(double y2){
        coordinate_y2 = y2;
      }
      void setX3(double x3){
        coordinate_x3 = x3;
      }
      void setY3(double y3){
        coordinate_y3 = y3;
      }
      double query(){
        double area=0;
        
        double base = (sqrt(pow(coordinate_x2 - coordinate_x1, 2) + pow(coordinate_y2 - coordinate_y1, 2)))/2;
        double height = sqrt(pow(base, 2) + pow(base*2, 2));
        area = base * height;
        
        return area;
      }
};
struct triangle{
          double coordinate_x1;
          double coordinate_y1;
          double coordinate_x2;
          double coordinate_y2;
          double coordinate_x3;
          double coordinate_y3;

}; 

struct triangle temp;

void setup(){
        Serial.begin(9600);
}
void loop(){
        Serial.println(sizeof(class Triangle));
        Serial.println(sizeof(struct triangle));
        delay(5000);
}

//Both the size of the class and struct are the same. The difference between a class and struct is that the attribute in class is declared private by default whereas attributes are declared public by default.
