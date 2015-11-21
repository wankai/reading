// pre C++11 implementation
class Singleton
{
 public:
  static Singleton* instance() {
    if (ptr_ == NULL) {
      ptr_ = new Singleton
    }
    return ptr_;
  }
  
  // practicle operations
  void foo();
  
 private:
  Singleton();
  void Singleton(const Singleton&);
  
  static Singleton* ptr_;
};
// usage
// Singleton::instance()->foo();
