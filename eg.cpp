class Singleton
{
 public:
  static Singleton* instance()
  {
    if (ptr_ == NULL)
    {
      MutexGuard mg(mutex_);
      if (ptr_ == NULL)
      {
        // C++ has 3 new:
        // new operator
        // operator new
        // placement new
        ptr_ =                           // step3
        operator new(sizeof(Singleton)); // step1
        new (ptr_) Sinleton;             // step2
      }
    }
    return ptr_;
  }
  
 private:
  // disable constructing and copy
  
  static Mutex mutex_;
  static Singleton* ptr_;
};
// initialize static member object
