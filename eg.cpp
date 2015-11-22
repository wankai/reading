class Singleton
{
 public:
  static Singleton* instance()
  {
    return &obj_;
  }
  
 private:
  Singleton();
  // disable copy
  static Singleton obj_;
};
Singleton Singleton::obj_;
// initialize other static member object
