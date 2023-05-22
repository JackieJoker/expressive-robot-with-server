#ifndef Mp3Controller_h
#define Mp3Controller_h

class Mp3Controller {
  private:

  public:
  Mp3Controller();
  void setup();

  /// volume in range between 0 and 30
  /// default is 20
  void setVolume(int volume);
  void play(int trackNumber);
};

#endif