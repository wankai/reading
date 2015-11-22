class Singleton
{
 public:
  static ShardPtr<Singleton> instance()
  {
    if (local_ptr_ == NULL) {
      {
        MutexGuard mg(mutex_);
        if (ptr_ == NULL) {
          ptr_ = new Singleton;
        }
      }
      local_ptr_ = ptr_;
    }
    return local_ptr_;
  }
  
 private:
  Singleton();
  thread_local SharedPtr<Singleton> local_ptr_;
  static Mutex mutex_;
  static SharedPtr<Singleton> ptr_;
};
