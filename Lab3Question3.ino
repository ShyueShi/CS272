class Point{
  
  public: 
      Point(float x, float y, float z){
        coordinate_x = x;
        coordinate_y = y;
        coordinate_z = z;
      }
      ~Point(){
        coordinate_x = 0;
        coordinate_y = 0;
        coordinate_z = 0;
      }
      float getX(){
        return coordinate_x;
      }
      float getY(){
        return coordinate_y;
      }
      float getZ(){
        return coordinate_z;
      }
      void setX(float newX){
        coordinate_x = newX;
      }
      void setY(float newY){
        coordinate_y = newY;
      }
      void setZ(float newZ){
        coordinate_z = newZ;
      }
  private:
      float coordinate_x;
      float coordinate_y;
      float coordinate_z;
      
}
