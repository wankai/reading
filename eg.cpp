class Singleton
{
 public:
  static Singleton* instance()
  {
    if (!local_ptr_) {
      {
        MutexGuard mg(mutex_);
        if (ptr_ == NULL) {
          ptr_ = new Singleton;
        }
      }
      local_ptr_ = ptr_;
    }
    return local_ptr_.get();
  }
  
 private:
  Singleton();
  thread_local SharedPtr<Singleton> local_ptr_;
  static Mutex mutex_;
  static Singleton* ptr_;
};
