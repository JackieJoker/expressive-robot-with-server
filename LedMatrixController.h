#ifndef LedMatrixController_h
#define LedMatrixController_h

class LedMatrixController {
private:

public:
  LedMatrixController();
  
  void setup();
  void showGif(char* gif);
  bool updateGif();
};
#endif