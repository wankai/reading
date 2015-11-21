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
        ptr_ = new Singleton;
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
