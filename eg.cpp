class Singleton
{
 public:
  static Singleton* instance() {
    if (ptr_ == NULL) {
      ptr_ = new Singleton
    }
    return ptr_;
  }
 private:
  Singleton();
  void Singleton(const Singleton&);
  
  static Singleton* ptr_;
};
