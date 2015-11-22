class Singleton
{
 public:
  static Singleton* instance()
  {
    static Singleton obj;
    return &obj;
  }
  
 private:
  Singleton();
};

